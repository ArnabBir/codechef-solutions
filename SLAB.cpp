#include <iostream>
using namespace std;

int get_tax(int n) {
    return max(0, min(n-250000, 250000))*0.05 
         + max(0, min(n-500000, 250000))*0.1 
         + max(0, min(n-750000, 250000))*0.15
         + max(0, min(n-1000000,250000))*0.2
         + max(0, min(n-1250000,250000))*0.25
         + max(0, n-1500000)*0.3;
}

int main() {
	int t, n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    cout<<n-get_tax(n)<<endl;
	}
	return 0;
}