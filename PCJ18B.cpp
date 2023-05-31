#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    int count = 0;
	    for (int i = 1; i <= n; i += 2) {
	        count += (n+1-i) * (n+1-i);
	    }
	    cout<<count<<endl;
	}
	return 0;
}