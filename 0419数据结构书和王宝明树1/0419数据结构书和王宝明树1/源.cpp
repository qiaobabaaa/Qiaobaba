#include "Tree.h"
//中序遍历
BiNode *GoFarLeft(BiNode *T, stack<BiNode*>&s)
{
	if (T == NULL){
		return NULL;
	}
	while (T->lchild){
		s.push(T);//将T(根节点)入栈
		T = T->lchild;//如果T的子节点还有lchild继续while里的步骤
	}
	return T;
}
 
void InOrder2(BiNode *T)
{
	stack<BiNode*>s;
	//步骤1:一直左走找到中序遍历的起点t的地址
	BiTree t = GoFarLeft(T, s); 
	while (t){
		cout << "中序遍历的起点:" << t->data << endl;
		//如果t节点有右子树重复步骤1
		if (t->rchild != NULL){
			t = GoFarLeft(t->rchild, s);
		}
		//如果t没有右子树,根据栈顶指示,访问栈顶元素
		else if (!s.empty()){
			t = s.top();
			s.pop();
		}
		//如果t没有右子树,并且栈为空
		else
		{
			t = NULL;
		}
	}

}
void main()
{
	BiTree p1, p2, p3, p4, p5;
	p1 = new BiNode;
	p2 = new BiNode;
	p3 = new BiNode;
	p4 = new BiNode;
	p5 = new BiNode;
	
	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;

	p1->lchild = p2;
	p2->lchild = p4;
	p1->rchild = p3;
	p3->lchild = p5;

	BiNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//建立树关系 t1左孩子
	t1.lchild = &t2;
	//t1右孩子
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	InOrder2(&t1);

	system("pause");
}