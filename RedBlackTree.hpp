#pragma once

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
Node<T> *new_node(Node<T> *parent, T value = T())
{
	Node<T> *tmp = new Node<T>;
	tmp->black = true;
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
						view->left = new_node<T>(view, value);
						break;
					}
					view = view->left;
				}
				else
				{
					if (!view->right)
					{
						view->right = new_node<T>(view, value);
						break;
					}
					view = view->right;
				}
			}
			if (!view)
			{
				_root = new_node<T>(NULL, value);
			}
		}
		Node<T> *getRoot( void ) const {return this->_root;};
	private :
		Node<T> *_root;
};

