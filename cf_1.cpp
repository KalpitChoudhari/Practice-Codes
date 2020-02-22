#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ll long long
#define beg1 ((l-1)+MOD)%MOD
#define end1 ((r-1)+MOD)%MOD
//#define type1(i,beg1,end1) for(int i=beg1;i<=end1;i++)
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define mii         map<ll,ll>
#define msi         map<string,ll>
#define mis         map<ll, string>
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)
#define trav(a, x) 	for(auto& a : x)
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pair<ll, ll>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define max(a,b)	(a>b?a:b)
#define min(a,b)	(a<b?a:b)
 
/*	For Debugging	*/
#define DEBUG 		cerr<<"\n>>>I'm Here<<<\n"<<endl;
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl;
#define what_is(x)  cerr << #x << " is " << x << endl;
 
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define TIME        cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define DECIMAL(n)  cout << fixed ; cout << setprecision(n);
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FAST
	long long n, len, queries, type, l, r, p, q;
	int i;
	char ch;
	string s;
	
	cin>>n;
	while(n--)
		{
		cin>>len;
		cin>>s;
		cin>>queries;
		while(queries--)
		{
			cin>>type;
			if(type == 1)
			{
				cin>>l>>r>>ch;
				for(int i=beg1;i<=end1;i++)
					s[i] = ch;
			}
			else
			{
				cin>>l>>r>>p>>q;
				long long temp1, temp2;
				for(int i=beg1;i<=end1;i++)
				{
					if(s[i] == 'A')
					{
						temp1 = p;
						temp2 = q;
						p = (temp1 - temp2 + MOD) % MOD;
						q = (temp1 + temp2) % MOD;
					}
					else
					{
						temp1 = p;
						temp2 = q;
						p = (temp1 + temp2) % MOD;
						q = (temp2 - temp1 + MOD) % MOD;
					}
					if(i == ((r-1)+MOD)%MOD)
						cout<<(p+MOD)%MOD<<" "<<(q+MOD)%MOD<<endl;
				}
			}
		}
	}
	TIME
	return 0;
}
