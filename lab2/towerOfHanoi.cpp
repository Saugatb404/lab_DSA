#include <iostream>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c) {
    if (n > 0) {
        towerOfHanoi(n - 1, a, c, b);

    cout << "Move Disk " << n << " from "
         << a << " to " << c << endl;

    towerOfHanoi(n - 1, b, a, c);
    return ;
    }

}

int main() {
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}