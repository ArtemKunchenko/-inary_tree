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
	void startLCA(T key1, T key2)
	{
		LCA(getNode(key1), getNode(key2));
	}
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
	void rfs(Node* root, T key_);
	Node* getNodeHelper(Node* current, const T& key) const
	{
		if (current == nullptr || current->data == key)
			return current;

		if (key < current->data)
			return getNodeHelper(current->left, key);

		return getNodeHelper(current->right, key);
	}

	Node* getNode(const T& key)
	{
		return getNodeHelper(root, key);
	}
	Node* findLCA(Node* current, Node* n1, Node* n2) const
	{
		if (current == nullptr)
			return nullptr;

		// Если текущий узел равен одному из искомых узлов, то это и есть LCA
		if (current == n1 || current == n2)
			return current;

		Node* leftLCA = findLCA(current->left, n1, n2);
		Node* rightLCA = findLCA(current->right, n1, n2);

		// Если один узел находится в левом поддереве, а другой - в правом поддереве,
		// то текущий узел является LCA
		if (leftLCA && rightLCA)
			return current;

		// В противном случае LCA находится в одном из поддеревьев
		return (leftLCA != nullptr) ? leftLCA : rightLCA;
	}
	void LCA(Node* n1, Node* n2)
	{
		Node* lcaNode = findLCA(root, n1, n2);

		if (lcaNode)
		{
			cout << "LCA of " << n1->data << " and " << n2->data << " is: " << lcaNode->data << std::endl;
		}
		else
		{
			cout << "LCA not found for " << n1->data << " and " << n2->data << std::endl;
		}
	}
	
};

