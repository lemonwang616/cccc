#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int min(int a,int b)
{
	return (a<b?a:b);
}
int max(int a,int b)
{
	return (a>b?a:b);
}

    int maxProfit(vector<int> prices) { 
    	//计算相邻两个差值和  
		int n=prices.size();
		if(n==0)
		{
			return 0;
		}
		vector<int> left(n,0);//left[0]为0 
		vector<int> reft(n,0);//right[n-1]为0 
		int i;
		int profit=0;
		int buyin=prices[0];
		for(i=1;i<n;i++)
		{
			if(prices[i]-buyin>profit)
			{
				profit=prices[i]-buyin;
			}
			if(buyin>prices[i])
			{
				buyin=prices[i];
			}
			left[i]=profit;//从 0到i的最大值 
		}
		profit=0;
		int buyout=prices[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(buyout-prices[i]>profit)
			{
				profit=buyout-prices[i];
			}
			if(prices[i]>buyout)
			{
				buyout=prices[i];
			}
			reft[i]=profit;//求price[n-1]到prices[i]的最大值 
		}
		profit=0;
		for(i=0;i<n;i++)
		{
			if(left[i]+reft[i]>profit)
			{
				profit=left[i]+reft[i];
			}
		}
		return profit;
    }

int main(int argc, char** argv) {
	vector<int> prices;
	int n;
	cin>>n;
	int i,temp;
	for(i=0;i<n;i++)
	{
	cin>>temp;
	prices.push_back(temp);
	}
	
	cout<<maxProfit(prices)<<endl;
	return 0;
	
}
