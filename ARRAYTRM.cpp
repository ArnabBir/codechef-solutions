#include <bits/stdc++.h>
using namespace std;

vector<long long int> bitAND(30, 0);

int main() {
    
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T, N, K;
	cin>>T;
	while(T--) {
	    cin>>N>>K;
	    int a[N];
	    for(int i = 0; i < N; ++i) {
	        cin >> a[i];
	    }
	    if(N == 2) {
	        cout<<"YES"<<endl;
	    }
	    else {
	        int res[K+1] = {0};
	        for(int i = 0; i < N; ++i) {
	            ++res[a[i]%(K+1)]; 
	        }
	        bool flag = false;
	        for(int i = 0; i <= K; ++i) {
	            if(res[i] >= N-1) {
	                flag = true;
	                break;
	            }
	        }
	        if(flag)    cout<<"YES"<<endl;
	        else cout<<"NO"<<endl;
	    }
	}
	return 0;
}
