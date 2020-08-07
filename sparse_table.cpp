//Range Min Queries - Demo to Sparse Table - ONLY WORK ON IMMUTABLE ARRAYS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[10] = {5 ,1, 4, 9, 2, 3, 6, 23, 45, 7};
	int l, r, n = sizeof(arr) / sizeof(arr[0]); 
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<"\nEnter left and right index (0-Base Indexing): ";
	cin>>l>>r;
	int k = log2(n);
	long long st[n][k];
	for(int i = 0; i < n; i++) {
		st[i][0] = arr[i];
	}
	//BUILD - O(log n)
	//j = 1 to 2^j <= n
	for(int j = 1; (1 << j) <= n; j++) {
		// i = 0 to (i + (2^j - 1)) <= n
		for(int i = 0; (i + (1 << j) - 1) <= n; i++) {
			st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
		}
	}
	//QUERY - O(1)
	int j = log2(r - l + 1);
	int minn = min(st[l][j], st[r - (1 << j) + 1][j]);
	
	cout<<minn<<endl;
}
