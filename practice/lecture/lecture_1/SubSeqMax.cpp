#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int min_seq=0, max_subseq=0,sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i];
        if (sum<min_seq){
            min_seq = sum;
        }
        if (sum-min_seq>max_subseq){
            max_subseq = sum - min_seq;
        }
    }
    cout<<max_subseq;
}
