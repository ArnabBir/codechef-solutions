#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num) {
    if(num < 2) {
        return false;
    } else if(num == 2) {
        return true;
    } else if(num % 2 == 0) {
        return false;
    }
    float maximum = sqrt(num);
    for(int i = 3; i < maximum; i += 2) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_square_free_number(int num)
{
	if((num % 4) == 0)
		return false;
	float maximum = sqrt(num);
    if (maximum  == (int)maximum)
        return false;
	for(int i = 3; i < maximum; i = i + 2)
	{
		if ((num % (i*i)) == 0)
			return false;
	}
	return true;
}

int prime_div(int num)
{
    int counter = 0;
    int square_root = (int) sqrt(num) + 1;
    for(int i = 1; i < square_root; ++i){
        if (((num % i) == 0)&& (i*i!=num)){
            if(isPrime(i))
                ++counter;
            if(isPrime(num / i))
                ++counter;
        }
        if (((num % i) == 0) && (i*i==num))
            if(isPrime(i))
                ++counter;
    }
    return counter;
}


int div_sum(int num)
{
    int sum = 0;
    int square_root = (int) sqrt(num) + 1;
    for (int i = 1; i < square_root; ++i) {
        if (((num % i) == 0)&& (i*i!=num))
            sum += i + num / i;
        if (((num % i) == 0) && (i*i==num))
            sum += i;
    }
    return sum;
}
int main()
{
	int L,R,T = 0;
	cin>>T;
	while(T--)
	{
	    int sum_of_divisors = 0;
		cin>>L;
		cin>>R;
		for(int i = L; i <= R; ++i){
            if(is_square_free_number(i)){
                int sum = div_sum(i);
                if(isPrime(prime_div(sum))){
                    sum_of_divisors += sum;
                }
            }
		}
		cout<<sum_of_divisors<<endl;
	}
	return 0;
}
