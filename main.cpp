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

bool isMatch(string s,string p)
{
	int slen=s.length(); //注意里面p、s在string中的数组要-1 
	int plen=p.length();  //
	int i=0;
	int j;
	int count=0;
	while(i<plen)
	{
		if(p[i]=='*')
		{
			count++;
		}
		i++;
	}
	if(slen<(plen-count))
	{
		return false;
	}
	vector<bool> pre(plen+1,false);//pre与cur中下标是从1开始，指的是s或p的下标 
	pre[0]=true;
	for(j=1;j<=plen;j++)
	{
		pre[j]=pre[j-1]&&(p[j-1]=='*');
	}
	for(i=1;i<=slen;i++)
	{
		vector<bool> cur(plen+1,false);
		for(int j=1;j<=plen;j++)
		{
			if(p[j-1]=='*')
			{
				cur[j]=cur[j-1]||pre[j];
			}
			else
			{
				cur[j]=pre[j-1]&&(s[i-1]==p[j-1]||p[j-1]=='?');
			}
		}
		pre=cur;
	}
	return pre[plen];
}

int main(int argc, char** argv) {
string s;
string p;
cin>>s;
cin>>p;
cout<<isMatch(s,p);	
	return 0;
}
