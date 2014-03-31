//Numerical Methods in Finance with C++
//Capinski and Zastawniak

#include "stdafx.h"
#include "Options01.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int GetInputData(int& N, double& K)
{

	cout << "Enter steps to expiry NL "; cin >> N;
	cout << "Enter strike price K:	"; cin >> K;
	if ( 0 >= K || 0 >= N) { std::cout<< "wrong data"; return EXIT_FAILURE;}
	cout << endl;
	return 0;
}



double PriceByCRR(double S0, double U, double D, 
					double R, int N, double K, bool flag)
{
	typedef std::vector<double> double_vec_t;
	
	
	double q=RiskNeutProb(U,D,R);
	
	
	
	double_vec_t Price(N+1);
	Price.reserve(10);

	
//Exercise 1.5
	//Use CRR formula instead of the iterative Procedure
	// H(0) = 1/(1+R)^n Sum_i=0^N N!/(i! (N-i)!) q^1 (1-q)^(n-i) h(S(N,i))

	//Assuming recombining tree

	if(flag)
	{
		double price = 0;
		for(int i=0; i<=N; i++)
		{
          
		  price +=   nChoosek(N,i)*pow(q,i)*pow(1-q,N-i)*CallPayoff(S(S0,U,D,N,i),K);
          
		}
		return price/(pow(1+R,N));

	}


	else
	{

	for(int i=0; i<=N; i++)
	{
		Price.at(i) = CallPayoff(S(S0,U,D,N,i),K);
	}


	for (int n=N-1; n>=0; n--)
	{
		for (int i=0; i<=n; i++)
		{
		Price.at(i) = (q*Price.at(i+1)+(1-q)*Price.at(i))/(1+R);
		}
	}

return Price.at(0);
}
}



double CallPayoff(double z, double K)
{
	if (z>K) return z-K;
	return 0.0;
}

double PutPayoff(double z, double K)
{
	if (z>K) return K-z;
	return 0.0;
}




//Ben Voigt
//http://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c
unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
