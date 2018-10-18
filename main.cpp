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

    int numDistinct(string s,string t) { 
    //special case  s or t is null
	if(s.empty()||t.empty())
	{
		return 0;	
	} 
	int slen=s.length();
	int tlen=t.length();
	if(slen<tlen)
	{
		return 0;
	}
	vector <vector<int> > dp(slen+1,vector<int>(tlen+1,0));
//	int dp[slen+1][tlen+1];
	int i,j;
	for(i=0;i<=slen;i++)
	{
		dp[i][0]=1;//表示当t中取空字符串时，每次s都只有一种方法 
	}
	for(i=1;i<=slen;i++)
	{
		for(j=1;j<=tlen;j++)
		{
			dp[i][j]=dp[i-1][j]+(s[i-1]==t[j-1]?dp[i-1][j-1]:0);
		}
	
	}
	return dp[slen][tlen];
  }

int main(int argc, char** argv) {
	string s;
	string t;
	cin>>s;
	cin>>t;
	cout<<numDistinct(s,t);
	return 0;
	
}
