#include <bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int findPairs(int srt, int num)
{
	int num1 = num, srt1 = srt, sum = srt1;
	int power = 0, val = srt1;	
	while(num1 > 1)
	{
		power = pow(2,val);
		num1 -= power;
		val = sqrt(num1);
		if(val == 1 && num1 == 1)
			break;
		sum += val;
	}
	//sum = 1;
	return sum;
}

int main()
{
	FAST
	int tc;
	cin>>tc;
	while(tc--)
	{
		int num, srt, sum;
		cin>>num;
		srt = sqrt(num);
		sum = findPairs(srt, num);			
		cout<<sum<<endl;
	}
	return 0;
}
