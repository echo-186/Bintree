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
		throw"数组为空，请重新输入";
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
	cout<<"成功查找\n";
	else
	{
		cout << "查找失败\n";
	}
}

template<typename T>
void BST<T>::Insert(BinNode<T>*& R, BinNode<T>* S)
{
	
		///显然else if效率更高//if (temp == NULL)
		 //	R = S;
	   //if (S->data <= R->data)//优化，关于等于的处理
		 //	R->lch = S;
	if (R== NULL)
	{
		R = S;
	}

	else if (S->data <= R->data)//优化，关于等于的处理
		Insert(R->lch, S);

		else
		Insert(R->rch, S);


}

template<typename T>
BinNode<T>* BST<T>::Search(BinNode<T>* R, T key)//为什么是一重指针？————因为二重指针的作用是修改函数外部指针指向的地址，一重指针是修改函数外部指针指向的值，这里绝不能用二重指针
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
	if (R->lch == NULL)//只有右子树
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
		int n = 1,m=0;//m下层有几个数，n是本层有几个数
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
		cout << "删除失败" << endl;
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


