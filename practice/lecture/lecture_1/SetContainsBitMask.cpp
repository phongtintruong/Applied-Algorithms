#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m], ans=m;
    for (int i=0;i<m;i++){
        cin>>b[i];
        for (int j=0;j<n;j++){
            if (b[i]==a[j]){
                ans--;
                break;
            }
        }
    }
    cout<<(ans==0)?1:0;
}