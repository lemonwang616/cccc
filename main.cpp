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

    int maxProfit(int k,vector<int> prices) { 
		int profit=0;
		int size=prices.size();
		if(size<2)
		{
			return 0;
		}
		int i,j;
		//当买卖次数>股票数时  特殊讨论 
		if(k>=size)
		{
			int profit=0;
			for(i=1;i<size;i++)
			{
				if(prices[i]>prices[i-1])
				{
					profit=profit+prices[i]-prices[i-1];
				}
			}
			return profit;
		}
		vector<int> global[2];
		vector<int> local[2];
		for(i=0;i<2;i++)
		{
			local[i].assign(k+1,0);
			global[i].assign(k+1,0);
		}

		int flag=0;

		for(i=1;i<size;i++)
		{
			
				flag=(flag+1)%2;
			for(j=1;j<=k;j++)
			{
				int diff=prices[i]-prices[i-1];
			
				local[flag][j]=max(global[1-flag][j-1]+max(diff,0),local[1-flag][j]+diff);
				global[flag][j]=max(local[flag][j],global[1-flag][j]);	
			//	cout<<"localarr"<<i<<j<<": "<<local[flag][j]<<endl;
			//	cout<<"globalar: "<<i<<j<<": "<<global[flag][j]<<endl;
			}
		}
		

		
		return global[flag][k];
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
	int k;
	cin>>k;
	cout<<maxProfit(k,prices)<<endl;
	return 0;
	
}
