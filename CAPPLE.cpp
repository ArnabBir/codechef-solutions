#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, temp;
	cin>>t;
	while(t--) {
		cin>>n;
		set<int> s;
		for(int i = 0; i < n; ++i) {
			cin>>temp;
			s.insert(temp);
		}
		cout<<s.size()<<endl;
	}

	return 0;
}
