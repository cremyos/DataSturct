/**
 * Name : HeapSort.cpp
 * Author : Lniper
 * Date : 2016-10-07
 * Aim : Heap Sort
 */

#include "Sort.h"

/**
 * Adjust heap sort in maxdown 
 */
Status CSort::HeapSortMIN_Down(int *array, int len, int CNode)
{
	int lChild = 0, rChild = 0, largest = 0;

	lChild = 2*CNode + 1;
	rChild = 2*CNode + 2;
	largest = CNode;
	
	if(lChild < len && array[lChild] > array[CNode])
		largest = lChild;

	if(rChild < len && array[rChild] > array[largest])
		largest = rChild;
	
	if(largest != CNode) {
		Swap(array+largest, array+CNode);
		HeapSortMIN_Down(array, len, largest);
	}	
}

/**
 * Heap max down 
 */
Status CSort::HeapMIN(int *array, int len)
{
	int i = 0;

	for(i = MAXSIZE/2 - 1; i >= 0; i--)
		HeapSortMIN_Down(array, len, i);
}

/**
 * Create the Heap in max down
 */
Status CSort::CreateHeapMIN(int *array, int len)
{
	int  i = 0;


	/**
	 * Adjust the Heap, make the every non-leaf node big than sons.
	 */
	HeapMIN(array, len);
	cout<<"LINE "<<__LINE__<<": ";
	Print(array);
	
	for(i = len -1; i >= 1; i--) {
		Swap(array, array+i);
		HeapSortMIN_Down(array, --len, 0);
	}
}

/**
 * Adjust the heap in mindown
 */
Status CSort::HeapSortMAX_Down(int *array, int len, int CNode)
{
	int lChild = 0, rChild = 0, minist = 0;

	lChild = 2*CNode + 1;
	rChild = 2*CNode + 2;
	minist = CNode;
	
	if(lChild < len && array[lChild] < array[CNode])
		minist = lChild;

	if(rChild < len && array[rChild] < array[minist])
		minist = rChild;
	
	if(minist != CNode) {
		Swap(array+minist, array+CNode);
		HeapSortMAX_Down(array, len, minist);
	}	

}

/**
 * Heap in min down
 */
Status CSort::HeapMAX(int *array, int len)
{
	int i = 0;

	for(i = MAXSIZE/2 - 1; i >= 0; i--)
		HeapSortMAX_Down(array, len, i);
}

/**
 * Create the heap in Mindown
 */
Status CSort::CreateHeapMAX(int *array, int len)
{
	int  i = 0;

	/**
	 * Adjust the Heap, make the every non-leaf node big than sons.
	 */
	HeapMAX(array, len);
	cout<<"LINE "<<__LINE__<<": ";
	Print(array);
	
	for(i = len -1; i >= 1; i--) {
		Swap(array, array+i);
		HeapSortMAX_Down(array, --len, 0);
	}

}



int main()
{
	CSort s1;

	cout<<"Before InSequece in MAX: "<<endl;
	s1.Print(s1.array);
	
	cout<<"Heap Sort: "<<endl;
	s1.CreateHeapMIN(s1.array, MAXSIZE);
	s1.Print(s1.array);

	cout<<endl;
	
	cout<<"Before USequence Heap Sort array_temp: "<<endl;
	s1.Print(s1.array_temp);
	
	cout<<"Heap Sort USequence in MAX: "<<endl;
	s1.CreateHeapMIN(s1.array_temp, MAXSIZE);
	s1.Print(s1.array_temp);

	cout<<endl;
	
	cout<<"Before InSequece in MIN: "<<endl;
	s1.Print(s1.array);
	
	cout<<"Heap Sort: "<<endl;
	s1.CreateHeapMAX(s1.array, MAXSIZE);
	s1.Print(s1.array);

	cout<<endl;
	
	cout<<"Before Heap Sort array_temp: "<<endl;
	s1.Print(s1.array_temp);
	
	cout<<"Heap Sort USequence in MIN: "<<endl;
	s1.CreateHeapMAX(s1.array_temp, MAXSIZE);
	s1.Print(s1.array_temp);
	
	return 0;
}
