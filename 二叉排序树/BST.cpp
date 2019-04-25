#include "BST.h"
template<typename T>
void BST<T>::release(BinNode<T>* &R)
{
	if (R != NULL)
	{
		release(R->lch);
		release(R->rch);
		delete R;
	}
}
template<typename T>
BST<T>::BST(T *r, int n)
{
	if (n == 0||!r)
		throw"����Ϊ�գ�����������";
	_root = NULL;
	for (int i = 0; i < n; i++)
	{
		BinNode<T> *s = new BinNode<T>;
		s->lch = NULL;
		s->rch = NULL;
		s->data = r[i];
		Insert(_root, s);
	}
}

template<typename T>
void BST<T>::InsertBST(T a)
{
	BinNode<T> *temp = new BinNode<T>;
	temp->lch = NULL;
	temp->rch = NULL;
	temp->data = a;
	Insert(_root, temp);

}

template<typename T>
void BST<T>::SearchBST(T key)
{
	if (Search(_root, key))
	cout<<"�ɹ�����\n";
	else
	{
		cout << "����ʧ��\n";
	}
}

template<typename T>
void BST<T>::Insert(BinNode<T>*& R, BinNode<T>* S)
{
	
		///��Ȼelse ifЧ�ʸ���//if (temp == NULL)
		 //	R = S;
	   //if (S->data <= R->data)//�Ż������ڵ��ڵĴ���
		 //	R->lch = S;
	if (R== NULL)
	{
		R = S;
	}

	else if (S->data <= R->data)//�Ż������ڵ��ڵĴ���
		Insert(R->lch, S);

		else
		Insert(R->rch, S);


}

template<typename T>
BinNode<T>* BST<T>::Search(BinNode<T>* R, T key)//Ϊʲô��һ��ָ�룿����������Ϊ����ָ����������޸ĺ����ⲿָ��ָ��ĵ�ַ��һ��ָ�����޸ĺ����ⲿָ��ָ���ֵ������������ö���ָ��
{
	if (R == NULL) return NULL;
	if (key == R->data) return R;
    if (key < R->data)return Search(R->lch, key);
	if (key > R->data)return Search(R->rch, key);
}

template<typename T>
void BST<T>::Delete(BinNode<T>*& R)
{
	BinNode<T> *q, *s;
	if (R==NULL)
	{
		return;
	}
	if (R->lch == NULL)//ֻ��������
	{
		q = R;
		R = R->rch; delete q;
	}
	else if (R->rch == NULL)
	{
		q = R;
		R = R->lch;
		delete q;
	}
	else
	{
		q = R;
		s = R->lch;
		while (s->rch!=NULL)
		{
			q = s;
			s = s->rch;
		}
		R->data = s->data;
		if (q != R)
			q->rch = s->lch;
		else
			R->lch = s->lch;
		delete s;
	}

}

template<typename T>
void BST<T>::InOrder(BinNode<T>* R)
{

	if (R!= NULL)
	{
		InOrder(R->lch);
		cout << R->data;
		InOrder(R->rch);
	}
	
}

template<typename T>
void BST<T>::LevelOrder()
{
	
	BinNode<T>* R = _root;
		BinNode<T> *queue[15];
		int f = 0, r = 0;
		int n = 1,m=0;//m�²��м�������n�Ǳ����м�����
		if (R != NULL)
		{
			queue[++r] = R;
		}
		while (f!= r)
		{

		BinNode<T> *p= queue[++f];
		n--;
		cout << p->data << " ";		
		
		if (p->lch != NULL) { queue[++r] = p->lch; m++; }
		if (p->rch != NULL) { queue[++r] = p->rch; m++;}
	    if (n == 0)
		{
			n = m;
			m = 0;
				cout << "\n";
		}

		}
	}


template<typename T>
BST<T>::~BST()
{
	release(_root);
}
template<typename T>
bool BST<T>::DeleteBST(BinNode<T>*&R, T key)
{
	if (R == NULL)
	{
		cout << "ɾ��ʧ��" << endl;
		return false;
	}
	else
	{
		
		if (key == R->data)
		{
			while (key ==R->data)
			{
				Delete(R);
			}
			return true;
		}
		else if(key<R->data)
	{
			return DeleteBST(R->lch, key);
	}
		else
		{
			return DeleteBST(R->rch, key);
		}
	}

}


