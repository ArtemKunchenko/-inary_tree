#pragma once
#include <iostream>
using namespace std;

template<class T>
class Tree
{
public:
	Tree();
	void addIteratively(T data);
	void addRecursively(T data);
	void printMinMax();
	void printMaxMin();
	bool find(T key);
private:
	class Node {
	public:
		~Node() {
			if (right != nullptr) {
				delete right;
			}
			if (left != nullptr) {
				delete left;
			}
		}
		T data;
		Node* right;
		Node* left;
	};
	Node* root;
	bool found = false;
	void printMinMaxSupport(Node* root);
	void printMaxMinSupport(Node* root);
	void ars(Node** root, Node** newNode);
	void rfs(Node* root, T key);
};

