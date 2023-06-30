#include<iostream>
#include<math.h>
using namespace std;
int main(){
    unsigned long long a, b;
    cin>>a>>b;
    cout<<((a%(int)(pow(10,9)+7))+(b%(int)(pow(10,9)+7)))%(int)(pow(10,9)+7);
    return 0;
}