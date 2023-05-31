#include <bits/stdc++.h>

using namespace std;

vector<int> get_min_perm(int n) {
    if (n == 3) {
        return {1,2,3};
    }
    if (n == 4) {
        return {3,2,1,4};
    }
    vector<int> perm;
    perm.push_back(n);
    perm.push_back(n-3);
    for (int i = 1; i <= n-4; ++i) perm.push_back(i);
    perm.push_back(n-2);
    perm.push_back(n-1);
    return perm;
}

int main() {
	int t, n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    vector<int> result = get_min_perm(n);
	    for (int i = result.size()-1; i >= 0; --i) cout<<result[i]<<" ";
	    cout<<endl;
	}
	return 0;
}