#include <iostream>
#include <math.h>
using namespace std;
#define myPi 3.14158 
#define myG 9.80665							//	m/s^2

double epsilon = 0.01;						// error limit for approximation
int L = 50;									// meters
double thetazeroOFG = 0.05;
double T_approx = 2 * myPi * sqrt(L / myG);	// approximation of period T

double myfuncOFG(double z) {				// exact period integrand
	return 1/sqrt(1-(pow(sin(thetazeroOFG/2),2)*pow(sin(z),2)));
}

void trapezoidalOFG(int L, double thetazeroOFG) {
	double result = 0;
	double low = 0;
	double high = 0.5*myPi;
	double deltax = (high - low) / 10000;
	for (; low < high; low += deltax) {
		result += (myfuncOFG(low) + myfuncOFG(low + deltax)) * deltax / 2;
	}
	result = result * 4 * sqrt(L/myG);
	cout << "Trapezoidal integral result for exact T is: " << result << endl;
}

double simpsonOFG(int L, double thetazeroOFG) {
	double result = 0;
	double low = 0;
	double high = 0.5 * myPi;
	double deltax = (high - low) / 10000;
	for (; low < high; low += deltax) {
		result += deltax/6*(myfuncOFG(low) + 
			4*myfuncOFG(low + deltax/2) + myfuncOFG(low + deltax)) ;
	}
	result = result * 4 * sqrt(L / myG);
	cout << "Simpsons integral result for exact T is: " << result << endl;
	return result;
}

int main() {
	cout << "T approx: " << T_approx << endl << endl;
	while (1) {
		cout << "Theta zero value is: " << thetazeroOFG << endl;
		trapezoidalOFG(L, thetazeroOFG);
		if (abs(T_approx - simpsonOFG(L, thetazeroOFG)) > epsilon) {
			break;
		} else {
			thetazeroOFG = thetazeroOFG + 0.05;
		}
		cout << endl;
	}
}