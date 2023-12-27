#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main() {
    mpz_t prime;
    mpz_init(prime);
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, (unsigned long)time(NULL));

    int bits = 1024;
    int iterations = 0;

    while (1) {
        mpz_urandomb(prime, state, bits); 
        mpz_setbit(prime, 0);

        if (mpz_cmp_ui(prime, 2) <= 0) {
            continue; 
        }
        int is_prime = 1;
        for (int i = 0; i < 50; i++) {
            if (!mpz_probab_prime_p(prime, 10)) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            break;
        }

        iterations++;
    }

    gmp_printf("1024-bit prime: %Zd\n", prime);
    printf("Iterations to find a prime: %d\n", iterations);

    mpz_clear(prime);
    gmp_randclear(state);

    return 0;
}