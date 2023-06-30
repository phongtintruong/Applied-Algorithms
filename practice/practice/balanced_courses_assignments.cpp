#include <iostream>
#include <vector>
using namespace std;

int m, n, ans=31, no_conflict, id=0;
int no_course[31], conflict[31][31];
vector<int> teacher[31];
vector<int> course[11];
vector<int> ans_array;


void Try(int k){
    // cout<<"run..."<<endl;
    for (auto i=teacher[k].begin();i!=teacher[k].end();i++){
        int is_conflict=0;
        for (auto j=course[*i].begin();j!=course[*i].end();j++){
            // cout<<"check "<<k<<" "<<*j<<endl;
            if (conflict[k][*j]||conflict[*j][k]){
                // cout<<"conflict "<<k<<" "<<*j<<endl;
                is_conflict=1;
                break;
            }
        }
        if (!is_conflict){
            course[*i].push_back(k);
            // cout<<ans<<" "<<course[*i].size()<<endl;
            if (course[*i].size()>=ans){
                course[*i].pop_back();
                continue;
            }
            if (k==n) {
                int tmp=0;
                for (int u=1;u<=m;u++){
                    if (tmp<course[u].size()){
                        tmp=course[u].size();
                        id=u;
                    }
                }
                cout<<"start debug"<<endl;
                cout<<k<<" "<<tmp<<" "<<ans<<" "<<id<<" "<<course[id].size()<<endl;
                for (auto i = course[id].begin();i!=course[id].end();i++){
                        cout<<*i<<" ";
                }
                cout<<endl;
                ans=tmp;
            } else {
                Try(k+1);
                course[*i].pop_back();
            }
        } else {
            continue;
        }
    }
}

int main(){
    // init conflict array 
    for (int i=1;i<31;i++){
        for (int j=1;j<31;j++){
            conflict[i][j]=0;
        }
    }

    cin>>m>>n;
    for (int i=1;i<=m;i++){
        cin>>no_course[i];
        for (int j=1;j<=no_course[i];j++){
            int tmp_course;
            cin>>tmp_course;
            teacher[tmp_course].push_back(i);
        }
    }
    cin>>no_conflict;
    for (int i=0;i<no_conflict;i++){
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        conflict[tmp1][tmp2]=1;
        // cout<<"input "<<tmp1<<" "<<tmp2<<" "<<conflict[tmp1][tmp2]<<endl;
    }

    Try(1);
    cout<<ans;
    // cout<<"abc";
    return 0;
}