#include"BST.h"
#include"BST.cpp"
int main()
{
	int a[]= { 3,2,7,5,3,2,4,5,6,10 };
	BST<int> b(a,9);
	cout << "�������" << endl;
	b.LevelOrder();
	cout << "ɾ��3" << endl;
	b.DeleteBST(b._root, 3);
    b.LevelOrder();
	cout << "����3" << endl;
	b.InsertBST(3);
	cout << "˳�����" << endl;
	b.InOrder(b._root);
	cout << endl;
	cout << "����1" << endl;
	b.SearchBST(1);
	cout << "����3" << endl;
	b.SearchBST(3);
	system("pause");
}