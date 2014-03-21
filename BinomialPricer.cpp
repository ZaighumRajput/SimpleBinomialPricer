// BinomialPricer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BinModel01.h"
#include "Options01.h"
#include <cmath>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	double S0,U,D,R;

	if (GetInputData(S0,U,D,R)==1) return 1;

	double K;
	int N;

	cout << "Enter call option data:" << endl;
	GetInputData(N,K);

	cout << "European call option price = "
		 << PriceByCRR(S0,U,D,R,N,K)
	     << endl << endl;
		 
		 return 0;

}


