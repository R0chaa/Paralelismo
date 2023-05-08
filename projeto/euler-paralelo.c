#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void euler(int n, mpf_t *e){
  	int my_rank = omp_get_thread_num();
  	int thread_count = omp_get_num_threads();
	long double mult = 1;

  	mpf_t fact, term, result, e_sum;
  	mpf_init2(fact, 33500U);
  	mpf_init2(term, 33500U);
  	mpf_init2(result, 33500U);
  	mpf_init2(e_sum, 33500U);

  	mpf_set_ui(fact, 1);
  	mpf_set_ui(term, 1);
  	mpf_set_ui(result, 1);

  	for (int i = my_rank + 1; i <= n; i += thread_count) {
    		mult = 1;
    		for (int j = 0; (j < thread_count) && ((i - j) > 1); j++) {
      			mult *= i - j;
    		}

		mpf_mul_ui(fact, fact, mult);
    		mpf_div(result, term, fact);
    		mpf_add(e_sum, e_sum, result);
 	}

#pragma omp critical
  	mpf_add(*e, *e, e_sum);

  	mpf_clear(e_sum);
  	mpf_clear(fact);
  	mpf_clear(term);
  	mpf_clear(result);
}


int main(int argc , char* argv[]) {
	if (argc < 2) {;
    		return 1;
  	}

  	int thread_count = strtol(argv[1], NULL, 10);
  	int n = 3250;
  	mpf_t e, um;
  	mpf_init2(e, 33500U);
  	mpf_init(um);

#pragma omp parallel num_threads(thread_count)

	euler(n, &e);
  	mpf_set_ui(um, 1);
  	mpf_add(e, e, um);

  	gmp_printf("%.9999Ff\n", e);

  	mpf_clear(e);
  	mpf_clear(um);

  	return 0;
}
