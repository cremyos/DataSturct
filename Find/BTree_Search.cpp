/*
 ************************************************
 * Name : BTree_Search.c
 * Date : 2016-07-12
 * Author : Lniper
 * Aim : BTree Search.
 ************************************************
 */
#include "Search.h"

int CSearch::BTree_Search(BiTree T, int key)
{
	if(T == NULL){
		return FALSE;
	}else if(key == T->data) {
		return TRUE;
	}
	else if(key < T ->data) {
		return BTree_Search(T->lchild, key);
	}else {
		return BTree_Search(T->rchild, key);
	}
}

void CSearch::BTree_Insert(BiTree &T, int key)
{
	if(T == NULL) {
		T = new BiTNode;
		T->data = key;
		T->lchild = T->rchild = NULL;
	}
	else if(key < T->data){
		BTree_Insert(T->lchild, key);
	}else {
		BTree_Insert(T->rchild, key);
	}
	
}

void CSearch::PreTraverse(BiTree T)
{
	if(T == NULL)
		return ;
	cout<<"T->data = "<<T->data<<" "<<endl;
	PreTraverse(T->lchild);
	PreTraverse(T->rchild);
}

int CSearch::DeleteBST(BiTree &T, int key)
{
	if(!T) {
		return FALSE;
	}else {
		if(key == T->data) {
			return Delete(T);
		}else if(key < T->data) {
			return DeleteBST(T->lchild, key);
		}else {
			return DeleteBST(T->rchild, key);
		}
	}
}

int CSearch::Delete(BiTree &T)
{
	BiTree q, s;
	q = new BiTNode;
	s = new BiTNode;
	
	if(q->rchild == NULL) {
		/**
		 * Right child is NULL. Make the left child joint to the node.
 		 */
		q = T;
		T = T->rchild;
		delete q;
	}else if(T->lchild == NULL) {
		/**
		 * Left child is NULL. Make the Right child joint to the node.
 		 */
		q = T;
		T = T->rchild;
		delete q;
	}else {
		/**
		 * Right and left child are not NULL
 		 */
		q = T;
		s = T->lchild;
		while(T->rchild) {
			/**
			 * Turn left, and go to the right.
			 */
			q = s;
			s = s->rchild;
		}
		/**
		 * s point to the delete node father node.
		 */
		 if(q != T) {
		 	/**
		 	 * rejoint the right tree.
			 */
 			q->rchild = s->lchild;
 		}else {
 			/**
 			 * rejoint the left tree.
 			 */
		 	q->lchild = s->lchild;
		 }
		 delete s;
	}
	
	return TRUE;
}

int main(void)
{
	CSearch find1;
	int i;
	
	int array_BiTree[] = {MAXSIZE_BT-1, 4, 5, 2, 1, 0, 9, 3, 7, 6, 8};
	
	find1.T = new BiTNode;
	find1.T = NULL;	
	
	for(i = 1; i < MAXSIZE_BT; i++) {
		cout<<"array_BiTree [ "<<i<<" ] = "<<array_BiTree[i]<<endl;
		find1.BTree_Insert(find1.T, array_BiTree[i]);		
	}
	
	/**
	 * Visit the BiTree
	 */
	find1.PreTraverse(find1.T);
	
	cout<<"Binary Tree Search: "<<endl;
	if(find1.BTree_Search(find1.T, 5))
		printf("Find the element\n");
	else 
		printf("Can't find the element\n");
	
	cout<<"Delete the Tree"<<endl;
	find1.DeleteBST(find1.T, 6);
	find1.PreTraverse(find1.T);
	
	
	return 0;
}
