#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastPow(int base ,int exp) {
    ll result = 1;
    while(exp > 0) {
        if(exp & 1) result  *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int main(){
    cout << fastPow(5 ,10);
    return 0;
}
