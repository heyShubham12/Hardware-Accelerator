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
    // ADDX: Saturating addition with signed overflow detection
    // Matches Spike ISS implementation
    extended_result = fu_data_i.operand_a + fu_data_i.operand_b;

    if (CVA6Cfg.IS_XLEN32) begin
      // For 32-bit: Check for signed overflow
      // Both positive and result is negative -> positive overflow
      if (~fu_data_i.operand_a[31] && ~fu_data_i.operand_b[31] && extended_result[31]) begin
        addx_result = 32'h7FFFFFFF;  // Saturate to max positive
      end
      // Both negative and result is positive -> negative overflow
      else if (fu_data_i.operand_a[31] && fu_data_i.operand_b[31] && ~extended_result[31]) begin
        addx_result = 32'h80000000;  // Saturate to min negative
      end
      else begin
        // No overflow - use normal result
        addx_result = extended_result[31:0];
      end
    end else begin // 64-bit
      // For 64-bit: Check for signed overflow
      // Both positive and result is negative -> positive overflow
      if (~fu_data_i.operand_a[63] && ~fu_data_i.operand_b[63] && extended_result[63]) begin
        addx_result = 64'h7FFFFFFFFFFFFFFF;  // Saturate to max positive
      end
      // Both negative and result is positive -> negative overflow
      else if (fu_data_i.operand_a[63] && fu_data_i.operand_b[63] && ~extended_result[63]) begin
        addx_result = 64'h8000000000000000;  // Saturate to min negative
      end
      else begin
        // No overflow - use normal result
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
    if (rst_ni) begin
      // Debug output removed to avoid accessing non-existent fu_data_i.valid field
      // Original debug code accessed fu_data_i.valid which doesn't exist in fu_data_t
      // The accelerator performs saturating addition with overflow detection
    end
  end
  // synthesis translate_on

endmodule




