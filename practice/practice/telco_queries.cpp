#include <bits/stdc++.h>
using namespace std;

int isCorrectNumbers=1;
map<string, int> call_from;
map<string, int> duration;
int total_call = 0;

bool check_phone_number(string number){
    if(number.size() != 10) return false;
    for(int i = 0; i < number.size(); ++i){
        if(number[i] < '0' || number[i] > '9') return false;
    }
    return true;
}

int calDuration(string from_time, string to_time){
    // cout<<from_time<<" "<<to_time<<endl;
    // time format: hh:mm:ss
    int from_hour = stoi(from_time.substr(0, 2));
    // cout<<from_hour<<endl;
    int from_minute = stoi(from_time.substr(3, 2));
    int from_second = stoi(from_time.substr(6, 2));

    int to_hour = stoi(to_time.substr(0, 2));
    int to_minute = stoi(to_time.substr(3, 2));
    int to_second = stoi(to_time.substr(6, 2));

    int duration = (to_hour - from_hour) * 3600 + (to_minute - from_minute) * 60 + (to_second - from_second);
    // cout<<"test duration: "<<duration<<endl;
    return duration;
}

void input(){
    while(1){
        string cmd, from_number, to_number, date, from_time, to_time;
        cin >> cmd;
        if (cmd == "#") break;
        total_call++;

        cin >> from_number;
        if (!check_phone_number(from_number)) isCorrectNumbers = 0;
        call_from[from_number]++;

        cin >> to_number;
        if (!check_phone_number(to_number)) isCorrectNumbers = 0;

        cin >> date;

        cin >> from_time;
        cin >> to_time;

        // cout<<"TEST "<<from_time<<" "<<to_time<<endl;

        duration[from_number] += calDuration(from_time, to_time);
    }
}

void queryHandle(){
    while (1){
        string query;
        cin >> query;
        if (query=="#") break;
        if (query=="?check_phone_number"){
            cout<<isCorrectNumbers<<endl;
        }
        if (query=="?number_calls_from"){
            string number;
            cin>>number;
            cout<<call_from[number]<<endl;
        }
        if (query=="?number_total_calls"){
            cout<<total_call<<endl;
        }
        if (query=="?count_time_calls_from"){
            string number;
            cin>>number;
            cout<<duration[number]<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    queryHandle();
    return 0;
}