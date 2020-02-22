#include <bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()	//3517	1357
{
	FAST
	int tc;
	cin>>tc;
	while(tc--)
	{
		string str;
		bool flg = false;
		cin>>str;
		sort(str.begin(), str.end());
		for(int i=0;i<str.length()-1;i++)
		{
			if(abs(str[i] - str[i+1]) > 2){
				flg = true;		
				break;
			}	
		}
		if(flg)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
