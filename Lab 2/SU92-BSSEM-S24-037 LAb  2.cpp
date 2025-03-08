#include<iostream>
using namespace std;

int findMax(int arr[], int length) {
    int maximum = arr[0];  
    for (int i = 1; i < length; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];  
        }
    }
    return maximum;  
}

int main() {
    int numbers[5] = {9, 18, 8, 1, 6};
    int largest = findMax(numbers, 5);
    cout << "Max value is: " << largest << endl;
    return 0;
}
