#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1010][1010];
int h[1010]={0};
int ans=0;

void solve(){
    // cout<<"test 1"<<endl;
    for (int i=0;i<n;i++){
        // cout<<"test 1.0 "<<i<<endl;
        stack<int> st;
        map<int, int> mp;
        // cout<<"test 1.0.1 "<<st.size()<<endl;
        for (int j=0;j<m;j++){
            // cout<<"test 1.0.2 "<<j<<endl;
            if (a[i][j]==1){
                // cout<<"test 1.0.3 "<<a[i][j]<<endl;
                // cout<<"test 1.0.4 "<<h[j]<<endl;
                h[j]+=1;
                // cout<<"test 1.1 "<<h[j]<<endl;
            }
            else{
                h[j]=0;
                // cout<<"test 1.2 "<<h[j]<<endl;
            }

            // cout<<h[j]<<" ";


            if (j==0){
                st.push(h[j]);
                mp[h[j]]++;
                // cout<<"test 1.3 "<<mp[h[j]]<<endl;
                continue;
            }
            if (h[j]>st.top()){
                st.push(h[j]);
                mp[h[j]]++;
                // cout<<"test 1.4 "<<mp[h[j]]<<endl;
            } else if (h[j]==st.top()){
                mp[h[j]]++;
                // cout<<"test 1.5 "<<mp[h[j]]<<endl;
            } else {
                int tmp;
                while (h[j]<st.top()){
                    // cout<<"TEST 1.6 "<<ans<<endl;
                    tmp=st.top();
                    ans = max(ans, tmp*mp[tmp]);
                    // cout<<"test 2 "<<ans<<endl;
                    st.pop();
                    if (st.empty()){
                        st.push(h[j]);
                        mp[h[j]]++;
                        mp[h[j]]+=mp[tmp];
                        mp.erase(tmp);
                        break;
                    }

                    if (h[j]==st.top()){
                        mp[h[j]]++;
                        mp[h[j]]+=mp[tmp];
                        mp.erase(tmp);
                    } else if (h[j]>st.top()){
                        st.push(h[j]);
                        mp[h[j]]++;
                        mp[h[j]]+=mp[tmp];
                        mp.erase(tmp);
                    }

                    mp[st.top()]+=mp[tmp];
                    mp.erase(tmp);
                }
            }        
        }
        // cout<<endl;
        while (!st.empty()){
            int tmp=st.top();
            ans = max(ans, tmp*mp[tmp]);
            st.pop();
            if (!st.empty()){
                mp[st.top()]+=mp[tmp];
                mp.erase(tmp);
            }
            // cout<<"test 3 "<<ans<<endl;
        }        
    }
    // return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    // cout<<endl;
    solve();
    cout<<ans;
    return 0;
}