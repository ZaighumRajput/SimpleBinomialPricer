//Numerical Methods in Finance with C++
//Capinski and Zastawniak

#ifndef Options01_h
#define Options01_h

//inputting and displaying option data
int GetInputData(int& N, double& K);

double PriceByCRR(double S0, double U, double D,
				  double R, int N, double K, double (*Payoff) (double z, double K));

//computing call payoff
double CallPayoff(double z, double K);

double PutPayoff(double z, double K);

unsigned nChoosek( unsigned n, unsigned k );

#endif


