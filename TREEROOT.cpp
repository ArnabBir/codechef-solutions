#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t, n, x, y;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int id = 0, cid = 0;
	    while(n--) {
	        cin>>x>>y;
	        id += x;
	        cid += y;
	    }
	    cout<<id-cid<<endl;
	}
	return 0;
}
