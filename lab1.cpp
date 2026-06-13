#include<iostream>
using namespace std;

void insert(int arr[], int &size, int n, int pos, int value) {
    if (size == n) {
        cout << "Array is full\n";
        return;
    }

    if (pos < 1 || pos > size + 1) {
        cout << "Invalid Position\n";
        return;
    }

    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    size++;
    cout<<"inserted...";
}

void remove(int arr[], int &size, int pos) {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }

    if (pos < 1 || pos > size) {
        cout << "Invalid Position\n";
        return;
    }

    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout<<"deleted....";
}

void display(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, pos, value;

    cout << "Enter size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    int* arr = new int[n];
    int size = 0;

    int choice;
    cout << "\n1) Insert  2) Delete  3) Display  4) Exit\n";
    cin >> choice;

    while (choice != 4) {

        if (choice == 1) {
            cout << "Enter position and value: ";
            cin >> pos >> value;
            insert(arr, size, n, pos, value);
        }
        else if (choice == 2) {
            cout << "Enter position to delete: ";
            cin >> pos;
            remove(arr, size, pos);
        }
        else if (choice == 3) {
            display(arr, size);
        }
        else {
            cout << "Invalid choice\n";
        }

        cout << "\n1) Insert  2) Delete  3) Display  4) Exit\n";
        cin >> choice;
    }

    delete[] arr;
    return 0;
}