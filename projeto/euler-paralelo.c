#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void euler(int n, mpf_t *e){

	int i, local_n;
  	int my_rank = omp_get_thread_num();
  	int thread_count = omp_get_num_threads();
	long double mult = 1;

  	mpf_t result, e_local;
  	mpf_init2(result, 335000U);
  	mpf_init2(e_local, 335000U);

  	mpf_set_ui(result, 1);
	local_n = n/thread_count;

	for(i = 1; i <= local_n; i++){
		if(i > local_n*my_rank){
			mpf_div_ui(result, result, i);
			mpf_add(e_local, e_local, result);
		} else {
			mpf_div_ui(result, result, i);
		}
	}

#pragma omp critical
  	mpf_add(*e, *e, e_local);
  	mpf_clear(e_local);
  	mpf_clear(result);
}


int main(int argc , char* argv[]) {

	if (argc < 2){
		printf("Informe o numero de threads.");
		return 1;
	}
	int thread_count = strtol(argv[1], NULL, 10);
  	int n = 130000; //33220 mto rapido pra 10k digitos
  	mpf_t e;
  	mpf_init2(e, 335000U);
	mpf_set_ui(e, 1);

#pragma omp parallel num_threads(thread_count)
	euler(n, &e);
  	gmp_printf("%.99999Ff\n", e);
  	mpf_clear(e);

  	return 0;
}
