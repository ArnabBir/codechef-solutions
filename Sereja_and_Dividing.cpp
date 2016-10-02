#include<iostream>
#include<cmath>
using namespace std;

int toDecimal(int n){
	int dec = 0, pow = 1;
	while(n){
		dec += (n % 10) * pow;
		n /= 10;
		pow *= 7;
	}
	return dec;
}
int to7ary(int n){
    int remainder;
    long sev = 0, i = 1;

    while(n != 0) {
        remainder = n%7;
        n = n/7;
        sev = sev  + (remainder*i);
        i = i*10;
    }
    return sev;
}

int main(){
	int T, A, B, C, L;
	int n = 10;
	cin>>T;
	while(T--){
		cin>>A>>B>>L;
        int temp = pow(7,L);
		C = toDecimal(A) / toDecimal(B);
		cout<<to7ary(C % temp)<<endl;
	}
	return 0;
}
