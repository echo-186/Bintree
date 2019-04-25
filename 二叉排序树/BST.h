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
	void Delete(BinNode<T>*&R);//删除节点
	void Insert(BinNode<T> *&R, BinNode<T>*S);//插入节点
	
	BinNode<T> *Search(BinNode<T> *R, T key);//查找第一个等于key的节点
public:
	BinNode<T> *_root;
	BST(T *r,int n );//((O(n^2),O(nlogn))
	void InsertBST(T a);//(O(n),O(logn))
	void SearchBST(T key);//(O(n),O(logn))
	 bool DeleteBST(BinNode<T>*&R,T key);//删除所有关键值节点
	 void InOrder(BinNode<T>*R);//由小到大打印(O(n))
	void LevelOrder();//层序打印(O(n))
	~BST();

	
};
