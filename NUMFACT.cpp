#include <bits/stdc++.h>
using namespace std;

vector<long long int> bitAND(30, 0);

int main() {
    
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T, N;
	cin>>T;
	while(T--) {
	    cin>>N;
	    int a[N];
	    int maxA = 0;
	    for(int i = 0; i < N; ++i) {
	        cin>>a[i];
	        maxA = max(maxA, a[i]);
	    }
	    long long int soln = 1;
	    int counter[maxA+1] = {0};
	    for(int j = 0; j < N; ++j) {
	        for(int i = 2; i <= a[j]; i += 2) {
	            while(a[j] % i == 0  && a[j] > 1) {
	                ++counter[i];
	                a[j] /= i;
	            }
	            if(i == 2)  --i;
	        }
	    }
	    for(int i = 2; i <= maxA; ++i) {
	        soln *= (counter[i] + 1);
	    }
	    cout<<soln<<endl;
	}
	return 0;
}
