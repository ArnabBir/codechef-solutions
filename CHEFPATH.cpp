#include <iostream>
using namespace std;

int main() {
	int t;
	long long int n, m;
	cin>>t;
	while (t--) {
	    cin>>n>>m;
	    if ( n > m) {
	        swap(n,m);
	    }
	    if (n==1) {
	        if (m == 2) {
	            cout<<"Yes"<<endl;
	        } else {
	            cout<<"No"<<endl;
	        }
	    } else if (n&1 && m&1) {
	        cout<<"No"<<endl;
	    } else {
	        cout<<"Yes"<<endl;
	    }
	}
	return 0;
}