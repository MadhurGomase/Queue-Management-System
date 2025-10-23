#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//from queueInitialize.cpp
class Node{
    public:
    int data;
    Node* next;

    Node(){
        data = 0;
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
        Node* newNode = new Node();
        newNode -> data = x;
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

    void qDisplay(){
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
    int mm = ltm->tm_min;          // minutes (0–59)
    int ss = ltm->tm_sec;          // seconds (0-59)

    int timeArrival = hh * 60 * 60 + mm * 60 + ss;       // combinely tell seconds passed
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

    Queue accCreate1;
    Queue accCreate2;
    Queue passEntry;
    Queue loanEnq;
    Queue forEx;
    Queue otherQuery;
    int opt;

    while (true){
        cout << "########\n";
        cout << "1. Add to queue\n";
        cout << "2. View queues\n";
        cout << "3. Estimate wait time\n";
        cout << "4. Dequeue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> opt;

        switch(opt) {
            case 1:
            {
                int task;
                cout << "Task choice: \n";
                cout << "1. Account creation\n";
                cout << "2. Passbook entry\n";
                cout << "3. Loan enquiry\n";
                cout << "4. Foreign exchange\n";
                cout << "5. Other queries\n";
                cout << "Enter choice : ";

                cin >> task;

                int token = addCustomer(task);
                cout << "Token number: " << token << endl;

                switch(task) {
                    case 1:
                    {
                        if (accCreate1.qSize() <= accCreate2.qSize()){
                            accCreate1.enQueue(token);
                            cout << "Head to counter 1\n";
                            break;
                        }
                        else{
                            accCreate2.enQueue(token);
                            cout << "Head to counter 2\n";
                            break;
                        }
                    }

                    case 2:
                    {
                        passEntry.enQueue(token);
                        cout << "Head to counter 3\n";
                        break;
                    }

                    case 3:
                    {
                        loanEnq.enQueue(token);
                        cout << "Head to counter 4\n";
                        break;
                    }

                    case 4:
                    {
                        forEx.enQueue(token);
                        cout << "Head to counter 5\n";
                        break;
                    }

                    case 5:
                    {
                        otherQuery.enQueue(token);
                        cout << "Head to counter 6\n";
                        break;
                    }
                    
                    default:
                    {
                        cout << "Enter valid task choice\n" << endl;    
                    }
                }
                break;
            }
            
            case 2:
            {
                cout << "Account creation 1: ";
                accCreate1.qDisplay();
                cout << endl;
                cout << "Account creation 2: ";
                accCreate2.qDisplay();
                cout << endl;
                cout << "Passbook entry: ";
                passEntry.qDisplay();
                cout << endl;
                cout << "Loan enquiry: ";
                loanEnq.qDisplay();
                cout << endl;
                cout << "Foerign exchange: ";
                forEx.qDisplay();
                cout << endl;
                cout << "Other queries: ";
                otherQuery.qDisplay();
                cout << endl;
                break;
            }
        }
        if (opt == 5){
            break;
        }
    }
}