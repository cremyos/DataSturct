#ifndef SEARCH_H_
#define SEARCH_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 21
#define TRUE 1
#define FALSE 0
#define MAXSIZE_BT	11

typedef int Status;

typedef struct BiTNode
{
	int data;								///< data
	struct BiTNode *lchild, *rchild;		///< left or right child pointer	
}BiTNode, *BiTree;


	
/**
 * CSearch Class
 */
class CSearch{
private:
	int *array;
	
	
public:
	BiTree T, T_backup;

	
	CSearch();
	~CSearch();

	/**
	 * Sequential Search
	 */
	int	Sequential_Search(int n, int key);					///Sequence Search and return the position.
	int	Sequential_Search_Signal(int n, int key);				///Sequence Search with signal.
	/**
	 * Binary Search
  	 */
	int Binary_Search(int n, int key);						///Binary Search 
	/**
	 * Fibonacci Search
	 */
	int Fibonacci_Search(int n, int key);						//Fibonacci Search
	/**
	 * Binary Tree
	 */
	int BTree_Search(BiTree T, int key);						///Binary Tree Search
	void BTree_Insert(BiTree &T, int key);						///Insert the Binary Tree
	void PreTraverse(BiTree T);							///Visit the Tree
	int DeleteBST(BiTree &T, int key);						///Delete the BiTree
	int Delete(BiTree &T);								///Delete the BiTree and joint the right or left tree
	

};

/**
 * construct function
 */
CSearch::CSearch()
{
	int i = 0;
	
	array = new int[MAXSIZE];
	array[0] = MAXSIZE-1;
	for(i = 1; i < MAXSIZE; i++)
		array[i] = i;
}

/**
 * Destruct function
 */
CSearch::~CSearch()
{
	delete array;
	delete T;
}

#endif
