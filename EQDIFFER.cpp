#include <bits/stdc++.h>
using namespace std;

/*
2 5 1 2 2 2

 0  3  1  0  0  0
 3  0  1  0  0  0
 1  4  0  1  1  1 
 0  3  1  0  0  0
 0  3  1  0  0  0
 0  3  1  0  0  0
 
 1 2 2 2 2 5
 
 0 1 1 1 1 4 
 1 0 0 0 0 3 
 1 0 0 0 0 3 
 1 0 0 0 0 3 
 1 0 0 0 0 3 
 4 3 3 3 3 0
*/

int main() {
	int t, n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    
	    int x;
	    unordered_map<int,int> m;
	    for (int i = 0; i < n; ++i) {
	        cin>>x;
	        ++m[x];
	    }
	    if (n <= 2) {
	        cout<<0<<endl;
	        continue;
	    }
	    int maxfreq = 0;
	    for (auto & it : m) {
	        maxfreq = max(maxfreq, it.second);
	    }
	    if (maxfreq == 1) cout<<n-2<<endl;
	    else cout<<(n-maxfreq)<<endl;
	}
	return 0;
}