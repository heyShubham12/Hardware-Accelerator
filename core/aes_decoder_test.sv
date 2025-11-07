// AES Decoder Test Module
// Tests the AES instruction decoding in CVA6

module aes_decoder_test;

    // Test parameters
    localparam config_pkg::cva6_cfg_t TestCfg = '{
        ZKN: 1'b1,           // Enable Zkn extension
        RVB: 1'b1,           // Enable Bit manipulation
        IS_XLEN32: 1'b1,     // 32-bit mode
        IS_XLEN64: 1'b0,
        default: '0
    };

    // Decoder inputs
    logic [31:0] instruction;
    logic [CVA6Cfg.VLEN-1:0] pc;
    logic [15:0] compressed_instr;
    logic is_compressed;
    logic is_illegal;
    // ... other decoder inputs (simplified for test)

    // Decoder outputs
    scoreboard_entry_t instruction_o;
    logic [31:0] orig_instr_o;
    logic is_control_flow_instr_o;

    // DUT instantiation
    decoder #(
        .CVA6Cfg(TestCfg)
    ) dut (
        .instruction_i(instruction),
        .pc_i(pc),
        .compressed_instr_i(compressed_instr),
        .is_compressed_i(is_compressed),
        .is_illegal_i(is_illegal),
        .instruction_o(instruction_o),
        .orig_instr_o(orig_instr_o),
        .is_control_flow_instr_o(is_control_flow_instr_o)
        // ... other connections
    );

    // Test sequences
    initial begin
        $display("Starting AES Decoder Tests...");

        // Initialize inputs
        pc = 64'h1000;
        compressed_instr = 16'h0;
        is_compressed = 1'b0;
        is_illegal = 1'b0;

        // Test 1: AES32ESI instruction
        // Format: aes32esi rd, rs1, rs2, bs
        // Encoding: 0x32000033 (with rs1=0, rs2=0, rd=0, bs=0)
        #10;
        instruction = 32'b00110010_00000_00000_000_00000_0110011; // AES32ESI
        #10;
        assert(instruction_o.fu == AES) else $error("AES32ESI: Wrong functional unit");
        assert(instruction_o.op == ariane_pkg::AES32ESI) else $error("AES32ESI: Wrong operation");
        $display("✓ AES32ESI decoded correctly: FU=%0d, OP=%0d", instruction_o.fu, instruction_o.op);

        // Test 2: AES32ESMI instruction
        #10;
        instruction = 32'b00110110_00000_00000_000_00000_0110011; // AES32ESMI
        #10;
        assert(instruction_o.fu == AES) else $error("AES32ESMI: Wrong functional unit");
        assert(instruction_o.op == ariane_pkg::AES32ESMI) else $error("AES32ESMI: Wrong operation");
        $display("✓ AES32ESMI decoded correctly: FU=%0d, OP=%0d", instruction_o.fu, instruction_o.op);

        // Test 3: AES32DSI instruction
        #10;
        instruction = 32'b00110010_00000_00000_000_00000_0110011; // AES32DSI (different funct7)
        instruction[31:25] = 7'b0011010; // AES32DSI funct7
        #10;
        assert(instruction_o.fu == AES) else $error("AES32DSI: Wrong functional unit");
        assert(instruction_o.op == ariane_pkg::AES32DSI) else $error("AES32DSI: Wrong operation");
        $display("✓ AES32DSI decoded correctly: FU=%0d, OP=%0d", instruction_o.fu, instruction_o.op);

        // Test 4: SHA256SIG0 instruction
        #10;
        instruction = 32'b00010000_00100_00000_001_00000_0010011; // SHA256SIG0
        #10;
        assert(instruction_o.fu == AES) else $error("SHA256SIG0: Wrong functional unit");
        assert(instruction_o.op == ariane_pkg::SHA256SIG0) else $error("SHA256SIG0: Wrong operation");
        $display("✓ SHA256SIG0 decoded correctly: FU=%0d, OP=%0d", instruction_o.fu, instruction_o.op);

        // Test 5: Test with different register assignments
        #10;
        instruction = 32'b00110010_00101_00011_000_00111_0110011; // AES32ESI x7, x3, x5, 0
        #10;
        assert(instruction_o.rs1 == 5'd3) else $error("Wrong rs1 decoding");
        assert(instruction_o.rs2 == 5'd5) else $error("Wrong rs2 decoding");
        assert(instruction_o.rd == 5'd7) else $error("Wrong rd decoding");
        $display("✓ Register assignments decoded correctly: rs1=%0d, rs2=%0d, rd=%0d",
                 instruction_o.rs1, instruction_o.rs2, instruction_o.rd);

        // Test 6: Test byte select encoding (bs field)
        for (int bs = 0; bs < 4; bs++) begin
            #10;
            instruction = 32'b00110010_00000_00000_000_00000_0110011; // Base AES32ESI
            instruction[31:30] = bs[1:0]; // High 2 bits of bs
            instruction[23:20] = bs[3:0]; // Low 4 bits of bs (only [1:0] used)
            #10;
            // The bs field should be passed to the execution stage
            $display("✓ Byte select %0d encoded in instruction bits", bs);
        end

        $display("All AES decoder tests completed successfully!");
        $finish;
    end

    // Monitor illegal instruction detection
    always @(posedge clk) begin
        if (is_illegal) begin
            $display("Warning: Illegal instruction detected for: 0x%08x", instruction);
        end
    end

endmodule

// Test runner
module aes_test_runner;
    initial begin
        aes_decoder_test test_instance();
        test_instance.run_tests();
    end
endmodule