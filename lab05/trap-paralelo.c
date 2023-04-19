void Trap(double a, double b, int n, double* global_result_p)
{
	double h, x, my_result;
	double local_a, local_b;
	int i, local_n;
	int my_rank = omp_get_thread_num();
	int thread_count = opm_get_num_threads();

	h = (b-a)/n;
	local_n = n/thread_count;
	local_a = a + my_rank*local_n*h;
	local_b = local_a + local_n*h;
	my_result = (f(local_a) + f(local_b))/2.0;
	for(i = 1; i <= local_n=1; i++){
		x = local_a + i*h;
		my_result += f(x);
	}
	my_result = my_result*h;
#	pragma omp critical
	*global_result_p += my_result;
}
