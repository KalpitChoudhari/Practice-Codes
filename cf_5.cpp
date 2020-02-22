#include <bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
} 

int main()
{
	FAST
	ll test;
	cin>>test;
	while(test--)
	{
		ll l ,b, gc_d;
		cin >> l >> b;
		gc_d = gcd(l,b);
		ll mul = lcm*lcm;
		cout<< ((l*b) / mul)<<endl;
	}
	return 0;
}
