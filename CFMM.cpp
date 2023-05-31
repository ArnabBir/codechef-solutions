#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
	cin>>t;
	while (t--) {
	    unordered_map<char, int> um;
	    cin>>n;
	    string s;
	    while (n--) {
	        cin>>s;
	        for (int i = 0; i < s.size(); ++i) {
	            ++um[s[i]];
	        }
	    }
	    if (um['c'] < 2 || um['e'] < 2) {
	        cout<<0<<endl;
	    } else {
	        int mincount = um['c'] / 2;
	        mincount = min(mincount, um['o']);
	        mincount = min(mincount, um['d']);
	        mincount = min(mincount, um['e'] / 2);
	        mincount = min(mincount, um['h']);
	        mincount = min(mincount, um['f']);
	        cout<<mincount<<endl;
	    }
	}
	return 0;
}