#include<iostream>
using namespace std;

int main() {
    int num = 1;
    int* pointer = &num;

    cout << "Before update:" << endl;
    cout << "num: " << num << endl;
    cout << "*pointer: " << *pointer << endl;

    *pointer = 9;

    cout << "After update:" << endl;
    cout << "num: " << num << endl;
    cout << "*pointer: " << *pointer << endl;

    return 0;
}
