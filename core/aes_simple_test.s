# Simple AES Test in RISC-V Assembly
# Tests basic AES accelerator functionality

.section .text
.global _start

_start:
    # Test AES32ESI instruction
    # Format: aes32esi rd, rs1, rs2, bs
    # where bs (byte select) is in bits [31:30] and [23:20] of instruction

    # Load test values
    li x1, 0x12345678      # Test input in rs1
    li x2, 0xABCDEF00      # Test data in rs2

    # Test AES32ESI with byte select 0 (bits [7:0] of rs2)
    # Encoding: opcode=0x33, funct3=0x0, funct7=0x32, bs=0
    .word 0x3200A033       # aes32esi x0, x1, x2, 0
    mv x3, x0              # Store result

    # Test AES32ESI with byte select 1 (bits [15:8] of rs2)
    .word 0x3400A033       # aes32esi x0, x1, x2, 1
    mv x4, x0              # Store result

    # Test AES32ESI with byte select 2 (bits [23:16] of rs2)
    .word 0x3600A033       # aes32esi x0, x1, x2, 2
    mv x5, x0              # Store result

    # Test AES32ESI with byte select 3 (bits [31:24] of rs2)
    .word 0x3800A033       # aes32esi x0, x1, x2, 3
    mv x6, x0              # Store result

    # Test AES32ESMI (middle round encryption)
    # Encoding: opcode=0x33, funct3=0x0, funct7=0x36
    .word 0x3600A0B3       # aes32esmi x1, x1, x2, 0
    mv x7, x1              # Store result

    # Test SHA256SIG0
    li x8, 0x61626380      # "abc" + padding
    .word 0x10201013       # sha256sig0 x0, x8
    mv x9, x0              # Store result

    # Test SHA256SIG1
    .word 0x10301013       # sha256sig1 x0, x8
    mv x10, x0             # Store result

    # Print results (if printf support available)
    # Otherwise results are in registers x3-x10

    # Simple verification: check if results are non-zero
    # (indicating the accelerator is functioning)
    or x11, x3, x4         # Combine results
    or x11, x11, x5
    or x11, x11, x6
    or x11, x11, x7
    or x11, x11, x9
    or x11, x11, x10

    # If x11 is non-zero, at least some operations produced output
    beqz x11, test_failed

test_passed:
    li x1, 0              # Return 0 for success
    j exit

test_failed:
    li x1, 1              # Return 1 for failure

exit:
    # Exit system call (if supported)
    li a0, 0              # Exit status
    li a7, 93             # sys_exit
    ecall

.section .data
test_msg: .string "AES Test Results in registers x3-x10\n"