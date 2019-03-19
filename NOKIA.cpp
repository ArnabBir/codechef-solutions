#include <bits/stdc++.h>
using namespace std;

int minLen[31]; 

int getMinLen(int n) {
    
    if(minLen[n] != -1) return minLen[n];
    if(n%2) minLen[n] = (n+1) + 2 * getMinLen((n-1)/2);
    else    minLen[n] = (n+1) + getMinLen(n/2) + getMinLen(n/2-1);
    return minLen[n];
}

int main() {
	
	int t, n, m;
	memset(minLen, -1, sizeof minLen);
	minLen[0] = 0;
	cin>>t;
	while(t--) {
	    cin>>n>>m;
	    if(getMinLen(n) > m) {
	        cout <<  -1 << endl;
	    }
	    else {
	        cout<<m-min(m, ((n+1)*(n+2))/2 - 1)<<endl;
	    }
	}
	return 0;
}
