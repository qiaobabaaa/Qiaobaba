#include "Tree.h"
//�������
BiNode *GoFarLeft(BiNode *T, stack<BiNode*>&s)
{
	if (T == NULL){
		return NULL;
	}
	while (T->lchild){
		s.push(T);//��T(���ڵ�)��ջ
		T = T->lchild;//���T���ӽڵ㻹��lchild����while��Ĳ���
	}
	return T;
}
 
void InOrder2(BiNode *T)
{
	stack<BiNode*>s;
	//����1:һֱ�����ҵ�������������t�ĵ�ַ
	BiTree t = GoFarLeft(T, s); 
	while (t){
		cout << "������������:" << t->data << endl;
		//���t�ڵ����������ظ�����1
		if (t->rchild != NULL){
			t = GoFarLeft(t->rchild, s);
		}
		//���tû��������,����ջ��ָʾ,����ջ��Ԫ��
		else if (!s.empty()){
			t = s.top();
			s.pop();
		}
		//���tû��������,����ջΪ��
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

	//��������ϵ t1����
	t1.lchild = &t2;
	//t1�Һ���
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	InOrder2(&t1);

	system("pause");
}