#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

void compLeftGCD(vector<int> & a, vector<int> & leftGCD, int sz) {
    for(int i = 1; i < sz; ++i) {
        leftGCD[i] = __gcd(leftGCD[i-1], a[i]);
    }
}

void compRightGCD(vector<int> & a, vector<int> & rightGCD, int sz) {
    for(int i = sz-2; i >= 0; --i) {
        rightGCD[i] = __gcd(rightGCD[i+1], a[i]);
    }
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, temp, sz;
	cin>>t;
	while(t--) {
        cin>>n;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            cin>>temp;
            s.insert(temp);
        }
        vector<int> a(s.begin(), s.end());
        sz = a.size();
        if(sz > 1) {
            vector<int> leftGCD(sz), rightGCD(sz);
            leftGCD[0] = a[0];
            rightGCD[sz-1] = a[sz-1];
            compLeftGCD(a, leftGCD, sz);
            compRightGCD(a, rightGCD, sz);
            ll maxSum = 0, sum = 0;
            for(int i = 0; i < sz; ++i) {
                //cout<<leftGCD[i]<<" "<<a[i]<<" "<<rightGCD[i]<<endl;
                if(i > 0 && i < sz-1) {
                    sum = __gcd(leftGCD[i-1], rightGCD[i+1]) + a[i];
                }
                else if(i == 0){
                    sum = rightGCD[i+1] + a[i];
                }
                else {
                    sum = leftGCD[i-1] + a[i];
                }
                maxSum = max(maxSum, sum);
            }
            cout<<maxSum<<endl;
        }
        else {
            cout<<2*a[0]<<endl;
        }
	}
	return 0;
}