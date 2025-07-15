#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    This code implements “running remainder” or “digit-by-digit modular reduction” — 
    a way to compute a large number’s remainder modulo m 
    without converting it into an actual integer.
    */

    int m = 13;
    string s = "2911285";

    int rem = 0;
    for(int i=0 ;i<s.size() ;i++) {
        rem = (rem * 10 + (s[i] - '0')) % m;
    }
    if(rem == 0) cout << "Yes";
    else cout<<"No";
    return 0;
}