#include <iostream>
using namespace std;

void ifPalindromesPossible(int x, int y) {
    bool isXOdd = x%2;
    bool isYOdd = y%2;
    string s1, s2;
    if (isXOdd && isYOdd) {
        cout<<-1<<endl;
        return;
    } else if (!isXOdd && !isYOdd) {
            for (int i = 0; i < x/2; ++i) {
                s1 += 'a';
            }
            for (int i = 0; i < y; ++i) {
                s1 += 'b';
            }
            for (int i = 0; i < x/2; ++i) {
                s1 += 'a';
            }
            for (int i = 0; i < y/2; ++i) {
                s2 += 'b';
            }
            for (int i = 0; i < x; ++i) {
                s2 += 'a';
            }
            for (int i = 0; i < y/2; ++i) {
                s2 += 'b';
            }
        } else if (isXOdd){
            for (int i = 0; i < (x-1)/2; ++i) {
                s1 += 'a';
            }
            for (int i = 0; i < y/2; ++i) {
                s1 += 'b';
            }
            s1 += 'a';
            for (int i = 0; i < y/2; ++i) {
                s1 += 'b';
            }
            for (int i = 0; i < (x-1)/2; ++i) {
                s1 += 'a';
            }
            for (int i = 0; i < y/2; ++i) {
                s2 += 'b';
            }
            for (int i = 0; i < x; ++i) {
                s2 += 'a';
            }
            for (int i = 0; i < y/2; ++i) {
                s2 += 'b';
            }
        } else {
            for (int i = 0; i < (y-1)/2; ++i) {
                s1 += 'b';
            }
            for (int i = 0; i < x/2; ++i) {
                s1 += 'a';
            }
            s1 += 'b';
            for (int i = 0; i < x/2; ++i) {
                s1 += 'a';
            }
            for (int i = 0; i < (y-1)/2; ++i) {
                s1 += 'b';
            }
            for (int i = 0; i < x/2; ++i) {
                s2 += 'a';
            }
            for (int i = 0; i < y; ++i) {
                s2 += 'b';
            }
            for (int i = 0; i < x/2; ++i) {
                s2 += 'a';
            }
        }
        if (s1 == s2) {
            cout<<-1<<endl;
        } else {
            cout<<s1<<endl<<s2<<endl;
        }
}

int main() {
    int t, x, y;
    cin>>t;
    while (t--) {
        cin>>x>>y;
        ifPalindromesPossible(x,y);
    }
    return 0;
}
