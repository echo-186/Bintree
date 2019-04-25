#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct BinNode
{
	T data;
	BinNode<T> *lch;
	BinNode<T> *rch;
	BinNode():lch(NULL), rch(NULL) {};
};
template<typename T>
class BST
{
private:
	void release(BinNode<T>*&R);
	void Delete(BinNode<T>*&R);//ɾ���ڵ�
	void Insert(BinNode<T> *&R, BinNode<T>*S);//����ڵ�
	
	BinNode<T> *Search(BinNode<T> *R, T key);//���ҵ�һ������key�Ľڵ�
public:
	BinNode<T> *_root;
	BST(T *r,int n );//((O(n^2),O(nlogn))
	void InsertBST(T a);//(O(n),O(logn))
	void SearchBST(T key);//(O(n),O(logn))
	 bool DeleteBST(BinNode<T>*&R,T key);//ɾ�����йؼ�ֵ�ڵ�
	 void InOrder(BinNode<T>*R);//��С�����ӡ(O(n))
	void LevelOrder();//�����ӡ(O(n))
	~BST();

	
};
