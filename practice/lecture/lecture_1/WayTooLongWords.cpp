#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    scanf("%d",&n);
    while(n--){
        cin>>s;
        cout<<(s.length()<=10?s:s.at(0)+to_string(s.length()-2)+s.at(s.length()-1))<<"\n";
    }

    return 0;
}