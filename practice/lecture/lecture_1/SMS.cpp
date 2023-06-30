#include<iostream>
#include<string.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio (0);
    cin . tie (0); cout . tie (0);

    string key[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", " "};
    int n;
    cin>>n;
    cin.ignore();
    for (int z=0;z<n;z++){
        string s;
        getline(cin, s);
        int ans=0;
        for (int i=0;i<s.length();i++){
            for (string tmp : key){
                for (int j=0;j<tmp.length();j++){
                    if (s[i]==tmp[j]){
                        ans+=(j+1);
                    }
                }
            }
        }
        cout<<"Case #"<<z+1<<": "<<ans<<endl;
        cin;
    }
    return 0;
}