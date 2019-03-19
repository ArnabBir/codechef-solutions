#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	long long int n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int count5 = 0;
	    while(n) {
	        n /= 5;
	        count5 += n;
	    }
	    cout<<count5<<endl;
	}
	return 0;
}
