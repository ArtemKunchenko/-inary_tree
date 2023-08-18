#include "Tree.h"
template<class T>
Tree<T>::Tree() : root(nullptr)
{
	cout << "Created the tree" << endl;
}
template<class T>
inline void Tree<T>::addIteratively(T data) 
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->right = nullptr;
	newNode->left = nullptr;

	Node** tmp = &root;

	while (*tmp != nullptr)
	{
		if ((*tmp)->data == data) return;
		if (*tmp != nullptr && (*tmp)->data > data) tmp = &(*tmp)->left;
		if (*tmp != nullptr && (*tmp)->data < data) tmp = &(*tmp)->right;
	}
	*tmp = newNode;
}

template<class T>
void Tree<T>::addRecursively(T data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->right = nullptr;
	newNode->left = nullptr;

	ars(&root, &newNode);
}

template<class T>
void Tree<T>::ars(Node** root, Node** newNode)
{
	if (*root != nullptr)
	{
		if ((*root)->data == (*newNode)->data) return;
		if ((*root)->data > (*newNode)->data) ars(&(*root)->left, &(*newNode));
		if ((*root)->data < (*newNode)->data) ars(&(*root)->right, &(*newNode));
	}
	else *root = *newNode;
}

template<class T>
void Tree<T>::printMinMax()
{
	printMinMaxSupport(root);
	cout << endl;
}

template<class T>
void Tree<T>::printMinMaxSupport(Node* root)
{
	if (root != nullptr)
	{
		printMinMaxSupport(root->left);
		cout << root->data << "\t";
		printMinMaxSupport(root->right);
	}
}

template<class T>
void Tree<T>::printMaxMin()
{
	printMaxMinSupport(root);
	cout << endl;
}

template<class T>
bool Tree<T>::find(T key)
{
	rfs(root, key);
	return found;
}

template<class T>
void Tree<T>::rfs(Node* root, T key_)
{
	if (root != nullptr)
	{
		rfs(root->right, key_);
		if (root->data == key_) found = true;
		rfs(root->left, key_);
	}
}



template<class T>
void Tree<T>::printMaxMinSupport(Node* root)
{
	if (root != nullptr)
	{
		printMaxMinSupport(root->right);
		cout << root->data << "\t"; 
		printMaxMinSupport(root->left);
	}
}