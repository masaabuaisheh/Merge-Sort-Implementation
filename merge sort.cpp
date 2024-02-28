#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays
void merge(vector<int>& A, int p, int q, int r) {
    int n1 = q - p + 1; // Size of the left subarray
    int n2 = r - q;     // Size of the right subarray

    vector<int> Larray(n1); // Temporary array to hold the left subarray
    vector<int> Rarray(n2); // Temporary array to hold the right subarray

    // Copy data to temporary arrays Larray[] and Rarray[]
    for (int i = 0; i < n1; i++) {
        Larray[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        Rarray[j] = A[q + j + 1];
    }

    // Merge the two sorted subarrays back into arr[p..r]
    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (Larray[i] <= Rarray[j]) {
            A[k] = Larray[i]; // Copy from left subarray
            i++;
        }
        else {
            A[k] = Rarray[j]; // Copy from right subarray
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        A[k] = Larray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        A[k] = Rarray[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        // Calculate the middle index
        int q = (p + r) / 2;

        // Recursively sort the left and right subarrays
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        // Merge the sorted subarrays
        merge(arr, p, q, r);
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
