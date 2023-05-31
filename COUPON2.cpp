#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, d, c;
	int a[3], b[3];
	cin>>t;
	while (t--) {
	    cin>>d>>c;
	    for (int i = 0; i < 3; ++i) {
	        cin>>a[i];
	    }
	    for (int i = 0; i < 3; ++i) {
	        cin>>b[i];
	    }
	    int order1_cost = a[0] + a[1] + a[2];
	    int order2_cost = b[0] + b[1] + b[2];
	    int total_without_coupon = order1_cost + order2_cost + 2*d;
	    int total_with_coupon = order1_cost  + order2_cost + c + (order1_cost >= 150 ? 0 : d) + (order2_cost >= 150 ? 0 : d);
	    cout<<((total_with_coupon < total_without_coupon) ? "YES" : "NO")<<endl;
	}
	return 0;
}