#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t a, b, gcd;
    
    // Initialize GMP integers
    mpz_init(a);
    mpz_init(b);
    mpz_init(gcd);
    
    // Input two large numbers 'a' and 'b'
    gmp_printf("Enter the first number 'a': ");
    gmp_scanf("%Zd", a);
    
    gmp_printf("Enter the second number 'b': ");
    gmp_scanf("%Zd", b);
    
    // Calculate GCD
    mpz_gcd(gcd, a, b);
    
    // Output the result
    gmp_printf("GCD of a and b is: %Zd\n", gcd);
    
    // Clear memory
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(gcd);
    
    return 0;
}
