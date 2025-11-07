# ADDX Simple Test Program
# This program demonstrates the ADDX custom instruction
# ADDX performs saturating addition: result = saturate(rs1 + rs2)

.section .text
.globl _start

_start:
    # Test 1: Add two positive numbers (25 + 37 = 62)
    li      a0, 25              # Load first number (25) into a0
    li      a1, 37              # Load second number (37) into a1
    .word   0x00B50533          # ADDX a0, a0, a1 (a0 = a0 + a1)
    # Result in a0 should be 62

    # Test 2: Add two larger numbers
    li      a2, 1000            # Load 1000 into a2
    li      a3, 2000            # Load 2000 into a3
    .word   0x00D60633          # ADDX a2, a2, a3 (a2 = a2 + a3)
    # Result in a2 should be 3000

    # Test 3: Test with hex values (like 0x1234 + 0x5678)
    li      a4, 0x1234          # Load 0x1234 into a4
    li      a5, 0x5678          # Load 0x5678 into a5
    .word   0x00F70733          # ADDX a4, a4, a5 (a4 = a4 + a5)
    # Result in a4 should be 0x68AC

    # Test 4: Test overflow - add max positive + 1
    li      t0, 0x7FFFFFFF      # Load max positive 32-bit value
    li      t1, 1               # Load 1
    .word   0x006282B3          # ADDX t0, t0, t1 (should saturate)
    # Result should saturate to max

    # Test 5: Add negative numbers
    li      t2, -100            # Load -100 into t2
    li      t3, -200            # Load -200 into t3
    .word   0x01CE0E33          # ADDX t3, t3, t2 (t3 = t3 + t2)
    # Result should be -300

    # Exit program
    li      a7, 93              # Exit syscall number
    li      a0, 0               # Exit code 0
    ecall                       # Make system call

.section .data
    # No data section needed for this simple test

# End of program
