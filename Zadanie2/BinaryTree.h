#pragma once
#include <iostream>
// ������� �� ��������� � ����� � ����� ���� ������ �� ��� ��������
class Tree
{
private:
	struct Node // ��������� ����� ������
	{
		int data; // �������� ������ �����
		int counter; // �������, ����� ����� ������� ���������� (������ �� �� �����, �������� ������ �� � �������� ����������� ����� ������ �������)
		Node* left, * right; // ��������� �� ��������
	};
public:

	Node* root = NULL; // ������ ������
	Tree();
	~Tree();
	void AddToSubTree(Node*& node, Node* newnode); // ��������� ����
	void AddToTree(Tree& tree, int d); // �������� ������
	void PrintTree(Tree tree, int d); // ����������� ������ 
	int SearchInSubTree(Node* node, int d); // ����� � ���������
	int SearchInTree(Tree tree, int d); // ������ � ������
	void PrintSubTreePr(Node* node);
	void PrintSubTreeObr(Node* node);
	void PrintSubTreeSimmetr(Node* node);
	void ClearTree(Node* node);
	void Is_Empty(Node* node);
	int del_elem(Node*& node, int aData);
	void PrintTreeStructure(Node* node);
	void PrintSubTreeStructure(Node* node, int depth, bool isroot = false);

};  