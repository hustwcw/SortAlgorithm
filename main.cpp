//
//  main.cpp
//  SortAlgorithm
//
//  Created by Wang Chengwen on 13-6-2.
//  Copyright (c) 2013年 user. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <stack>
#include <cstdlib>

#define ArrayLen	0xfffff


using namespace std;


typedef struct tagListNode
{
	int value;
	struct tagListNode *next;
}ListNode;

inline void exch(int &a, int &b)
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

void merge(int *a, int *copy, int q, int len)
{
    if (len < 2) {
        return;
    }
    
    for (int i = 0; i < len; i++) {
        copy[i] = a[i];
    }

    int i = 0;
    int j = q;
    int k = 0;
    while (i < q && j < len)
    {
        if (copy[i] > copy[j]) {
            a[k++] = copy[j++];
        }
        else
        {
            a[k++] = copy[i++];
        }
    }

    while (i < q)
    {
        a[k++] = copy[i++];
    }
    while (j < len)
    {
        a[k++] = copy[j++];
    }
}
// 归并排序
void mergeSort(int *a, int *copy, int len)
{
    if (a == NULL || len < 2) {
        return;
    }

    int q = (len >> 1);
    mergeSort(a, copy, q);
    mergeSort(a+q, copy+q, len-q);
    merge(a, copy, q, len);
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

void quickSort1(int *a, int start, int end)
{
    int x = a[end];
    int i = start-1;
    for (int j = start; j < end; j++)
    {
        if (a[j] < x)
        {
            i++;
            exch(a[i], a[j]);
        }
    }
    exch(a[i+1], a[end]);
    if (start < i)
    {
        quickSort1(a, start, i);
    }
    if (i+2 < end)
    {
        quickSort1(a, i+2, end);
    }
}

void quickSort2(int *a, int size)
{
	stack<int> paraStack;
	paraStack.push(0);
	paraStack.push(size-1);

	while (!paraStack.empty()) 
	{
		int end = paraStack.top();
		paraStack.pop();
		int start = paraStack.top();
		paraStack.pop();

			int x = a[end];
			int i = start-1;
			for (int j = start; j < end; j++)
			{
				if (a[j] < x)
				{
					i++;
					exch(a[i], a[j]);
				}
			}
			exch(a[i+1], a[end]);
			if (start < i)
			{
				paraStack.push(start);
				paraStack.push(i);
			}
			if (i+2 < end)
			{
				paraStack.push(i+2);
				paraStack.push(end);
			}
	}
}


void quickSort3(int *a, int size)
{
	int mystack[100];
	int top=-1;
	mystack[++top] = 0;
	mystack[++top] = size-1;

	while (top>0)
	{
		int end = mystack[top--];
		int start = mystack[top--];

		int x = a[end];
		int i = start-1;
		for (int j = start; j < end; j++)
		{
			if (a[j] < x)
			{
				i++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				//exch(a[i], a[j]);
			}
		}
		int temp = a[i+1];
		a[i+1] = a[end];
		a[end] = temp;
		//exch(a[i+1], a[end]);
		if (start < i)
		{
			mystack[++top]=start;
			mystack[++top]=i;
		}
		if (i+2 < end)
		{
			mystack[++top] = i+2;
			mystack[++top] = end;
		}
	}
}


void tailRecursiveQuickSort(int *a, int start, int end)
{
    while (start < end)
    {
        int x = a[end];
        int i = start-1;
        for (int j = start; j < end; j++)
        {
            if (a[j] < x)
            {
                i++;
                exch(a[i], a[j]);
            }
        }
        exch(a[i+1], a[end]);
        if (start < i)
        {
            tailRecursiveQuickSort(a, start, i);
        }
        start = i+2;
    }
}



// quick sort for single link list
// head: first node
// tail: last node
void quickSort(ListNode **head, ListNode **tail)
{
	ListNode *pj = (*head)->next;
	// 遍历链表进行划分
	ListNode *head1 = NULL, *head2 = NULL;
	ListNode *tail1 = NULL, *tail2 = NULL;

	while (pj != NULL)
	{
		(*head)->next = pj->next;
		if (pj->value < (*head)->value)
		{
			if (head1 != NULL)
			{
				tail1->next = pj;
			}
			else
			{
				head1 = pj;
			}
			tail1 = pj;
		}
		else
		{
			if (head2 != NULL)
			{
				tail2->next = pj;
			}
			else
			{
				head2 = pj;
			}
			tail2 = pj;
		}

		pj = (*head)->next;
	}
	// 设置两个尾节点的next为NULL
	if (tail1 != NULL)
	{
		tail1->next = NULL;
	}
	if (tail2 != NULL)
	{
		tail2->next = NULL;
	}

	if (head1 != tail1)
	{
		quickSort(&head1, &tail1);
	}
	if (head2 != tail2)
	{
		quickSort(&head2, &tail2);
	}

	if (head1 != NULL)
	{
		tail1->next = *head;
		(*head)->next = head2;
		if (head2 != NULL)
		{
			*tail = tail2;
		}
		else
		{
			*tail = *head;
		}
		*head = head1;
	}
	else
	{
		(*head)->next = head2;
		*tail = tail2;
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
	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		array[i] = rand()+rand();
	}
}

void generateRandSingleLinkList(ListNode **head, int size)
{
	*head = NULL;
	ListNode *tail = *head;
	while (size > 0)
	{
		ListNode *p = new ListNode;
		p->next = NULL;
		p->value = rand() + rand();
		if (tail != NULL)
		{
			tail->next = p;
			tail = p;
		}
		else
		{
			(*head) = p;
			tail = p;
		}
		--size;
	}
}


void partition(ListNode** head, ListNode** tail)
{
	if(*head == *tail)return;

	ListNode *small_head = NULL, *small_tail = NULL, *big_head = NULL, *big_tail = NULL, *tp = NULL;
	ListNode **cur = &((*head)->next);
	ListNode *end = (*tail)->next;

	small_tail = small_head = NULL;
	while(*cur != end)
	{
		if((*cur)->value >= (*head)->value)
		{
			big_tail = *cur;
			cur = &((*cur)->next);
		}
		else{
			tp = *cur;
			*cur = (*cur)->next;
			if(small_head == NULL)
			{
				small_head = small_tail = tp;
				tp->next = NULL;
			}else
			{
				small_tail->next = tp;
				tp->next = NULL;
			}
		}
	}
	small_tail->next = *head;
	big_head = (*head)->next;

//注意这一段不能忘记，重新设置head和tail
	*head = small_head;
	*tail = big_tail;

	partition(head, &small_tail);
	partition(&big_head, tail);
}



void TestQuickSortForSingleLinkList()
{
	ListNode *head, *tail;
	generateRandSingleLinkList(&head, ArrayLen);
	//ListNode *p = head;
	//while (p->next->next != NULL)
	//{
	//	p = p->next;
	//}
	//tail = p->next;
	clock_t startClock, endClock;
	startClock = clock();
	quickSort(&head, &tail);
	endClock = clock();
	cout << "Quick Sort For Single Link List:\t" << endClock - startClock << endl;
	//ListNode *p = head;
	//int i = 0;
	//while (p != NULL)
	//{
	//	cout << ++i << ":\t" << p->value << endl;
	//	p = p->next;
	//}
}


void TestInsertionSort()
{
    int *array = new int[ArrayLen];
    clock_t startClock, endClock;
	generateRandArray(array, ArrayLen);
	startClock = clock();
    insertionSort(array, ArrayLen);
    endClock = clock();
	cout << "Insertion Sort Time: " << endClock - startClock << endl;
}


void TestSelectionSort()
{
    int *array = new int[ArrayLen];
    clock_t startClock, endClock;
    generateRandArray(array, ArrayLen);
	startClock = clock();
    selectionSort(array, ArrayLen);
    endClock = clock();
	cout << "Selection Sort Time: " << endClock - startClock << endl;
}


void TestBubbleSort()
{
    int *array = new int[ArrayLen];
    clock_t startClock, endClock;
	generateRandArray(array, ArrayLen);
	startClock = clock();
    bubbleSort(array, ArrayLen);
    endClock = clock();
	cout << "Bubble Sort Time: " << endClock - startClock << endl;
}


void TestShellSort()
{
    int *array = new int[ArrayLen];
    clock_t startClock, endClock;
	generateRandArray(array, ArrayLen);
	startClock = clock();
    shellSort(array, ArrayLen);
    endClock = clock();
	cout << "Shell Sort Time: " << endClock - startClock << endl;
}


void TestMergeSort()
{
    int *array = new int[ArrayLen];
    int *copy = new int[ArrayLen];

    generateRandArray(array, ArrayLen);
    clock_t startClock = clock();
    mergeSort(array, copy, ArrayLen);
    clock_t endClock = clock();
    cout << "Merge Sort Time: " << endClock - startClock << endl;
}

void TestQuickSort()
{
    int *array = new int[ArrayLen];
    clock_t startClock, endClock;
	generateRandArray(array, ArrayLen);
	startClock = clock();
    quickSort(array, 0, ArrayLen-1);
	endClock = clock();
	cout << "Quick Sort Time: " << endClock - startClock << endl;
}


int main(int argc, const char * argv[])
{
	// TestQuickSortForSingleLinkList();
    // TestSelectionSort();
    // TestInsertionSort();
    // TestBubbleSort();
    TestShellSort();
    TestMergeSort();
    TestQuickSort();
	//system("pause");
	return 0;

    int *array = new int[ArrayLen];
	clock_t startClock, endClock;
	generateRandArray(array, ArrayLen);
	startClock = clock();
    quickSort1(array, 0, ArrayLen-1);
	endClock = clock();
	cout << "Quick Sort1 Time: " << endClock - startClock << endl;


	generateRandArray(array, ArrayLen);
	startClock = clock();
    quickSort2(array, ArrayLen);
	endClock = clock();
	cout << "No Recursive Quick Sort Time(stl stack): " << endClock - startClock << endl;

	generateRandArray(array, ArrayLen);
	startClock = clock();
    quickSort3(array, ArrayLen);
	endClock = clock();
	cout << "No Recursive Quick Sort Time(custom stack): " << endClock - startClock << endl;

    
    generateRandArray(array, ArrayLen);
	startClock = clock();
    tailRecursiveQuickSort(array, 0, ArrayLen-1);
	endClock = clock();
	cout << "Tail Recursive Quick Sort: " << endClock - startClock << endl;
    
    
    return 0;
}

