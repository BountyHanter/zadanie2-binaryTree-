#pragma once
#include <iostream>
// перевел из структуры в класс и могут быть ошибки но код работает
class Tree
{
private:
	struct Node // стркутура узела дерева
	{
		int data; // значение внутри листа
		int counter; // счетчик, нужен чтобы считать повторения (сейчас он не нужен, занимает память но с большими структурами очень сильно поможет)
		Node* left, * right; // указатели на потомков
	};
public:

	Node* root = NULL; // корень дерева
	Tree();
	~Tree();
	void AddToSubTree(Node*& node, Node* newnode); // передаётся узел
	void AddToTree(Tree& tree, int d); // добавить дерево
	void PrintTree(Tree tree, int d); // распечатать дерево 
	int SearchInSubTree(Node* node, int d); // поиск в поддереве
	int SearchInTree(Tree tree, int d); // искать в дереве
	void PrintSubTreePr(Node* node);
	void PrintSubTreeObr(Node* node);
	void PrintSubTreeSimmetr(Node* node);
	void ClearTree(Node* node);
	void Is_Empty(Node* node);
	int del_elem(Node*& node, int aData);
	void PrintTreeStructure(Node* node);
	void PrintSubTreeStructure(Node* node, int depth, bool isroot = false);

};  