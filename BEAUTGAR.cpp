#include <bits/stdc++.h>
using namespace std;

/*
RRGG -> RGRG
RRG -> 
RRRGGG-> RGGRRG -> RGRGRG
RRGGGR ->RRGGRG -> RGRG
*/

bool check(string &s) {
    for(int i = 0 ; i < s.size() - 1;  i++)
        if(s[i] == s[i + 1]) return false ;
    return (s.back() != s.front());
}

int main() {
	int t;
	string s;
	cin>>t;
	while (t--) {
	    cin>>s;
	    int n = s.size();
	    if (n%2) {
	        cout<<"no"<<endl;
	        continue;
	    }
	    int rc = 0, c = 0, same = 0;
	    for (int i = 0; i < n; ++i) {
	        
	        if (s[i] == s[(i+1)%n] && s[i] == 'R') {
	            ++same;
	            rc  = max(rc, same);
	        }
	    }
	    if ( rc > 2) {
	        cout<<"no"<<endl;
	        continue;
	    }
	    same = 0;
	    for (int i = 0; i < n; ++i) {
	        if (s[i] == s[(i+1)%n] && s[i] == 'G') {
	            ++same;
	            c = max(c, same);
	        }
	    }
	    if ( c > 2) {
	        cout<<"no"<<endl;
	        continue;
	    }
	    int l = -1 , r = -1 , ok = 0 ;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == s[(i + 1) % n]) {
                if(l == -1) l = i + 1 ;
                else if(r == -1) r = i  ;
                else ok = 1;
            }
        }
        if(ok) {
            cout << "no" << endl;
            continue ;
        }
        reverse(s.begin() + l , s.begin() + r + 1) ;
	    cout << (check(s) ? "yes" : "no") << endl ;
	}
	return 0;
}