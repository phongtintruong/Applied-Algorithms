#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000000], b[1000000], ans[1000000];
map<int, int> mp;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
		mp[b[i]]=i;
	}
	sort(a, a+n);
	sort(b, b+n);
	for (int i=0;i<n;i++){
		ans[mp[b[i]]]=a[i];
	}
	for (int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
