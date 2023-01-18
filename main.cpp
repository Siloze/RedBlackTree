#include <iostream>
#include <vector>
#include <stdlib.h>
# include "RedBlackTree.hpp"

template <class T>
void print2DUtil(Node<T>* root, int space)
{
	if (root == NULL)
		return;
	 space += 10;
	 print2DUtil(root->right, space);
	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	std::cout << root->value;
	root->black ? std::cout << "b" : std::cout << "r";
	std::cout << "\n";
	 print2DUtil(root->left, space);
}
 
template <class T>
void print2D(Node<T>* root)
{
	print2DUtil(root, 0);
}

template <class T>
void search2D(Tree<T> &tree)
{
	Node<T> *resul;

	resul = tree.search(7, tree.getRoot());
	if (resul)
		std::cout << "result node value : " << resul->value << ", parent value : " << resul->parent->value << std::endl;
}
int main( void )
{
	Tree<int> slt;
	slt.add(40);
	slt.add(32);
	slt.add(31);
	slt.add(33);
	slt.add(4);
	slt.add(456);
	slt.add(1);
	slt.add(98);
	slt.add(29);
	slt.add(28);
	slt.add(2);
	slt.add(3);


	print2D<int>(slt.getRoot());
//	search2D<int>(slt);
	return (0);
}