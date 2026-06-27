// the implementation of queue operations i.e enqueue and dequeue using stack 

#include <iostream>

using namespace std;

class Queue {
    int front, rear, size;
    int *arr;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted element: " << arr[front] << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}