#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree :: BinarySearchTree() { root = NULL; }

void BinarySearchTree :: insert(int element, BinaryTreeNode*& binaryTreeNode)
{
    if (binaryTreeNode == NULL) 
    {
        binaryTreeNode = new BinaryTreeNode(element);
        binaryTreeNode->element = element;
        binaryTreeNode->left = NULL;
        binaryTreeNode->right = NULL; 
    }
    else if (element < binaryTreeNode->element)
        insert(element, binaryTreeNode->left);
    else if (element > binaryTreeNode->element)
        insert (element, binaryTreeNode->right);
    return;
}
void BinarySearchTree :: insert(int element) { insert(element, root); }

BinaryTreeNode* BinarySearchTree :: findMinValue(BinaryTreeNode* binaryTreeNode)
{
    if (binaryTreeNode == NULL)
        std::cout << "\nBinary Search Tree is Empty" << std::endl;
    else if (binaryTreeNode != NULL)
        if (binaryTreeNode->left != NULL)
            return findMinValue(binaryTreeNode->left);
    return binaryTreeNode;
}

void BinarySearchTree :: remove(int element , BinaryTreeNode*& binaryTreeNode)
{
    if (binaryTreeNode == NULL)
        return;
    if (element < binaryTreeNode->element)
        remove(element, binaryTreeNode->left); 
    else if (element > binaryTreeNode-> element)
        remove(element, binaryTreeNode->right);
    else if (binaryTreeNode->left && binaryTreeNode->right) 
        remove(findMinValue(binaryTreeNode->right)->element, binaryTreeNode->right);
    else 
    {
        if (binaryTreeNode->left == NULL)
            binaryTreeNode = binaryTreeNode->right;
        else if (binaryTreeNode->right == NULL)
            binaryTreeNode = binaryTreeNode->left;
        delete binaryTreeNode;   
    }
}
void BinarySearchTree :: remove(int element) { remove(element, root); }

void BinarySearchTree :: traversePreorder(BinaryTreeNode* binaryTreeNode) 
{
    if (root != NULL)
    {
        std::cout << binaryTreeNode->element << " ";
        if (binaryTreeNode->left != NULL)
            traversePreorder(binaryTreeNode->left);
        if (binaryTreeNode->right != NULL)
            traversePreorder(binaryTreeNode->right);
    }
    else 
        return;
}
void BinarySearchTree :: printPreorder() { traversePreorder(root); }

void BinarySearchTree :: traverseInorder(BinaryTreeNode* binaryTreeNode) 
{
    if (root != NULL)
    {
        if (binaryTreeNode->left != NULL)
            traverseInorder(binaryTreeNode->left);
        std::cout << binaryTreeNode->element << " ";
        if (binaryTreeNode->right != NULL)
            traverseInorder(binaryTreeNode->right);
    }
    else 
        return;
}
void BinarySearchTree :: printInorder() { traverseInorder(root); }

void BinarySearchTree :: traversePostorder(BinaryTreeNode* binaryTreeNode) 
{
    if (root != NULL)
    {
        if (binaryTreeNode->left != NULL)
            traversePostorder(binaryTreeNode->left);
        if (binaryTreeNode->right != NULL)
            traversePostorder(binaryTreeNode->right);
        std::cout << binaryTreeNode->element << " ";    
    }
    else 
        return;
}
void BinarySearchTree :: printPostOrder() { traversePostorder(root); }

void BinarySearchTree :: deleteNodes(BinaryTreeNode*& binaryTreeNode)
{
    if (binaryTreeNode != NULL)
    {
        if (binaryTreeNode->left != NULL)
            deleteNodes(binaryTreeNode->left);
        if (binaryTreeNode->right != NULL)
            deleteNodes(binaryTreeNode->right);
        delete binaryTreeNode;        
    }
    else
        std::cout << "\nBinary Search Tree is Empty" << std::endl;
}
BinarySearchTree :: ~BinarySearchTree() { deleteNodes(root); }