#include <iostream>
using namespace std;


void selectionSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;


        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }


        swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    selectionSortDescending(arr, size);


    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



//Q2
#include <iostream>
using namespace std;


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int size;


    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];


    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    bubbleSort(arr, size);


    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




//Q3
#include <iostream>
using namespace std;


void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int size;


    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];


    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    bubbleSortDescending(arr, size);


    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




//Q4

#include <iostream>
using namespace std;


void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];  
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

int main() {
    int size;


    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];


    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    insertionSort(arr, size);


    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




//Q5

#include <iostream>
using namespace std;


void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];  
        int j = i - 1;


        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

int main() {
    int size;


    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];


    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    insertionSortDescending(arr, size);


    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
 88 changes: 88 additions & 0 deletions88  
Lab12Q1.cpp
