#include <iostream>
#include <string>
using namespace std;
char check_phone_number = 1;
int number_calls_from[];
int number_total_calls=0;
int count_time_calls_from[];
// struct call_type{
//     int caller;
//     int receiver;
//     string date;
//     string starting_time;
//     string finishing_time;
// };

// call_type* call_ptr = new call_type;

void data(){
    string query;
    while (1){
        cin>>query;
        if (query=="#"){
            return;
        }
        if (query!="call"){
            cout<<"wrong usage"<<endl;
        }
        number_total_calls++;
    }
}
int main(){

}