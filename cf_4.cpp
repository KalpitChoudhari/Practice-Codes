#include <bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{
	FAST
	vector <string> str1, str2;
	string s1;
	for(int i=0;i<6;i++)
	{
		cin>>s1;
		str1.push_back(s1);
	}
	int sz = str1.size();
	for(int i=sz-1;i>=0;i--)
	{
		string nw, nw1, nw2, fin;
		stringstream ss;
		nw = str1[i][0];
		nw1 = str1[i][1];
		nw2 = str1[i][2];
		ss << nw2<<nw1<<nw;
		ss >> fin;
		//fin = nw+nw1+nw2;
		str2.push_back(fin);
	}
	for(int i=0;i<6;i++)
	{
		cout<<str2[i]<<endl;
	}
	return 0;
}
