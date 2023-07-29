#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int a[5];


int main(){
	cin>>n;
    int tmp;
    for (int i=1;i<5;i++){
        a[i]=0;
    }
	for (int i=0;i<n;i++){
		cin>>tmp;
		a[tmp]++;
	}
	ans+=a[4];
    ans+=a[3];
    ans+=a[2]/2;
    a[2]=a[2]%2;
    if (a[2]){
        ans++;
    }
    if (a[1]>a[3]){
        a[1]-=a[3];
        if (a[2]){
            if (a[1]>2){
                a[1]-=2;
                ans+=a[1]/4;
                a[1]=a[1]%4;
                if (a[1]){
                    ans++;
                }
            }
        } else {
            ans+=a[1]/4;
            a[1]=a[1]%4;
            if (a[1]){
                ans++;
            }
        }
    }
    cout<<ans;
	return 0;
}
