#ifndef TREENODE_H
#define TREENODE_H

#include "KeyedItem.h"
#include "KeyedItemCount.h"

typedef KeyedItem TreeItemType;
typedef KeyedItemCount TreeItemCount;

class TreeNode
{
private:
	TreeNode() { }
	TreeNode(const TreeItemType& nodeItem, const TreeItemCount& nodeItemCount, TreeNode *left = NULL, TreeNode *right = NULL)
		{item = nodeItem; count = nodeItemCount; leftChildPtr = left;  rightChildPtr = right;}
	TreeItemType item;
	TreeItemCount count;
	TreeNode *leftChildPtr, *rightChildPtr;

	friend class BinarySearchTree;
};

#endif