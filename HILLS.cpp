#include <bits/stdc++.h>
using namespace std;

int get_max_hills(vector<int> heights, int u, int d) {
    int count = 1;
    int parachutes = 0;
    for (int i = 1; i < heights.size(); ++i) {
        if (heights[i] >= heights[i-1]) {
            if (heights[i]-heights[i-1] <= u) {
                ++count;
            } else {
                break;
            }
        } else {
            if (heights[i-1] - heights[i] > d) {
                if (parachutes > 0) {
                    break;
                }
                ++parachutes;
            }
            ++count;
        }
    }
    return count;
}

int main() {
	int t, n, u, d;
	cin>>t;
	while (t--) {
	    cin>>n>>u>>d;
	    vector<int> heights(n);
	    for (int i = 0; i < n; ++i) {
	        cin>>heights[i];
	    }
	    cout<<endl;
	    cout<<get_max_hills(heights, u, d)<<endl;
	}
	return 0;
}