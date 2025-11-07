# ADDX Standalone Test Program
# Simple assembly program to test ADDX instruction
# Uses direct system calls for minimal dependencies

.section .text
.globl _start

_start:
    # Initialize stack pointer (required for proper execution)
    li sp, 0x80010000

    # Print header message
    li a0, 1                    # stdout
    la a1, msg_header           # message address
    li a2, 50                   # message length
    li a7, 64                   # sys_write
    ecall

    #========================================
    # Test 1: Simple addition (25 + 37 = 62)
    #========================================
    la a1, msg_test1
    li a2, 30
    li a7, 64
    ecall

    li a0, 25                   # First operand = 25
    li a1, 37                   # Second operand = 37
    .word 0x00B50533            # ADDX a0, a0, a1
    # Result in a0 = 62

    #========================================
    # Test 2: Larger numbers (1000 + 2000 = 3000)
    #========================================
    la a1, msg_test2
    li a2, 35
    ecall

    li a2, 1000                 # First operand = 1000
    li a3, 2000                 # Second operand = 2000
    .word 0x00D60633            # ADDX a2, a2, a3
    # Result in a2 = 3000

    #========================================
    # Test 3: Hex values (0x1234 + 0x5678)
    #========================================
    la a1, msg_test3
    li a2, 40
    ecall

    li a4, 0x1234               # First operand = 0x1234
    li a5, 0x5678               # Second operand = 0x5678
    .word 0x00F70733            # ADDX a4, a4, a5
    # Result in a4 = 0x68AC

    #========================================
    # Test 4: Negative numbers (-100 + -200)
    #========================================
    la a1, msg_test4
    li a2, 40
    ecall

    li t0, -100                 # First operand = -100
    li t1, -200                 # Second operand = -200
    .word 0x006282B3            # ADDX t0, t0, t1
    # Result in t0 = -300

    #========================================
    # Test 5: Very large numbers (overflow test)
    #========================================
    la a1, msg_test5
    li a2, 45
    ecall

    li t2, 0x7FFFFFFFFFFFFFFF   # Max positive value
    li t3, 1                    # Add 1
    .word 0x01CE0E33            # ADDX t3, t2, t3
    # Should saturate or overflow

    # Print completion message
    li a0, 1
    la a1, msg_complete
    li a2, 40
    li a7, 64
    ecall

    # Exit program with status 0
    li a0, 0                    # Exit code 0
    li a7, 93                   # sys_exit
    ecall

.section .rodata
msg_header:
    .ascii "========================================\n"
    .ascii "  ADDX Instruction Test Program\n"
    .ascii "========================================\n\n"

msg_test1:
    .ascii "Test 1: 25 + 37 = 62\n"

msg_test2:
    .ascii "Test 2: 1000 + 2000 = 3000\n"

msg_test3:
    .ascii "Test 3: 0x1234 + 0x5678 = 0x68AC\n"

msg_test4:
    .ascii "Test 4: -100 + (-200) = -300\n"

msg_test5:
    .ascii "Test 5: Overflow test (MAX + 1)\n"

msg_complete:
    .ascii "\n========================================\n"
    .ascii "  All ADDX tests completed!\n"
    .ascii "========================================\n"

.section .data
# No data section needed

# End of program
