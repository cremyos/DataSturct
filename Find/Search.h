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
	int *array_BiTree;
	
public:
	BiTree T, T_backup;
	
	CSearch();
	~CSearch();

	int	Sequential_Search(int n, int key);						///Sequence Search and return the position.
	int	Sequential_Search_Signal(int n, int key);				///Sequence Search with signal.
	int Binary_Search(int n, int key);							///Binary Search 
	int Fibonacci_Search(int n, int key);						//Fibonacci Search
	int BTree_Search(BiTree T, int key);						///Binary Tree Search
	void BTree_Insert(BiTree &T, int key);						///Insert the Binary Tree
	void PreTraverse(BiTree T);									///Visit the Tree
	int DeleteBST(BiTree &T, int key);							///Delete the BiTree
	int Delete(BiTree &T);										///Delete the BiTree and joint the right or left tree
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
		
	array_BiTree = new int[MAXSIZE_BT];
	array_BiTree[0] = MAXSIZE_BT-1;
 
	int array_new[] = {4, 5, 2, 1, 0, 9, 3, 7, 6, 8};
	for(i = 1; i < MAXSIZE_BT; i++)
		array_BiTree[i] = array_new[i-1];
	T = new BiTNode;
	T = NULL;
	
	
	for(i = 1; i < MAXSIZE_BT; i++) {
		cout<<"array_BiTree [ "<<i<<" ] = "<<array_BiTree[i]<<endl;
		BTree_Insert(T, array_BiTree[i]);		
	}
	
	/**
	 * Visit the BiTree
	 */
	PreTraverse(T);

}

/**
 * Destruct function
 */
CSearch::~CSearch()
{
	delete array;
	delete T;
	delete array_BiTree;
}

#endif
