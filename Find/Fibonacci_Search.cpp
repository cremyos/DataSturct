/*
 ************************************************
 * Name : Fibonacci_Search.c
 * Date : 2016-07-03
 * Author : Lniper
 * Aim : Fibonacci Search.
 ************************************************
 */
#include "Search.h"

int F[20] = {0};

/**
 * Create the Fabonacci array
 */
void Fabonacci(int F[])
{
	int x,y,i,sum;
	
	x=1,y=1;
	F[0] = F[1] = x;
	for(i=2;i<20;i++) {
		sum=x+y;
		F[i] = sum;
		x=y;
		y=sum;
	}
	
	for(i = 0; i < 20; i++) {
		cout<<"Fibonacci "<<i<<" : "<<F[i]<<endl;
	}
}

int CSearch::Fibonacci_Search(int n, int key)
{
	int low, high, mid, i, k;
	
	low = 0;
	high = n;
	k = 0;
	Fabonacci(F);
	
	while(n > F[k] - 1)
		k++;
	for(i = n; i < F[k] - 1; i++)
		array[i] = array[n];
		
	while(low <= high) {
		cout<<"line"<<__LINE__<<": k = "<<k<<" || element = "<<F[k-1]<<endl;
		mid = low  + F[k - 1] - 1;
		cout<<"mid = "<<mid<<endl;
		if (key < array[mid]) {
			high = mid - 1;
			k -= 1;
		}else if(key > array[mid]) {
			low = mid + 1;
			cout<<"low = "<<low<<endl;
			k -= 2;
		}else {
			if (mid <= n)
				return mid;
			else 
				return n;
		}
	}
	return 0;
}

int main(void)
{
	CSearch find1;
	
	cout<<"Binary Search: ";
	if(find1.Fibonacci_Search(MAXSIZE, 10))
		printf("position = %d\n", find1.Fibonacci_Search(MAXSIZE-1, 12));
	else 
		printf("Can't find the element");
		
	return 0;
}