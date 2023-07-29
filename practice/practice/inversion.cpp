#include <iostream>
using namespace std;

int n, a[1000001];
long long count(int a[], int l, int m, int r){



    long long ans=0, tmp=0;
    int n1 = m-l+1;
    int n2 = r-m;
    int left[n1], right[n2];

    for (int i=0;i<n1;i++){
        left[i]=a[l+i];
    }
    for (int i=0;i<n2;i++){
        right[i]=a[m+1+i];
    }

    int i=0, j=0, k=l;
    while (i<n1&&j<n2){
        if (left[i]<=right[j]){
            a[k]=left[i];
            i++;
            ans+=tmp;
        } else {
            a[k]=right[j];
            j++;
            tmp++;
        }
        k++;
    }

    while (i<n1){
        a[k]=left[i];
        i++;
        k++;
        ans+=tmp;
    }

    while (j<n2){
        a[k]=right[j];
        j++;
        k++;
    }

    return ans;
}

void no_Q(long long& ans, int a[], int l, int r){
    // cout<<"start "<<ans<<endl;
    if (l<r){
        int m = l+(r-l)/2;

        no_Q(ans, a, l, m);
        no_Q(ans, a, m+1, r);

        ans+=count(a, l, m, r);
        // cout<<l<<" "<<r<<" "<<ans<<endl;
    }
    // if (l==0&&r==n-1){
    //     cout<<ans;
    // }
    // cout<<ans<<endl;
}

int main(){
    long long ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    no_Q(ans, a, 0, n-1);
    ans = ans % 1000000007;
    cout<<ans;
    return 0;
}