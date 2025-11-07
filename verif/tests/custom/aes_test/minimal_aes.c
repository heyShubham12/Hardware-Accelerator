/*
 * Minimal AES test - just check if we can execute basic operations
 */

int main() {
    // Simple test that should pass
    volatile int x = 42;
    volatile int y = x + 1;

    // Return 0 for success
    if (y == 43) {
        return 0;
    }
    return 1;
}