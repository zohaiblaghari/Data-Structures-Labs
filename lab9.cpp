#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {10, 15, 20, 25, 30, 35, 40, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
        cout<<"The Size of this Array is: "<<size;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}




//Q2
#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    int count = 0;
    cout << "Key " << key << " found at indices: ";

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << i << " ";
            count++;
        }
    }

    if (count == 0) {
        cout << "Key not found in the array.";
    } else {
        cout << "\nTotal number of times repeated : " << count;
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 5, 8, 8, 12, 16, 23, 23, 100, 38, 56, 72, 91, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the key to search: ";
    cin >> key;

    linearSearch(arr, n, key);

    return 0;
}