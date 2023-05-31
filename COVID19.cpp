#include <bits/stdc++.h>
using namespace std;

int get_infected_count(vector<int> pos, int curr) {
    int n = pos.size();
    int count = 1;
    stack<int> s;
    s.push(curr);
    vector<bool> visited(n, false);
    visited[curr] = true;
    while (!s.empty()) {
        int x  = s.top();
        s.pop();
        if (x >= 1 && !visited[x-1] && abs(pos[x]-pos[x-1]) <= 2) {
            ++count;
            visited[x-1] = true;
            s.push(x-1);
        }
        if (x < n-1 && !visited[x+1] && abs(pos[x]-pos[x+1]) <= 2) {
            ++count;
            visited[x+1] = true;
            s.push(x+1);
        }
    }
    return count;
}

pair<int,int> get_min_max_infected_count(vector<int> pos) {
    int n = pos.size();
    int max_pos = 1;
    int min_pos = INT_MAX;
    for (int i = 0; i < n; ++i) {
        max_pos = max(max_pos, get_infected_count(pos, i));
        min_pos = min(min_pos, get_infected_count(pos, i));
    }
    return make_pair(min_pos, max_pos);
}

int main() {
	int t,n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    vector<int> input(n);
	    for (int i = 0; i < n; ++i) {
	        cin>>input[i];
	    }
	    pair<int,int> minmax = get_min_max_infected_count(input);
	    cout<<minmax.first<<" "<<minmax.second<<endl;
	}
	return 0;
}