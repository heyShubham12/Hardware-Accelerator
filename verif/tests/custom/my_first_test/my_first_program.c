/*
 * My First CVA6 RISC-V Program
 * This is a simple example showing how to run custom programs on CVA6
 */

#include <stdint.h>
#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Function to check if number is prime
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    printf("========================================\n");
    printf("  Welcome to My First CVA6 Program!    \n");
    printf("  Hello Shubham    \n");
    printf("========================================\n\n");

    // Test 1: Basic arithmetic
    int a = 25;
    int b = 17;
    printf("Test 1: Basic Arithmetic\n");
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);
    printf("  %d / %d = %d\n", a, b, a / b);
    printf("\n");

    // Test 2: Loops and arrays
    printf("Test 2: Array Sum\n");
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
        printf("  numbers[%d] = %d, running sum = %d\n", i, numbers[i], sum);
    }
    printf("  Total sum = %d\n\n", sum);

    // Test 3: Factorial calculation
    printf("Test 3: Factorial\n");
    for (int i = 1; i <= 7; i++) {
        printf("  %d! = %d\n", i, factorial(i));
    }
    printf("\n");

    // Test 4: Prime number check
    printf("Test 4: Prime Numbers from 1 to 20\n");
    printf("  Primes: ");
    for (int i = 1; i <= 20; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    // Test 5: Bitwise operations
    printf("Test 5: Bitwise Operations\n");
    uint32_t x = 0x12345678;
    uint32_t y = 0x87654321;
    printf("  x = 0x%08x\n", x);
    printf("  y = 0x%08x\n", y);
    printf("  x & y = 0x%08x\n", x & y);
    printf("  x | y = 0x%08x\n", x | y);
    printf("  x ^ y = 0x%08x\n", x ^ y);
    printf("  ~x = 0x%08x\n", ~x);
    printf("\n");

    // Final result
    printf("========================================\n");
    printf("  All tests completed successfully!    \n");
    printf("========================================\n");

    return 0;  // Success!
}
