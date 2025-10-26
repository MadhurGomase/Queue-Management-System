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

int arrMin(int arr[], int size){
    int min = 100;
    for(int i = 0; i <= size - 1; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    int idx = 0;
    for(int i = 0; i <= size - 1; i++){
        if(arr[i] == min){
            return i;
            break;
        }
    }
}

int main(){
    Queue q;
    q.enQueue(1334);
    q.enQueue(1335);
    q.qDisplay();
    cout << q.qFront() << endl;
    q.deQueue();
    cout << q.qFront() << endl;
    q.qDisplay();
    cout << q.qSize() << endl;

    Queue q1,q2,q3;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q2.enQueue(1);
    q2.enQueue(2);
    q3.enQueue(1);
    q3.enQueue(2);
    Queue* qArr[] = {&q1, &q2, &q3};
    int qSizeArr[] = {q1.qSize(), q2.qSize(), q3.qSize()};
    int arrSize = sizeof(qSizeArr) / sizeof(qSizeArr[0]);
    qArr[arrMin(qSizeArr, arrSize)]->enQueue(1234);
    int qSizeArr1[] = {q1.qSize(), q2.qSize(), q3.qSize()};
    qArr[arrMin(qSizeArr1, arrSize)]->enQueue(1234);
    q1.qDisplay();
    q2.qDisplay();
    q3.qDisplay();

}

