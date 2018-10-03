#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		int a[n+1];
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
		} 
		int globInv = 0, locInv = 0;
		for(int i = 0; i < n-1; ++i) {
			if(a[i] > a[i+1])	++locInv;
			for(int j = i+1; j < n; ++j) {
				if(a[i] > a[j])	++globInv;
			}
		}
		cout<<((locInv == globInv) ? "YES" : "NO")<<endl;
	}

	return 0;
}
