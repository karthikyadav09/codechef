#include <bits/stdc++.h>
#include <limits.h>
#include <cmath>
using namespace std;
		
int main()
{
	long long int t, total,l,i;
	string str;
	cin>>t;
	while(t--)
	{
		total = 0;
		cin>>str;
		l = str.length();
		for(i=0;i<l;i++)
		{
			if(str[i] != '4' && str[i] != '7')
				total++;
		}
		cout<<total<<endl;
	}
	return 0;
}