#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

int main()
{
	Tree<int> tree;
	
	tree.addIteratively(8);
	tree.addIteratively(3);
	tree.addIteratively(10);
	tree.addIteratively(1);
	tree.addIteratively(6);
	tree.addIteratively(14);
	tree.addIteratively(4);
	tree.addIteratively(7);
	tree.addIteratively(13);
	
	tree.startLCA(1, 14);
	system("pause");
	return 0;
}