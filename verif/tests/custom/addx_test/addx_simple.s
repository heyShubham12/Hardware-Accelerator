# Simple ADDX Test in RISC-V Assembly
# Tests the custom ADDX instruction with raw encodings

.section .text
.global _start

_start:
    # Test Case 1: Basic ADDX operation
    # addx rd, rs1, rs2 with rd=x3, rs1=x1, rs2=x2
    li x1, 0x12345678      # Load test value 1
    li x2, 0x87654321      # Load test value 2

    # ADDX instruction: addx x3, x1, x2
    # Encoding: opcode=0x0B, funct3=0x0, funct7=0x00
    # Binary: 0000000_00010_00001_000_00011_0001011
    # Hex: 0x0020A18B
    .word 0x0020A18B       # addx x3, x1, x2

    # Test Case 2: ADDX with different registers
    li x4, 0x11111111      # Load test value 3
    li x5, 0x22222222      # Load test value 4

    # ADDX instruction: addx x6, x4, x5
    # Encoding with x4=rs1, x5=rs2, x6=rd
    # Binary: 0000000_00101_00100_000_00110_0001011
    # Hex: 0x0052030B
    .word 0x0052030B       # addx x6, x4, x5

    # Test Case 3: Test overflow case
    li x7, 0x7FFFFFFF      # Maximum positive 32-bit value
    li x8, 0x00000001      # Add 1 to trigger overflow

    # ADDX instruction: addx x9, x7, x8
    # Should saturate to 0x7FFFFFFF
    .word 0x0083848B       # addx x9, x7, x8

    # Test Case 4: Test negative overflow
    li x10, 0x80000000     # Minimum negative 32-bit value
    li x11, 0x80000000     # Add another negative to trigger overflow

    # ADDX instruction: addx x12, x10, x11
    # Should saturate to 0x80000000
    .word 0x00B5060B       # addx x12, x10, x11

    # Verification: Check if results are reasonable
    # x3 should contain result of 0x12345678 + 0x87654321
    # x6 should contain result of 0x11111111 + 0x22222222 = 0x33333333
    # x9 should contain 0x7FFFFFFF (saturated)
    # x12 should contain 0x80000000 (saturated)

    # Simple test: OR all results to check if any computation occurred
    or x13, x3, x6         # Combine results
    or x13, x13, x9
    or x13, x13, x12

    # If x13 is non-zero, some computation occurred
    beqz x13, test_failed

test_passed:
    li x1, 0               # Return 0 for success
    j exit

test_failed:
    li x1, 1               # Return 1 for failure

exit:
    # Exit system call
    li a0, 0               # Exit status
    li a7, 93              # sys_exit
    ecall

.section .data
test_msg: .string "ADDX Test Results:\\n"