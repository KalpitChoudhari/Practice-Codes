#include <bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{
	FAST
	ll ip, k, val;
	cin>>ip>>k;
	vector <int> arr;
	for(int i=0;i<ip;i++)
	{
		cin>>val;
		arr.push_back(val);
	}
	sort(arr.begin(),arr.end());
	ll sum = 0, count = 0;
	for(int i=0;i<arr.size();i++)
	{
		count += arr[i];
		if(count > k)
			break;
		sum++;
	}
	cout<<sum;
	return 0;
}
