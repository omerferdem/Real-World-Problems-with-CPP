#include <iostream>
using namespace std;

double lambdaOFG = 0.000121;	//half life in 1/year
double epsilon = 0.000006;		//acceptance limit for halved nuclei number
int h = 1;						//year spacing

void calculate_half_life(int N_0);

int main() {
		/* From 0 years to 10 years by 1 year steps.
		t goes from 0..10
		N_0 means initial nuclei number
		N(t) goes from 10..?
		N_t+1 = N_k + f(t_k , N_k)
		dN/dt = -lambda*f(t,N)
		*/
	calculate_half_life(10);
	calculate_half_life(100);
	calculate_half_life(1000);
	calculate_half_life(10000);
}

void calculate_half_life(int N_0) {
	double N_t = N_0;
	int step_counter = 0;
	for (int t = 0; (N_t - N_0 / 2) >= epsilon; t++) {
		N_t = N_t - h * lambdaOFG * (N_t);
		step_counter++;
	}
	cout << "Number of nuclei halved in " << step_counter << 
		" years for " << N_0 << " initial nuclei." << endl;
}