#include <bits/stdc++.h>
#define ll long long int
#define CF 0.75
using namespace std;

int main() {
	
	int t, d;
	string s;
	cin>>t;
	while(t--) {
	    cin>>d>>s;
	    bool flag = true;
	    ll proxy = 0, attendance = 0, cutoff = (ll)ceil(CF * (double)d);
	    for(int i = 0; i < d; ++i) {
	        if(i < 2 || i+2 >= d) {
	            if(s[i] == 'P') {
	                ++attendance;
	            }
	        }
	        else {
	            if(s[i] == 'A') {
	                if(((s[i-2] == 'P') || (s[i-1] == 'P'))
	                && ((s[i+1] == 'P') || (s[i+2] == 'P'))) {
	                    //cout<<i<<" ";
	                    ++proxy;
	                }
	            }
	            else {
	                ++attendance;
	            }
	        }
	    }
	    //cout<<endl<<attendance<<" "<<proxy<<" "<<cutoff<<endl;
	    if(attendance + proxy >= cutoff)    {
	        if(attendance > cutoff) {
	            cout<<0<<endl;
	        }
	        else    cout<<cutoff - attendance<<endl;
	    }
	    else    cout<<-1<<endl;
	}
	return 0;
}