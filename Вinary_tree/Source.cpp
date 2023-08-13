#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

int main()
{
	Tree<int> tree;
	//Iteration
	//tree.addIteratively(2); // Root
	//tree.addIteratively(1);
	//tree.addIteratively(4);
	//tree.addIteratively(3);
	// Recursively
	tree.addRecursively(2); // Root
	tree.addRecursively(1);
	tree.addRecursively(4);
	tree.addRecursively(3);

	// Recursive print
	cout << "min -> max:" << endl;
	tree.printMinMax();
	cout << "max -> min:" << endl;
	tree.printMaxMin();
	//find
	if (tree.find(15)) cout << "found" << endl;
	else cout << "Not found" << endl;

	return 0;
}