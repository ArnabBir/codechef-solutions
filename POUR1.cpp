#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, a, b, c;
	cin>>t;
	while(t--) {
	    cin>>a>>b>>c;
	    if(c > a && c > b) {
	        cout<<-1<<endl;
	    }
	    else if(c == a || c == b) {
	        cout<<1<<endl;
	    }
	    else if(a == b) {
	        cout<<-1<<endl;
	    }
	    else {
	        if(a < b)   swap(a, b);
	        int gcd = __gcd(a, b);
	        if(c%gcd) {
	            cout<<-1<<endl;
	        }
	        else {
	            int count1 = 0, count2 = 0;
	            int aFilled = 0, bFilled = 0;
	            while(aFilled != c && bFilled != c) {
	                if(aFilled == 0) {
	                    aFilled = a;
	                }
	                else if(bFilled < b) {
	                    int temp = min(b-bFilled, aFilled);
	                    aFilled -= temp;
	                    bFilled += temp;
	                }
	                else if(bFilled == b) {
	                    bFilled = 0;
	                }
	                ++count1;
	            }
	            aFilled = 0, bFilled = 0;
	            while(aFilled != c && bFilled != c) {
	                if(bFilled == 0) {
	                    bFilled = b;
	                }
	                else if(aFilled < a) {
	                    int temp = min(a-aFilled, bFilled);
	                    bFilled -= temp;
	                    aFilled += temp;
	                }
	                else if(aFilled == a) {
	                    aFilled = 0;
	                }
	                ++count2;
	            }
	            cout<<min(count1, count2)<<endl;
	        }
	    }
	}
	return 0;
}
