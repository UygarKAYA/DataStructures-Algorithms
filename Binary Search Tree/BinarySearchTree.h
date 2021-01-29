#ifndef _BinarySearchTree_
#define _BinarySearchTree_

#include "BinaryTreeNode.h"

class BinarySearchTree 
{
	public:
		BinarySearchTree(); 
		~BinarySearchTree();
		void insert(int); 
		void remove(int);
		void printPreorder(); 
		void printInorder(); 
		void printPostOrder(); 
	private:
		BinaryTreeNode *root;
		void insert(int, BinaryTreeNode * & n); 
		void remove(int, BinaryTreeNode * & n);
		void traversePreorder(BinaryTreeNode * n); 
		void traverseInorder(BinaryTreeNode * n); 
		void traversePostorder(BinaryTreeNode * n); 
		void deleteNodes(BinaryTreeNode * & n);
		BinaryTreeNode* findMinValue(BinaryTreeNode* n);
};

#endif 