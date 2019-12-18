#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,h,area;
	long double l,b, a1, a2;
	cin>>t;
	while(t--)
	{
		cin>>h>>area;
		if( h*h >= 4*area)
		{
			a1 = (long double)sqrt(h*h + 4*area);
			a2 = (long double)sqrt(h*h - 4*area);
			l = (long double)(a1+a2)/2.000000;
			b = (long double)(a1-a2)/2.000000;
			cout<<fixed;
			cout<<setprecision(6);
   			cout<<b<<" "<<l<<" "<<h<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
