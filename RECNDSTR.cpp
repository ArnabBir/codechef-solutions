#include <iostream>
using namespace std;

int main() {
	int t;
	string s;
	cin>>t;
	while (t--) {
	    cin>>s;
	    int n = s.size();
	    bool found = false;
	    for (int i = 0; i < n; ++i) {
	        int l = (i-1+n)%n;
	        int r = (i+1)%n;
	        if (s[l] != s[r]) {
	            found = true;
	            break;
	        }
	    }
	    if (found)  cout<<"NO"<<endl;
	    else cout<<"YES"<<endl;
	}
	return 0;
}