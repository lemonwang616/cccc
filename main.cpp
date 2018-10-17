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
    vector<int> holdstack;
    vector<int> emptystack;
    int days=prices.size();
    if(days<2)
    	return 0;
    int i,j;
    holdstack.assign(days+1,0);
    emptystack.assign(days+1,0);
    holdstack[0]=-prices[0];
   for(i=1;i<days;i++)
    {
    	if(i==1)
    	{
    		holdstack[i]=max(-prices[0],-prices[i]);//持有  买之前要冷静一天 
		}
		else
		{
			holdstack[i]=max(holdstack[i-1],emptystack[i-2]-prices[i]);
		} 
	
    	emptystack[i]=max(emptystack[i-1],holdstack[i-1]+prices[i]);
    	//cout<<"holdstack"<<i<<": "<<holdstack[i]<<endl;
    	//cout<<"emptystack"<<i<<": "<<emptystack[i]<<endl;
	}

	 return emptystack[days-1];
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
	cout<<maxProfit(prices)<<endl;
	return 0;
	
}
