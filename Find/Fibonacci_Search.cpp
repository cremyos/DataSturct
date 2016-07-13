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
	F[1] = F[2] = x;
	for(i=3;i<=20;i++) {
		sum=x+y;
		F[i] = sum;
		x=y;
		y=sum;
	}
}

int CSearch::Fibonacci_Search(int n, int key)
{
	int low, high, mid, i, k;
	
	low = 1;
	high = n;
	k = 0;
	Fabonacci(F);
	
	while(n > F[k] - 1)
		k++;
	for(i = n; i < F[k] - 1; i++)
		array[i] = array[n];
	for(i = 1; i < 21; i++)
		cout<<array[i]<<endl;
		
	while(low <= high) {
		cout<<"line"<<__LINE__<<": k = "<<k<<" || element = "<<F[k-1] - 1<<endl;
		mid = low - 1+F[k-1] - 1;
		cout<<"mid = "<<mid<<endl;
		if (key < array[mid]) {
			high = mid - 1;
			k -= 1;
		}
		else if(key > array[mid]) {
			low = mid + 1;
			k -= 2;
		}
		else {
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
	
	cout<<"Fibonacci Search: ";
	if(find1.Fibonacci_Search(MAXSIZE, 10))
		printf("position = %d\n", find1.Fibonacci_Search(MAXSIZE-1, 10));
	else 
		printf("Can't find the element");
		
	return 0;
}
