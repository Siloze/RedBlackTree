#pragma once
#include <stdio.h>
template <class T>
struct Node
{
	bool	black; //1 = black, 0 = red
	Node	*left;
	Node	*right;
	Node	*parent;
	T		value;
};

template <class T>
Node<T> *new_node(Node<T> *parent, T value = T(), bool isblack = true)
{
	Node<T> *tmp = new Node<T>;
	tmp->black = isblack;
	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = parent;
	return (tmp);
}

template <class T>
class Tree
{
	public :
		Tree() : _root(NULL)
		{
			return ;
		}
		Tree(const Tree & src)
		{
			return ;
		}
		~Tree()
		{
			return ;
		}
		Tree &operator=(const Tree& src)
		{
			return ;
		}
		void add(const T& value)
		{
			Node<T> *view = _root;
			while (view)
			{
				if (value <= view->value)
				{
					if (!view->left)
					{
						view->left = new_node<T>(view, value, false);
						this->recoloring(view->left);
						break;
					}
					view = view->left;
				}
				else
				{
					if (!view->right)
					{
						view->right = new_node<T>(view, value, false);
						this->recoloring(view->right);
						break;
					}
					view = view->right;
				}
			}
			if (!view)
				_root = new_node<T>(NULL, value);
		}
		
		Node<T> *search (const T& val, Node<T> *root)
		{
			if (!root || root->value == val)
				return (root);
			if (val < root->value)
				return (search(val, root->left));
			else
				return (search(val, root->right));
			
		}
		
		void	recoloring(Node<T> *child)
		{
			Node<T> *oncle;

			if (child->parent->parent && child->parent->parent->left && (child->parent->parent->left->value == child->parent->value))
				oncle = child->parent->parent->right;
			else if (child->parent->parent)
				oncle = child->parent->parent->left;
			else
				oncle = NULL;
			if (child->parent && !child->parent->black) // si le parent est rouge
			{
				if (oncle && !oncle->black) // si l'oncle de la nouvelle node est rouge
				{
					child->parent->black = true; //On met le parent en noir
					oncle->black = true; // On met l'oncle en noir
					if (child->parent->parent && child->parent->parent->parent) //si le grand pere (view.parent) n'est pas le root,
					{
						child->parent->parent->black = false; //On met le grand parent en rouge
						this->recoloring(child->parent->parent);
					}
				}
				else if ((oncle && oncle->black) || !oncle) // Tentative des 4 rotations si l'oncle est noir(LL, LR RR, RL)
					this->rotation(child);
			}
		}
		
		void rotation(Node<T> *child)
		{
			if (child->parent->parent->left && child->parent->value == child->parent->parent->left->value) //parent is left child of grand-parent
			{
				if (child->parent->left && child->value == child->parent->left->value) //  child is left child of parent
					LLRotation(child);
				else // child is right child of parent
					LRRotation(child);
			}
			else
			{
				if (child->parent->left && child->value == child->parent->left->value) //  child is left child of parent
					RLRotation(child);
				else
					RRRotation(child);
			}
			

		}

		void LLRotation(Node<T> *child)
		{

			std::cout << "LL ROTATION" << std::endl;
			Node<T> x = *child;
			Node<T> p = *child->parent;
			Node<T> g = *child->parent->parent;

			child->parent->parent->black = g.black;
			child->parent->parent->value = p.value;
			child->parent->parent->left = p.left;
			child->parent->parent->right = child->parent;
			child->parent->parent->parent = g.parent;

			child->parent->black = p.black;
			child->parent->value = g.value;
			child->parent->left = p.right;
			child->parent->right = g.right;
			child->parent = p.parent;
		};
		void LRRotation(Node<T> *child) // NE MARCHE PEUT ETRE PAS (DOIT ETRE RL A L ENVERS)
		{
			(void)child;
			std::cout << "LR ROTATION" << std::endl;
			Node<T> x = *child;
			Node<T> p = *child->parent;

			child->parent->value = x.value;
			child->parent->black = x.black;
			child->parent->left = child;
			child->parent->right = x.right;
			
			child->value = p.value;
			child->black = p.black;
			child->left = x.left;
			child->right = p.left;
			LLRotation(child);
		};
		void RRRotation(Node<T> *child)
		{
			std::cout << "RR ROTATION" << std::endl;
			Node<T> x = *child;
			Node<T> p = *child->parent;
			Node<T> g = *child->parent->parent;

			child->parent->parent->black = g.black;
			child->parent->parent->value = p.value;
			child->parent->parent->left = child->parent;
			child->parent->parent->right = p.right;
			child->parent->parent->parent = g.parent;

			child->parent->black = p.black;
			child->parent->value = g.value;
			child->parent->left = g.left;
			child->parent->right = p.left;

			child->parent = p.parent;
			//child->parent->parent = 

			// if (child->parent->parent->parent && child->parent->parent->parent->left && //si les arriere grand parents existent
			// 	child->parent->parent->value == child->parent->parent->parent->left->value) // si le grand parent est un enfant de gauche
			// {
			// 		std::cout << "1111" << std::endl;
			// 	child->parent->parent->parent->left = child->parent;
			// }
			// else if (child->parent->parent->parent)
			// {
			// 		std::cout << "22222" << std::endl;
			// 	child->parent->parent->parent->right = child->parent;
			// }

			// tmp = child->parent->left;	
			// child->parent->left = child->parent->parent;
			// child->parent->parent->right = tmp;	
			// child->parent
		};
		void RLRotation(Node<T> *child)
		{
			std::cout << "RL ROTATION" << std::endl;
			Node<T> x = *child;
			Node<T> p = *child->parent;

			child->parent->value = x.value;
			child->parent->black = x.black;
			child->parent->left = x.left;
			child->parent->right = child;
			
			child->value = p.value;
			child->black = p.black;
			child->left = x.right;
			child->right = p.right;
			RRRotation(child);
		};
		Node<T> *getRoot( void ) const {return this->_root;};
	private :
		Node<T> *_root;
};

