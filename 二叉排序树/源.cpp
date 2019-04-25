#include"BST.h"
#include"BST.cpp"
int main()
{
	int a[]= { 3,2,7,5,3,2,4,5,6,10 };
	BST<int> b(a,9);
	cout << "²ãÐò±éÀú" << endl;
	b.LevelOrder();
	cout << "É¾³ý3" << endl;
	b.DeleteBST(b._root, 3);
    b.LevelOrder();
	cout << "Ôö¼Ó3" << endl;
	b.InsertBST(3);
	cout << "Ë³ÐòÊä³ö" << endl;
	b.InOrder(b._root);
	cout << endl;
	cout << "²éÕÒ1" << endl;
	b.SearchBST(1);
	cout << "²éÕÒ3" << endl;
	b.SearchBST(3);
	system("pause");
}