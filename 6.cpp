#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

// Deterministic Quick Sort
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pivot - 1);
        deterministicQuickSort(arr, pivot + 1, high);
    }
}

// Randomized Quick Sort
int randomizedPartition(vector<int>& arr, int low, int high) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    int randomPivot = dis(gen);
    
    swap(arr[randomPivot], arr[low]);
    
    return deterministicPartition(arr, low, high);
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10000);
    
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    vector<int> arrDeterministic = arr; // Copy of the original array
    vector<int> arrRandomized = arr;    // Copy of the original array

    // Measure time for deterministic Quick Sort
    auto start = chrono::high_resolution_clock::now();
    deterministicQuickSort(arrDeterministic, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedSeconds = end - start;
    cout << "Time taken by deterministic Quick Sort: " << elapsedSeconds.count() << " seconds" << endl;

    // Measure time for randomized Quick Sort
    start = chrono::high_resolution_clock::now();
    randomizedQuickSort(arrRandomized, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsedSeconds = end - start;
    cout << "Time taken by randomized Quick Sort: " << elapsedSeconds.count() << " seconds" << endl;

    return 0;
}

