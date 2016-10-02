#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int A[N];
	int temp, maximum = 0;
	for(int i = 0; i < N; ++i) cin>>A[i];
	for(int i = 0; i < N - 1; ++i){
		for(int j = i + 1; j < N; ++j){
			temp = (A[i] & A[j]);
			if(maximum < temp) maximum = temp;
        }
	}
	cout<<maximum<<endl;

	return 0;
}
