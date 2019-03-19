#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N;
	string a, b;
	cin>>N>>a>>b;
	int shift = 0;
	int maxCount = 0;
	int i = 0, j;
	while(i < N) {
	    j = 0;
	    for(; j < N; ++j) {
	        if(a[j] != b[(i+j)%N]) {
	            break;
	        }
	    }
	    if(j > maxCount) {
	        maxCount = j;
	        shift = i;
	    }
	    i += j ? j : 1;
	    if(maxCount == N)   break;
	}
	cout<<shift<<endl;
	return 0;
}
