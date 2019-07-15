#include "stdio.h"
#include <iostream>

void exchange_int(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void adjust_heap(int* arr, int i, int heap_size)
{
	int left = 2*i+1;
	int right = left+1;
	int largest = i;
	if(left < heap_size && arr[left] > arr[largest])
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	
	if (right < heap_size && arr[right] > arr[largest])
	{
		largest = right;
	}
	
	if (largest != i)
	{
		exchange_int(arr[i], arr[largest]);
		adjust_heap(arr, largest, heap_size);
	}
}
int build_heap(int* arr, int length)
{
	for (int i = length/2-1; i >= 0; --i)
	{
		adjust_heap(arr, i, length);
	}
}

void heap_sort(int* arr, int length)
{
	build_heap(arr, length);
	
	for (int i = length-1; i >= 0; --i)
	{
		exchange_int(arr[i], arr[0]);
		adjust_heap(arr, 0, i);
	}
}
void print_array(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        std::cout << arr[i] << " "; 
    std::cout << "\n"; 
} 
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int length = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr, length);
	print_array(arr, length);
}
