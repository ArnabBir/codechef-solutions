#include <iostream>
using namespace std;

int main() {
	
	int T;
	string s;
	
	cin>>T;
	while(T--) {
	    cin>>s;
	    int sum = 0;
        for(int i = 0; i < s.size(); ++i) { 
            if(s[i] > '0' && s[i] <= '9') {
                sum += s[i] - '0';
            }
        }
        cout<<sum<<endl;
	}
	return 0;
}
