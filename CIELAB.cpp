#include <iostream>
using namespace std;

int main() {
	
	int a, b, c, d;
	cin>>a>>b;
	c = a - b;
	d  = (c + 1) % 10;
	d = d ? d : 5;
	c = c / 10 * 10 + d;
	cout<<c<<endl;
	return 0;
}
