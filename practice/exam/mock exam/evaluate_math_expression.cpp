#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> bracket;
int pre_end=0;
bool isCloseBracket = false;

long long evaluate(string s, int start){
    cout<<"test0 start: "<<start<<" "<<s[start]<<endl;
    long long ans=0;
    if (s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'||s[0]==')'){
        cout<<"NOT_CORRECT"<<endl;
        exit(1);
    }
    int tmp=0;
    bool isStart=false;
    for (int i=start;i<s.length();i++){
        if (s[i]=='('){
            if (i==start||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='('){
                bracket.push('(');
                isStart=false;
            } else {
                cout<<"NOT_CORRECT"<<endl;
                exit(1);
            }
        } else if (s[i]==')'){
            cout<<"test13"<<endl;
            if (bracket.empty()){
                cout<<"test13.1"<<endl;
                cout<<"NOT_CORRECT"<<endl;
                exit(1);
            } else if (s[i-1]=='('){
                cout<<"test13.2"<<endl;
                cout<<"NOT_CORRECT"<<endl;
                exit(1);
            } else {
                cout<<"test13.3"<<endl;
                isStart=true;
                if (start==0){
                    bracket.pop();
                } else {
                    isCloseBracket=true;
                    bracket.pop();
                    pre_end=i-1;
                    ans=tmp;
                    cout<<"test1 ans: "<<ans<<endl;
                    return ans;
                }
            }
        } else if (s[i]>='0'&&s[i]<='9'){
            tmp=tmp*10+(s[i]-'0');
            isStart=true;
            cout<<"test12 tmp: "<<tmp<<endl;
        } else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            if (isStart){
                if (tmp!=0){
                    ans+=tmp;
                    tmp=0;
                    cout<<"test2 ans: "<<ans<<endl;
                }
                if (s[i]=='+'){
                    cout<<"test11"<<endl;
                    if ((s[start-1]=='*'||s[start-1]=='/')&&s[start-1]!='('){
                        pre_end=i-1;
                        cout<<"test3 ans: "<<ans<<endl;
                        return ans;
                    } else {
                        isStart=false;
                        ans+=evaluate(s, i+1);
                        if (isCloseBracket){
                            if (s[start]=='('){
                                isStart=true;
                                cout<<"test4 ans: "<<ans<<endl;
                                cout<<pre_end<<endl;
                                i=pre_end+1;
                                isCloseBracket=false;
                            } else {
                                return ans;
                            }
                        }
                        isStart=true;
                        cout<<"test4 ans: "<<ans<<endl;
                        cout<<pre_end<<endl;
                        i=pre_end+1;
                    }
                } else if (s[i]=='-'){
                    if ((s[start-1]=='*'||s[start-1]=='/')&&s[start-1]!='('){
                        pre_end=i-1;
                        cout<<"test5 ans: "<<ans<<endl;
                        return ans;
                    } else {
                        isStart=false;
                        ans-=evaluate(s, i+1);
                        if (isCloseBracket){
                            if (s[start]=='('){
                                isStart=true;
                                cout<<"test6 ans: "<<ans<<endl;
                                i=pre_end+1;
                                isCloseBracket=false;
                            } else {
                                return ans;
                            }
                        }        
                        isStart=true;
                        cout<<"test6 ans: "<<ans<<endl;
                        i=pre_end+1;                
                    }
                } else if (s[i]=='*'){
                    isStart=false;
                    ans*=evaluate(s, i+1);
                    if (isCloseBracket){
                        if (s[start]=='('){
                            isStart=true;
                            cout<<"test7 ans: "<<ans<<endl;
                            i=pre_end+1;
                            cout<<"test7 i: "<<i<<endl;
                            isCloseBracket=false;
                        } else {
                            return ans;
                        }
                    }       
                    isStart=true;
                    cout<<"test7 ans: "<<ans<<endl;
                    i=pre_end+1;
                    cout<<"test7 i: "<<i<<endl; 
                } else if (s[i]=='/'){
                    isStart=false;
                    ans/=evaluate(s, i+1);
                    if (isCloseBracket){
                        if (s[start]=='('){
                            isStart=true;
                            cout<<"test8 ans: "<<ans<<endl;
                            i=pre_end+1;
                            isCloseBracket=false;
                        } else {
                            return ans;
                        }
                    }
                    isStart=true;
                    cout<<"test8 ans: "<<ans<<endl;
                    i=pre_end+1;
                }
            } else if (s[i]=='-'){
                isStart=false;
                ans-=evaluate(s, i+1);
                if (isCloseBracket){
                    if (s[start]=='('){
                        isStart=true;
                        cout<<"test9 ans: "<<ans<<endl;
                        i=pre_end+1;
                        isCloseBracket=false;
                    } else {
                        return ans;
                    }
                }
                isStart=true;
                cout<<"test9 ans: "<<ans<<endl;
                i=pre_end+1;
            } else {
                cout<<"NOT_CORRECT"<<endl;
                exit(1);
            }
        }
    }
    if (bracket.empty()){
        if (tmp!=0){
            ans+=tmp;
        }
        pre_end=s.length();
        cout<<"test10 ans: "<<ans<<endl;
        return ans;
    } else {
        cout<<"NOT_CORRECT"<<endl;
        exit(1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    getline(cin, s);
    cout<<evaluate(s, 0)%(long long)(1e9+7)<<endl;

    cout<<s;
    return 0;
}