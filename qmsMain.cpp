#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//from queueInitialize.cpp
class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enQueue(int x){
        Node* newNode = new Node(x);
        if (rear == NULL){
            front = rear = newNode;
        }
        else{
            rear -> next = newNode;
            rear = newNode;
        }
    }

    int deQueue(){
        if (front == NULL){
            cout << "Empty queue";
            return -1;
        }
        
        Node* temp = front;
        int data = temp -> data;
        front = front -> next;

        if (front == NULL) rear = NULL;

        delete temp;
        return data;
    }

    bool isEmpty(){
        if (front == NULL) return true;
        else return false;
    }

    int qSize(){
        Node* temp = front;
        int count = 0;
        while (temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }

    int qFront(){
        if (front != NULL) return front -> data;
        else return -1;
    }

    int qDisplay(){
        Node* temp = front;
        while (temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};
//queueInitialize.cpp ends

//from addCustomer.cpp
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
//addCustomer.cpp ends

int main(){

    int opt;
    cout << "########\n";
    cout << "1. Add to queue\n";
    cout << "2. Estimate wait time\n";
    cout << "3. Dequeue\n";
    cout << "Enter choice: ";
    cin >> opt;

    Queue accCreate1;
    Queue accCreate2;
    Queue passEntry;
    Queue forEx;
    Queue otherQuery;


    switch(opt) {
        case 1:
            int task;
            cout << "Task choice: \n";
            cout << "1. Account creation\n";
            cout << "2. Passbook entry\n";
            cout << "3. Loan enquiry\n";
            cout << "4. Foreign exchange\n";
            cout << "5. Other queries\n";
            cout << "Enter choice : ";

            cin >> task;

            
    }
}