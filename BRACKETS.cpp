#include <iostream>
using namespace std;

int f(string s) {
    int balance = 0;
    int max_balance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++balance;
        } else {
            --balance;
        }
        max_balance = max(max_balance, balance);
    }
    return max_balance;
}

int main() {
	int t;
	string s;
	cin>>t;
	while (t--) {
	    cin>>s;
	    int max_balance = f(s);
	    string balaced = "";
	    for (int i = 0; i < max_balance; ++i) {
	        balaced += "(";
	    }
	    for (int i = 0; i < max_balance; ++i) {
	        balaced += ")";
	    }
	    cout<<balaced<<endl;
	}
	return 0;
}