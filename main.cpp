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
    	
        int length=prices.size();
        //cout<<length;
        int buyin=prices[0];//买入点越低越好 
		int profit=0; 
        for(int i=1;i<length;i++)
        {
        	profit=max(profit,prices[i]-buyin);
        	buyin=min(buyin,prices[i]);
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
