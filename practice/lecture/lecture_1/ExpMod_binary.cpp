#include<iostream>
using namespace std;
int main(){
    unsigned long long a, b, ans=1, c=1e9+7;
    cin>>a>>b;
    // ans = a^b mod c = (a mod c)^b mod c
    // (a*a) mod c = ((a mod c) * (a mod c)) mod c
    // a^b = (x^2)^(n/2)        //b is even 
    //     = x*(x^2)^((n-1)/2)  //b is odd
    while(b>0){
        if (b%2==1){
            ans = ((ans%c)*(a%c))%c;
        }
        a = ((a%c)*(a%c))%c;
        b /= 2;
    }
    cout<<ans;
}