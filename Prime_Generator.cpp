#include<iostream>
#include<cmath>
using namespace std;
 
void check_prime(int m){
	if (m == 2){
        cout<<2<<endl;
        return;
	}
 
    if (m%2 == 0)
        return;
 
    for (int i=3;i<=sqrt(m);i+=2)
        if (m%i==0)
            return;
 
    cout<<m<<endl;
}
 
void print_prime(int m, int n){
	while(m <= n){
		check_prime(m++);
	}
 
}
 
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(m == 0) ++m;
		if(m == 1 && n > 0) ++m;
		if(m == 2 && n == 2){ cout<<2<<endl<<endl; continue;}
		print_prime(m,n);
		cout<<endl;
	}
 
	return 0;
}
