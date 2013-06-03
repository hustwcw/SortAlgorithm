//
//  main.cpp
//  SortAlgorithm
//
//  Created by Wang Chengwen on 13-6-2.
//  Copyright (c) 2013年 user. All rights reserved.
//

#include <iostream>

using namespace std;

void exch(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *a, int len)
{
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        exch(a[i], a[min]);
    }
}

void insertionSort(int *a, int len)
{
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && a[j] < a[j-1]; j--) {
            exch(a[j], a[j-1]);
        }
    }
}

void bubbleSort(int *a, int len)
{
    for (int i = len; i > 0; i--) {
        for (int j = 0; j < i-1; j++) {
            if (a[j] > a[j+1]) {
                exch(a[j], a[j+1]);
            }
        }
    }
}
void shellSort(int *a, int length)
{
    int h = 1;
    while (h < length/3) {
        h = 3*h + 1;
    }
    
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && a[j] < a[j-h]; j -= h) {
                exch(a[j], a[j-h]);
            }
        }
        h = h/3;
    }
}

void printArray(int *a, int length, string prefix)
{
    cout << prefix;
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main(int argc, const char * argv[])
{
    
    // insert code here...
    int arrayLen = 20;
    int *array = new int[arrayLen];
    for (int i = 0; i < arrayLen; i++) {
        array[i] = rand()/10000000;
    }
    
    printArray(array, arrayLen, "Before Sort:\t\t");
    
    selectionSort(array, arrayLen);
    printArray(array, arrayLen, "Selection Sort:\t");
    
    insertionSort(array, arrayLen);
    printArray(array, arrayLen, "Insertion Sort:\t");
    
    bubbleSort(array, arrayLen);
    printArray(array, arrayLen, "Bubble Sort:\t\t");
    
    shellSort(array, arrayLen);
    printArray(array, arrayLen, "Shell Sort:\t\t");
    return 0;
}

