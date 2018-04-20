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
};//BiNode, *BiTree;�������д���ȼ�

typedef struct BiNode BiNode;
typedef struct BiNode *BiTree;

// ������
typedef struct TriNode{
	int data;
	TriNode * lchild, *rchild;
	TriNode * parent;
}TriNode, *TreeNode;

//˫������
typedef struct BPTNode{
	int data;
	int parentPosition;//ָ��˫�׵�ָ��//�������±�
	char LRTag;//���Һ��ӱ�־
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];//�ڵ��Ƿ�ɢ�� ���Դ洢��������
	int num_node;//�ڵ���Ŀ 
	int root;//���ڵ��λ��//ע�������洢���Ǹ��׽ڵ���������±�
}BPTree;

void InOrder1();
BiNode *GoFarLeft(BiNode *T, stack<BiNode*>&s);
void InOrder2(BiNode *);
#endif