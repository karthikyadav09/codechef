#include <bits/stdc++.h>
#include <limits.h>
#include <cmath>
using namespace std;

int main()
{
	long long int t, total,l,i,c;
	string str;
	cin>>t;
	while(t--)
	{
		total = 0;
		c = 0;
		cin>>str;
		l = str.length();
		for(i=0;i<l;i++)
		{
			if(str[i] == '<')
				c++;
			else
				c--;

			if(c==0)
			{
				total = max(total,i+1);
			}
			else if(c < 0)
				break;
		}
		cout<<total<<endl;
	}
	return 0;
}
