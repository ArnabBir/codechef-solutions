#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n,x;
	cin>>t;
	while(t--) {
	    cin>>n>>x;
	    vector<int> v(n);
	    int temp = v[0];
	    for (int i = 0; i < n; ++i) {
	        cin>>v[i];
	        if (i == 0) temp = v[0];
	        else    temp |= v[i];
	    }
	    bool found = false;
	    for (int i = 0; i <= x+1; ++i) {
	        int orval = temp | i;
	        if (orval == x) {
	            found = true;
	            cout<<i<<endl;
	            break;
	        }
	    }
	    if (!found) cout<<-1<<endl;
	}
	return 0;
}