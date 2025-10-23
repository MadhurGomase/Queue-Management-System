#include<iostream>
using namespace std;

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

int main(){
    Queue q;
    q.enQueue(1334);
    q.enQueue(1335);
    q.qDisplay();
    cout << q.qFront() << endl;
    q.deQueue();
    cout << q.qFront() << endl;
    q.qDisplay();
    cout << q.qSize();
}

