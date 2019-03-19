#include <bits/stdc++.h>
using namespace std;

bool visited[2001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, count;
	cin >>t;
	while(t--) {
	    cin>>n;
	    memset(visited, false, sizeof visited);
	    vector<pair<int, int> > ab;
	    int a, b;
	    count = 1;
	    for(int i = 0; i < n; ++i) {
	        cin>>a>>b;
	        ab.push_back(make_pair(a, b));
	    }
	    sort(ab.begin(), ab.end());
	    int bound = ab[0].second;
	    for(int i = 1; i < n; ++i) {
	        if(bound < ab[i].first) {
	            ++count;
	            bound = ab[i].second;
	        }
	        else {
	            bound = min(bound, ab[i].second);
	        }
	        
	    }
	    cout<<count<<endl;
	}
	return 0;
}
