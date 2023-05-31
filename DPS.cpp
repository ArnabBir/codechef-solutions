#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	bool result;
    int t, n, oddCount, evenCount;
    string s;
    cin>>t; 
    while(t--) {
    	int count = 0;
    	cin>>s;
    	n = s.length();
    	vector<int> m(26, 0);
    	for(int i = 0; i < n; ++i) {
    		++m[s[i]-'a'];
    	}
    	oddCount = 0;
    	evenCount = 0;
    	for(int i = 0; i < 26; ++i) {
    		if(m[i] % 2) {
    			++oddCount;
    		}
    		else {
    			++evenCount;
    		}
    	}
    	if(n%2) {
    		if(oddCount == 1 || oddCount == 3) {
    			result = true;
    		}
    		else {
    			result = false;
    		}
    		
    	}
    	else {
    		if(oddCount == 2) {
    			result = true;
    		}
    		else {
    			result = false;
    		}
    	}
    	if(result) {
    		cout<<"DPS\n";
    	}
    	else {
    		cout<<"!DPS\n";
    	}
    }
    
    return 0;
}