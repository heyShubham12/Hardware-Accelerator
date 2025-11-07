// Author: [Shubham Mishra]
// Date: [12-10-2025]
// Description: ADDX instruction hardware accelerator
// Implements the custom ADDX instruction functionality

module addx_accel
  import ariane_pkg::*;
#(
    parameter config_pkg::cva6_cfg_t CVA6Cfg = config_pkg::cva6_cfg_empty,
    parameter type fu_data_t = logic
) (
    // Subsystem Clock - SUBSYSTEM
    input  logic                        clk_i,
    // Asynchronous reset active low - SUBSYSTEM
    input  logic                        rst_ni,
    // FU data needed to execute instruction - ISSUE_STAGE
    input  fu_data_t                    fu_data_i,
    // Original instruction bits for addx (if needed for specific encoding details)
    input  logic     [             5:0] orig_instr_addx,
    // ADDX result - ISSUE_STAGE
    output logic     [CVA6Cfg.XLEN-1:0] result_o
);

  // Internal signals for ADDX operation
  logic [CVA6Cfg.XLEN-1:0] addx_result;
  logic [CVA6Cfg.XLEN:0]   extended_result;  // Extra bit for overflow/carry detection

  // ADDX Implementation
  // Assuming ADDX is an extended addition operation
  // This can be customized based on your specific requirements

  always_comb begin
    // Default: Enhanced addition with overflow detection
    extended_result = fu_data_i.operand_a + fu_data_i.operand_b;

    // Basic ADDX: addition with overflow saturation
    if (CVA6Cfg.IS_XLEN32) begin
      // For 32-bit: Check for overflow
      if (extended_result[32]) begin
        // Overflow occurred - saturate based on operand signs
        if (fu_data_i.operand_a[31] == fu_data_i.operand_b[31]) begin
          // Same signs - saturate to max/min
          addx_result = fu_data_i.operand_a[31] ? 32'h80000000 : 32'h7FFFFFFF;
        end else begin
          // Different signs - no overflow possible, just use result
          addx_result = extended_result[31:0];
        end
      end else begin
        addx_result = extended_result[31:0];
      end
    end else begin // 64-bit
      // For 64-bit operations
      if (extended_result[64]) begin
        // Overflow occurred - saturate based on operand signs
        if (fu_data_i.operand_a[63] == fu_data_i.operand_b[63]) begin
          // Same signs - saturate to max/min
          addx_result = fu_data_i.operand_a[63] ? 64'h8000000000000000 : 64'h7FFFFFFFFFFFFFFF;
        end else begin
          // Different signs - no overflow possible, just use result
          addx_result = extended_result[63:0];
        end
      end else begin
        addx_result = extended_result[63:0];
      end
    end
  end

  // -----------
  // Result Output
  // -----------
  assign result_o = addx_result;

  // -----------
  // Simulation Display (synthesis off)
  // -----------
  // synthesis translate_off
  logic [63:0] cycle_counter;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      cycle_counter <= 64'h0;
    end else begin
      cycle_counter <= cycle_counter + 1;
    end
  end

  always_ff @(posedge clk_i) begin
    if (rst_ni && fu_data_i.valid) begin
      $display("================================================================================");
      $display("[ADDX ACCELERATOR] Execution at time %0t (Cycle: %0d)", $time, cycle_counter);
      $display("--------------------------------------------------------------------------------");
      $display("  Operand A:  0x%0h (%0d)", fu_data_i.operand_a, $signed(fu_data_i.operand_a));
      $display("  Operand B:  0x%0h (%0d)", fu_data_i.operand_b, $signed(fu_data_i.operand_b));
      $display("  Result:     0x%0h (%0d)", addx_result, $signed(addx_result));

      if (CVA6Cfg.IS_XLEN32) begin
        if (extended_result[32]) begin
          if (fu_data_i.operand_a[31] == fu_data_i.operand_b[31]) begin
            $display("  Status:     OVERFLOW DETECTED - Result SATURATED to %s",
                     fu_data_i.operand_a[31] ? "MIN (0x80000000)" : "MAX (0x7FFFFFFF)");
          end else begin
            $display("  Status:     Overflow bit set but operands have different signs (Normal)");
          end
        end else begin
          $display("  Status:     Normal addition (No overflow)");
        end
      end else begin
        if (extended_result[64]) begin
          if (fu_data_i.operand_a[63] == fu_data_i.operand_b[63]) begin
            $display("  Status:     OVERFLOW DETECTED - Result SATURATED to %s",
                     fu_data_i.operand_a[63] ? "MIN (0x8000000000000000)" : "MAX (0x7FFFFFFFFFFFFFFF)");
          end else begin
            $display("  Status:     Overflow bit set but operands have different signs (Normal)");
          end
        end else begin
          $display("  Status:     Normal addition (No overflow)");
        end
      end

      $display("  Mode:       %s-bit", CVA6Cfg.IS_XLEN32 ? "32" : "64");
      $display("================================================================================");
    end
  end
  // synthesis translate_on

endmodule




