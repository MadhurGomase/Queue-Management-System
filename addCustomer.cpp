#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Customer{
    string custName;
    int taskChoice;
    int arrivalTime;
    int tokenNum;
};

int addCustomer(int choice){
    Customer c;

    cout << "Enter name: ";
    getline(cin, c.custName);
    c.taskChoice = choice;

    string strChoice = to_string(choice);

    //Fetch system time
    time_t now = time(0);           // get current time
    tm *ltm = localtime(&now);      // convert to local time

    int hh = ltm->tm_hour;          // hours (0–23)
    int mm = ltm->tm_min;           // minutes (0–59)

    int timeArrival = hh * 100 + mm;       // combine into HHMM format
    c.arrivalTime = timeArrival;

    string strTime = to_string(timeArrival);

    // Bank IFSC = XXXX0111111, here, 
    //the last six digits indicate the
    // bank branch location

    string branchLoc = "111111";

    //Token number will be a unique 
    //temporary reference for the customer

    c.tokenNum = stoi(strChoice + strTime);

    return c.tokenNum;
}
    
int main(){
    cout << addCustomer(2);
}