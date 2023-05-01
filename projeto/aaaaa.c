#include <stdio.h>
#include <gmp.h>

void euler(mpf_t result, int n) {
    //mpf_set_ui(result, 1);
    mpf_t fact, term;
    mpf_init(fact);
    mpf_init(term);

    mpf_set_ui(fact, 1);
    //mpf_set_ui(term, 0);

    for (int i = 1; i < n; i++) {
        //factorial(fact, i);
        mpf_mul_ui(fact, fact, i);
	mpf_ui_div(term, 1, fact);
        mpf_add(result, result, term);
    }

    mpf_clear(fact);
    mpf_clear(term);
}

int main() {
    mpf_set_default_prec(80000U);
    mpf_t e;
    mpf_init(e);
    mpf_set_ui(e, 1);
    euler(e, 10000);
    gmp_printf("Euler: %.9999Ff\n", e);
    mpf_clear(e);
    return 0;
}
