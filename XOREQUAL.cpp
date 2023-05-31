#include <iostream>

constexpr int N = 1e5;      //user can input n up to 1e5
unsigned long long  arr[N];
constexpr unsigned int p = 1e9 + 7;  // we have to find answer modulo p

//  pre-compute the powers of 2
 void pre() {
    arr[0] = 1;
    for (int i = 1; i < N; i++) {
        arr[i] = (2 * arr[i-1]) % p;  
    }
}

int main() {
    pre();
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::cout << arr[n-1] << std::endl ;
    }
    return 0;
}