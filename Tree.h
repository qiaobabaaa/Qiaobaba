#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include  <stack>
using namespace std;

typedef struct BiNode{
	int data;
	struct BiNode* lchild, *rchild;
};//BiNode, *BiTree;与下面的写法等价

typedef struct BiNode BiNode;
typedef struct BiNode *BiTree;

// 三叉树
typedef struct TriNode{
	int data;
	TriNode * lchild, *rchild;
	TriNode * parent;
}TriNode, *TreeNode;

//双亲链表
typedef struct BPTNode{
	int data;
	int parentPosition;//指向双亲的指针//即数组下标
	char LRTag;//左右孩子标志
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];//节点是分散的 所以存储在数组中
	int num_node;//节点数目 
	int root;//根节点的位置//注意此区域存储的是父亲节点在数组的下标
}BPTree;

void InOrder1();
BiNode *GoFarLeft(BiNode *T, stack<BiNode*>&s);
void InOrder2(BiNode *);
#endif