//
//  main.cpp
//  SortAlgorithm
//
//  Created by Wang Chengwen on 13-6-2.
//  Copyright (c) 2013年 user. All rights reserved.
//

#include <iostream>
#include <windows.h>

#define ArrayLen	0x7fff


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



int partition(int *a, int start, int end)
{
	int x = a[end];
	int i = start-1;
	int j=start;
	for (int j = start; j < end; j++)
	{
		if (a[j] < x)
		{
			i++;
			exch(a[i], a[j]);
		}
	}
	exch(a[i+1], a[end]);

	return i+1;
}
void quickSort(int *a, int start, int end)
{
	if (start < end)
	{
		int p = partition(a, start, end);
		quickSort(a, start, p-1);
		quickSort(a, p+1, end);
	}
}


void printArray(int *a, int length, string prefix)
{
    cout << prefix.c_str();
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

void generateRandArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}
int main(int argc, const char * argv[])
{
    
    // insert code here...
    int *array = new int[ArrayLen];
	int startClock, endClock;

    generateRandArray(array, ArrayLen);
	startClock = GetTickCount();
    selectionSort(array, ArrayLen);
    endClock = GetTickCount();
	cout << "Selection Sort Time: " << endClock - startClock << endl;


	generateRandArray(array, ArrayLen);
	startClock = GetTickCount();
    insertionSort(array, ArrayLen);
    endClock = GetTickCount();
	cout << "Insertion Sort Time: " << endClock - startClock << endl;
    
	generateRandArray(array, ArrayLen);
	startClock = GetTickCount();
    bubbleSort(array, ArrayLen);
    endClock = GetTickCount();
	cout << "Bubble Sort Time: " << endClock - startClock << endl;
    
	generateRandArray(array, ArrayLen);
	startClock = GetTickCount();
    shellSort(array, ArrayLen);
    endClock = GetTickCount();
	cout << "Shell Sort Time: " << endClock - startClock << endl;

	generateRandArray(array, ArrayLen);
	startClock = GetTickCount();
    quickSort(array, 0, ArrayLen-1);
	endClock = GetTickCount();
	cout << "Quick Sort Time: " << endClock - startClock << endl;

	system("pause");
    return 0;
}

