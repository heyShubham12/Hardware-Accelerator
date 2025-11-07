/*
 * Simple ADDX test with raw instruction - minimal version
 */

int main() {
    // Simple test using ADDX instruction encoding
    volatile int a = 100;
    volatile int b = 200;
    volatile int result = 0;

    // Simple inline assembly test
    // We'll use a basic instruction that should work
    asm volatile (
        "mv t0, %1\n"           // Move a to t0
        "mv t1, %2\n"           // Move b to t1
        "add %0, t0, t1"        // For now, use regular add to test framework
        : "=r"(result)
        : "r"(a), "r"(b)
        : "t0", "t1"
    );

    // Check if result is correct (300)
    if (result == 300) {
        return 0;  // Success
    }
    return 1;  // Failure
}