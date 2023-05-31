#include <bits/stdc++.h>
using namespace std;
 
bool isVowel(char c) {
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') ||  (c == 'u');
}
 
int main() {
 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t, n;
    string s;
    cin>>t; 
    while(t--) {
    	int count = 0;
    	cin>>n>>s;
    	for(int i = 0; i < n-1; ++i) {
    		if(!isVowel(s[i])) {
    			if(isVowel(s[i+1])) {
    				++count;
    				++i;
    			}
    		}
    	}
    	cout<<count<<endl;
    }
 
    return 0;
}