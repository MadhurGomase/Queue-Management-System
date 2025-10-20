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