#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdint.h>
#include <vector>
#include <algorithm>
int can_cut(uint64_t m);
using namespace std;
uint64_t i,j,n,h,l,k1,k2,high;
vector<uint64_t> height, rate;
uint64_t sum = 0, count = 0, c = 0, t_L = -1, t_R = 1, t_M;
int main()
{
	cin>>n;
	cin>>h;
	cin>>l;
	for(i=0;i<n;i++)
	{
		cin>>k1;
		height.push_back(k1);
		cin>>k2;
		rate.push_back(k2);
	}
	while (can_cut(t_R) == 0)
    	t_R *= 2;
	while ((t_R - t_L) > 1)
	{
    	t_M = (t_L + t_R)/2;
    	if(can_cut(t_M) == 1)
       	 	t_R = t_M;
    	else
        	t_L = t_M;
    }
	cout<<t_R<<endl;
	return 0;
} 
int can_cut(uint64_t m)
{
	sum = 0;
	for(i=0;i<n;i++)
	{
		high = height[i] + rate[i]*m;
		if(high >= l)
		{
			sum = sum + high;
			if(sum >= h)
			{
				return 1;
			}
		}
	}
	return 0;
}