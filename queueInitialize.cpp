#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    Queue(){
        size = 20;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int x){
        if(rear != size){
            arr[rear] = x;
            rear++;
        }
        else cout << "Queue full" << endl;
    }

    int dequeue(){
        if(front != rear){
            int ans = arr[front];
            front++;

            if (front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
        else return -1;
    }

    bool isFull(){
        if (rear == size) return true;
        else return false;
    }

    bool isEmpty(){
        if (front == rear) return true;
        else return false;
    }

    int qSize(){
        return rear;
    }

    int qFront(){
        if (front != rear) return arr[front];
        else return -1;
    }

    int qDisplay(){
        for (int i = front; i <= rear - 1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(1334);
    q.enqueue(1335);
    q.qDisplay();
    q.qFront();
    q.dequeue();
    q.qFront();
    q.qDisplay();
    cout << q.qSize();
}

