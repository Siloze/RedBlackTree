# RedBlackTree

## **Description**
Ce projet est une implémentation d'un arbre rouge-noir (Red-Black Tree) en C++. L'arbre rouge-noir est une structure de données de type arbre binaire de recherche auto-équilibré. Il garantit que la hauteur de l'arbre est O(log n), ce qui le rend efficace pour la recherche, l'insertion et la suppression d'éléments.

## **Fonctionnalités**
La classe RedBlackTree implémente les fonctions suivantes :

void insert(const T& value) : insère un nouvel élément dans l'arbre.

void remove(const T& value) : supprime un élément de l'arbre.

bool contains(const T& value) const : vérifie si l'arbre contient un élément donné.

void clear() : supprime tous les éléments de l'arbre.

size_t size() const : renvoie le nombre d'éléments de l'arbre.

bool empty() const : vérifie si l'arbre est vide.

void print() : affiche les éléments de l'arbre.

## **Utilisation**
Pour utiliser cette implémentation de Red-Black Tree, vous pouvez inclure la classe RedBlackTree.h dans votre projet et instancier un objet RedBlackTree<T> avec le type de données que vous souhaitez stocker dans l'arbre.
```C++
#include "RedBlackTree.h"

RedBlackTree<int> tree;

tree.insert(10);
tree.insert(5);
tree.insert(15);
tree.remove(5);
bool contains = tree.contains(10);
size_t size = tree.size();
tree.print();
```
## **Auteur**
Ce projet a été créé par Siloze (samuel.janssens13@gmail.com
