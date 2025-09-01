#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace SortingAlgorithms {

void bubbleSort(int arr[], int n) {
    bool sorted = false;
    int counter = 0;

    do {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temporal = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temporal;
            }
        }
        counter++;
        if (counter == n - 1) {
            sorted = true;
        }
        
    } while (!sorted);
    
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++){
        int min = i;
        
        for (int j = i+1; j < n; j++){
            if (arr[min] > arr[j]) min = j;
        }
        
        int temporal = arr[i];
        arr[i] = arr[min];
        arr[min] = temporal;
    }
    
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++){
    int j = i;
        
        while (arr[j-1]>arr[j] && j > 0){
            int temporal = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temporal;
            j--;
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arrA[n1], arrB[n2];

    for (int n = 0; n < n1; n++) arrA[n] = arr[left + n];
    for (int m = 0; m < n2; m++) arrB[m] = arr[mid + 1 + m];
    
    int p1 = 0, p2 = 0, idx = left;
    while (p1 < n1 && p2 < n2){
        
        if (arrA[p1] < arrB[p2]){
            arr[idx++] = arrA[p1++];
        } 
        
        else {
            arr[idx++] = arrB[p2++];
        }
    }
    
    while (p1 < n1) arr[idx++] = arrA[p1++];
    while (p2 < n2) arr[idx++] = arrB[p2++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    do {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i < j){
            int temporal = arr[j];
            arr[j] = arr[i]; 
            arr[i] = temporal;
        }
        
    } while (i < j);
    
    int temporal = arr[low];
    arr[low] = arr[j]; 
    arr[j] = temporal;
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quickSort(arr, low, j - 1);   
        quickSort(arr, j + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    
}

void heapSort(int arr[], int n) {
    
}

void printArray(int arr[], int n) {
    if (n == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void SortingTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void SortingTimer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}

double SortingTimer::getElapsedMilliseconds() const {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count() / 1000.0;
}

std::string SortingTimer::getElapsedTime() const {
    double ms = getElapsedMilliseconds();
    std::stringstream ss;
    
    if (ms < 1.0) {
        ss << std::fixed << std::setprecision(3) << (ms * 1000) << " microseconds";
    } else if (ms < 1000.0) {
        ss << std::fixed << std::setprecision(3) << ms << " ms";
    } else {
        ss << std::fixed << std::setprecision(3) << (ms / 1000.0) << " seconds";
    }
    
    return ss.str();
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr = generateSortedArray(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    for (int i = 0; i < swaps && i < size/2; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

}