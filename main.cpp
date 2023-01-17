#include <iostream>
#include <vector>

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
    std::cout << root->value << "\n";
     print2DUtil(root->left, space);
}
 
template <class T>
void print2D(Node<T>* root)
{
    print2DUtil(root, 0);
}

int main( void )
{
    Tree<int> slt;
    slt.add(5);
    slt.add(2);
    slt.add(3);
    slt.add(8);
    slt.add(9);
    slt.add(7);
    print2D<int>(slt.getRoot());
    return (0);
}