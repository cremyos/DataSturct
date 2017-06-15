/*
 ************************************************
 * Name : AVL_tree.cpp
 * Date : 2016-10-03
 * Author : Lniper
 * Aim : AVL Tree Search.
 ************************************************
 */
#include "AVL_Tree.h"

/**
 * Get the high of tree
 */
int CAVLBiTree::GetHigh(AVLBiTree &AVL_T)
{
	return AVL_T == NULL? -1 : AVL_T->high;
}

/**
 * Return the max number 
 */
int CAVLBiTree::max(int a, int b)
{
	return a>b?a:b;
}

/**
 * Turn Right. The graph from A change to B.
 *     *			     *
 *    *    change to   *   *
 *   *
 *    A                  B
 */
void CAVLBiTree::L_Rotate(AVLBiTree &AVL_T)
{
	AVLBiTree p;
	p = new AVLBiTNode;
	p = AVL_T->lchild;
	AVL_T->lchild = p->rchild;
	p->rchild = AVL_T;

	AVL_T->high = max(GetHigh(AVL_T->lchild), GetHigh(AVL_T->rchild)) + 1;
	p->high = max(GetHigh(p->lchild), GetHigh(AVL_T)) + 1;
	AVL_T = p;
	
}

/**
 * Turn Left. The graph from A change to B.
 *   *	      		     *
 *    *    change to   *   *
 *     *
 *    A                  B
 */
void CAVLBiTree::R_Rotate(AVLBiTree &AVL_T)
{
  	AVLBiTree p;
	p = new AVLBiTNode;
	p = AVL_T->rchild;
	AVL_T->rchild = p->lchild;
	p->lchild = AVL_T;

	AVL_T->high = max(GetHigh(AVL_T->lchild), GetHigh(AVL_T->rchild)) + 1;
	p->high = max(GetHigh(p->lchild), GetHigh(AVL_T)) + 1;
	
	AVL_T = p;
}

/**
 * Turn Right then turn Left. The graph from A change to B.
 *       *            *            *
 *     *    ---->   *    ------> *   *
 *       *        *
 *      A 						   B
 */	
void CAVLBiTree::LR_Rotate(AVLBiTree &AVL_T)
{
	R_Rotate(AVL_T->lchild);
	L_Rotate(AVL_T);
}

/**
 * Turn Left then turn Right. The graph from A change to B.
 *     *            *                *
 *       *  ----->    *    ------> *   *
 *     *                *
 *     A                             B
 */
void CAVLBiTree::RL_Rotate(AVLBiTree &AVL_T)
{
	L_Rotate(AVL_T->rchild);
	R_Rotate(AVL_T);
}


/**
 * Create the AVL Tree
 */
void CAVLBiTree::Create_AVL(AVLBiTree &AVL_T, int x)
{
	if(AVL_T == NULL) {
	  AVL_T = new AVLBiTNode;
	  AVL_T->data = x;
	  AVL_T->lchild = NULL;
	  AVL_T->rchild = NULL;
	  AVL_T->high = 0;
	  return ;
	}else if(AVL_T->data > x) {
		Create_AVL(AVL_T->lchild, x);

		if(2 == GetHigh(AVL_T->lchild) - GetHigh(AVL_T->rchild)) {
			if(x < AVL_T->lchild->data) {
				L_Rotate(AVL_T);
			} else {
				LR_Rotate(AVL_T);
			}
		}
   	}else if(AVL_T->data < x) {
		Create_AVL(AVL_T->rchild, x);

		if(2 == GetHigh(AVL_T->rchild) - GetHigh(AVL_T->lchild)) {
			if(x > AVL_T->rchild->data) {
				R_Rotate(AVL_T);
			} else {
				RL_Rotate(AVL_T);
			}
		}
	}

	AVL_T->high = max(GetHigh(AVL_T->lchild), GetHigh(AVL_T->rchild))+1;
}

/**
 * Pre Traverl the AVL tree.
 */
void CAVLBiTree::AVL_PreTraverse(AVLBiTree &AVL_T)
{
	if(AVL_T == NULL) {
		return ;
	}

	cout<<"AVL_T->data = "<<AVL_T->data<<" "<<endl;//<<" || AVL_T->high = "<<AVL_T->high<<endl;
	AVL_PreTraverse(AVL_T->lchild);
	AVL_PreTraverse(AVL_T->rchild);
}

/**
 * Delete the AVL Tree node
 */
void CAVLBiTree::DeleteAVL_Node(AVLBiTree &AVL_T, int x)
{
	if(AVL_T == NULL)
		return ;

	if(x < AVL_T->data) {
		DeleteAVL_Node(AVL_T->lchild, x);

		if(2 == GetHigh(AVL_T->rchild) - GetHigh(AVL_T->lchild)) {
			if(AVL_T->rchild->lchild && GetHigh(AVL_T->rchild->lchild) > GetHigh(AVL_T->rchild->rchild))
				RL_Rotate(AVL_T);
			else
				R_Rotate(AVL_T);
		}
	} else if(x > AVL_T->data) {
		DeleteAVL_Node(AVL_T->rchild, x);

		if(2 == GetHigh(AVL_T->lchild) - GetHigh(AVL_T->rchild)) {
			if(AVL_T->lchild->rchild && GetHigh(AVL_T->lchild->rchild) > GetHigh(AVL_T->lchild->lchild))
				LR_Rotate(AVL_T);
			else
				L_Rotate(AVL_T);
		}
	} else {
		if(AVL_T->lchild && AVL_T->rchild) {
			AVLBiTree p;

			p = AVL_T->rchild;
			while(p->lchild != NULL)
				p = p->lchild;
			AVL_T->data = p->data;
			DeleteAVL_Node(AVL_T->rchild, p->data);
			if(2 == GetHigh(AVL_T->lchild) - GetHigh(AVL_T->rchild)) {
				if(AVL_T->lchild->rchild && GetHigh(AVL_T->lchild->rchild) > GetHigh(AVL_T->lchild->lchild))
					LR_Rotate(AVL_T);
				else
					L_Rotate(AVL_T);
			}
		} else {
			AVLBiTree p;

			p = AVL_T;
			if(AVL_T->lchild == NULL)
				AVL_T = AVL_T->rchild;
			else if(AVL_T->rchild == NULL)
				AVL_T = AVL_T->lchild;

			delete p;
		}
	}

	if(AVL_T)
		AVL_T->high = max(GetHigh(AVL_T->lchild), GetHigh(AVL_T->rchild)) + 1;
		
}

int main()
{
	int number[6] = {13, 24, 37, 48, 53, 90};//{3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
	int i = 0;
	CAVLBiTree cav1;
	AVLBiTree AVL_T;

	AVL_T = new AVLBiTNode;
	AVL_T->data = number[0];
	AVL_T->lchild = NULL;
	AVL_T->rchild = NULL;
	AVL_T->high = 0;
	
	for(i = 1; i < 6; i++) {
		cout<<"i = "<<i<<endl;
		cav1.Create_AVL(AVL_T, number[i]);
		cav1.AVL_PreTraverse(AVL_T);
	}
	cout<<endl;
	
#if 0
	cout<<"Delete the 8 Node: "<<endl;
	cav1.DeleteAVL_Node(AVL_T, 8);
	cav1.AVL_PreTraverse(AVL_T);
	cout<<endl;

	cout<<"Insert the 8 Node: "<<endl;
	cav1.Create_AVL(AVL_T, 8);
	cav1.AVL_PreTraverse(AVL_T);
	cout<<endl;
	
	cout<<"Delete the 9 Node: "<<endl;
	cav1.DeleteAVL_Node(AVL_T, 9);
	cav1.AVL_PreTraverse(AVL_T);
	cout<<endl;

	cout<<"Insert the 9 Node: "<<endl;
	cav1.Create_AVL(AVL_T, 9);
	cav1.AVL_PreTraverse(AVL_T);
	cout<<endl;
	
	cout<<"Delete the 7 Node: "<<endl;
	cav1.DeleteAVL_Node(AVL_T, 7);
	cav1.AVL_PreTraverse(AVL_T);
	cout<<endl;
#endif

	cout<<"Delete the 48: "<<endl;
	cav1.DeleteAVL_Node(AVL_T, 48);
	cav1.AVL_PreTraverse(AVL_T);
	cout<<endl;

	return 0;
}
     
