#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t, n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int cardinality = 1<<n;
	    vector<int> array;
	    multiset<int> powerSet;
	    vector<int> subSum;
	    int temp;
	    for(int i = 0; i < cardinality; ++i) {
	        cin>>temp;
	        powerSet.insert(temp);
	    }
	   powerSet.erase(0);
	   subSum.push_back(0);
	    while(array.size() < n) {
	        int val = * powerSet.begin();
	        int x = subSum.size();
	        for(int i = 0; i < x; ++i) {
	            auto firstPtr = powerSet.find(subSum[i]+val);
	            powerSet.erase(firstPtr);
	            subSum.push_back(subSum[i]+val);
	        }
	        array.push_back(val);
	    }
	    for(int i = 0; i < n; ++i) {
	        cout<<array[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
