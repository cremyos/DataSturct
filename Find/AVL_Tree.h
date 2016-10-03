#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/**
 * AVL Tree
 */
typedef struct AVLBiTNode
{
	int data;								///< data
	int high;								///< The tree high
	struct AVLBiTNode *lchild, *rchild;		///< left and right child
}AVLBiTNode, *AVLBiTree;

class CAVLBiTree
{
 public:
	AVLBiTree AVL_T;

	CAVLBiTree(){};
	~CAVLBiTree(){};
	/**
	 * AVL Tree
	 * param key 关键字
	 * 
	 */
	void R_Rotate(AVLBiTree &AVL_T);									///< Turn right 
	void L_Rotate(AVLBiTree &AVL_T);									///< Turn left
	void LR_Rotate(AVLBiTree &AVL_T); 									///< Left Right tree
	void RL_Rotate(AVLBiTree &AVL_T);									///< Right Left tree
	void Create_AVL(AVLBiTree &AVL_T, int x);							///< Create the AVL Tree
	int GetHigh(AVLBiTree &AVL_T);										///< Get the high of the tree
	int max(int a, int b);												///< Return the max number
	void AVL_PreTraverse(AVLBiTree &AVL_T);								///Visit the Tree
};

#endif
