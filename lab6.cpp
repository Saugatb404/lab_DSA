// Circular Queue using Array

#include <iostream>
using namespace std;

class Queue {

    int* arr;
    int rear, front, size;

public:

    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {

        // Queue Full
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow!!" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;

        cout << value << " inserted into the circular queue." << endl;
    }

    void dequeue() {

        if (front == -1) {
            cout << "Queue Underflow!!" << endl;
            return;
        }

        cout << arr[front] << " is removed from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void display() {

        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue Elements : ";

        if (front <= rear) {

            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }

        }
        else {

            int i = front;

            while (i < size) {
                cout << arr[i] << " ";
                i++;
            }

            i = 0;

            while (i <= rear) {
                cout << arr[i] << " ";
                i++;
            }

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

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}