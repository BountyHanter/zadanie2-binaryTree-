#include "BinaryTree.h"
Tree::Tree()
{
	std::cout << this << " start constructor\n";
}
Tree::~Tree()
{
	std::cout << this << " start destructor\n";

}
void Tree::AddToSubTree(Node*& node, Node* newnode) // ������� ����
{
	if (node == NULL)
	{
		node = newnode; // ���� ����� ��� �� ����� ���� ���������� ������
		return;
	}
	if (newnode->data == node->data) // ���� ������ � ����� newnode ����������� � ����� �� ����� �� ����������� ������� � ������ ������� ����
	{
		node->counter += newnode->counter; // ���������� � �������� ������������� node ������� newnode ��� ��� � newnode ����� �������� �� ���� � ��������� �����.
		newnode = NULL;
		return;
	}
	if (newnode->data < node->data) // ���� ������ ������ ���� ������ ��� �������
		AddToSubTree(node->left, newnode); // �� ��������� � ������ �������
	else
		AddToSubTree(node->right, newnode); // ����� � �������
}

void Tree::AddToTree(Tree& tree, int d) // ������� ������
{
	Node* node = new Node; 
	node->data = d; 
	node->left = node->right = NULL; // ������� �������� ������� ���� ��� ������
	node->counter = 1;
	AddToSubTree(tree.root, node); // ��������� �������� ����
}

void Tree::PrintSubTreePr(Node* node) // ������ ����� ������ ( ������ - ����� ��� �� ����� ����������� �� �����, ����� ��� �� ������ ����������� ����� ����� )
{
	
	if (!node) return;
	printf(" %i", node->data); // (%i �.�. �� ��������� 8,10,16  ������� ���������) ����� ����������� ����� ��������� ������� ������ 
	if (node->counter > 1)
		printf("x%i", node->counter);
	Tree::PrintSubTreePr(node->left);
	Tree::PrintSubTreePr(node->right);
}

void Tree::PrintSubTreeObr(Node* node) // �������� ����� ������ ( ����� ��������� �����, ����� ������, ����� ������ � ��� ����� ����� )
{
	if (node == NULL) return;
	Tree::PrintSubTreeObr(node->left);
	Tree::PrintSubTreeObr(node->right);
	printf(" %i", node->data);
	if (node->counter > 1)
		printf("x%i", node->counter);

}

void Tree::PrintSubTreeSimmetr(Node* node) // ������������ ����� ������ ( �������� ����� ����� - ����� - ������ - �����, � ����� ����� )
{
	if (node == NULL) return;
	Tree::PrintSubTreeSimmetr(node->left);
	printf(" %i", node->data);
	if (node->counter > 1)
		printf("x%i", node->counter);
	Tree::PrintSubTreeSimmetr(node->right);
}

void Tree::ClearTree(Node* node)

{
	if (node == NULL)
		return;
		Tree::ClearTree(node->left);
		Tree::ClearTree(node->right);
		delete node;
}

void Tree::PrintTree(Tree tree, int d) // �������� ������, ��� �� ��� ����� ����� ����� ������ ������������
{
	if (d == NULL) 
		Tree::PrintSubTreePr(tree.root);
	else if (d == 1)
		Tree::PrintSubTreeSimmetr(tree.root);
	else if (d == 2)
		Tree::PrintSubTreeObr(tree.root);
	else
	{
		while (d != NULL && d != 1 && d != 2)
		{
			std::cout << "Wrong number, return";
			std::cin >> d;
		}
		return;
	}
}

int Tree::SearchInSubTree(Node* node, int d)
{

	if (node == NULL) return 0; // ���� ��� ���� 
	if (node->data == d) return node->counter; // ���� ���� == ������, ������ 1. ���� ������ 1 ������ counter;
	if (d < node->data)
		return SearchInSubTree(node->left, d); // ���� �������� ����� ������ �� ��� � ����� ������� � ����� �������
	else
		return SearchInSubTree(node->right, d); // ���� ������ �� � ������ �������

}

int Tree::SearchInTree(Tree tree, int d)
{
	return SearchInSubTree(tree.root, d);
}

//void Tree::SearchForDelete(Node* node, int d)
//{
//	if (node == NULL) return; // ���� ��� ���� 
//	if (node->data == d)
//	DeleteElement(node); // ���� ���� == ������, ������ 1. ���� ������ 1 ������ counter;
//	if (d < node->data)
//		return SearchForDelete(node->left, d); // ���� �������� ����� ������ �� ��� � ����� ������� � ����� �������
//	else
//		return SearchForDelete(node->right, d); // ���� ������ �� � ������ �������
//}

void Tree::Is_Empty(Node* node)
{
	if (!node)
		std::cout << "Tree is empty";
	else
		std::cout << "Tree isn't empty";
}



void Tree::PrintSubTreeStructure(Node* node, int depth, bool isroot)
{
	if (node == NULL) return;
	if (isroot) 
		printf("%2d\n", node->data);
	else
	{
		for (int i = 0; i < depth; i++)
			printf("|  ");
		printf("\b\b--%2d\n", node->data);
	}
		PrintSubTreeStructure(node->left, depth + 1);
		PrintSubTreeStructure(node->right, depth + 1);
}

void Tree::PrintTreeStructure(Node* node)
{
	PrintSubTreeStructure(node, 0, true);
}
int Tree::del_elem( Node*& node, int aData)
/*���������:
������� �� �����.
��������� - ���� �� ������ ����. 
���� ��� �� ��������� ���� �� ����� ����
���� ���� �� �������� ��������� �� ����� ����, ���� ��� �� ������ ������� ����
���� ������ ����, ����� ���� ��� � ���������� ptr � ������ ����� �� ����� �����������, ��� �� ����� �����, ���� ��� ����, � � ����� ������ ����� ����, � ���� � ����� ���� ��������� ptr
���� ����� ����� ��� �� ������ ptr � ����� ���� ���������� ����
*/
{
	if (node == NULL) return 0; // ���� ��� ���� 
	if (node->data == aData) // ���� ���� == ���������� ��������
	{
		Node* ntr;
		if (node->right == NULL) // ���� � ����� ��� ������� ����
		{
			if (node->left != NULL) // ���� � ����� ���� ����� ����
			{
				ntr = node->left; // ������� ����� ���� � ����������
				node = ntr; // ������ = ��� ������ ����, �.�. �� �������� ��������� ������ �� ��� ����� ����, �� �������� ��� ��� (���������!!!!!!!)
			}
			else // ���� � ����� ��� �� ������ �� ������� ���� ������ ������� ������
				delete node;
		}
		else // ���� � ����� ���� ������ ����
		{
			if (node->left == NULL) // � ��� ������ ����
			{
				ntr = node->right; // �������� ��������� �� ��� ����� ���� 
				node = ntr;
			}
			else // ���� ���� � ����� ����
			{
				ntr = node->left; // ���� ����� � ����������
				Node* ptr = node->right;
				node = ptr; // �������� ��������� �� ��� ������ ����
				if (node->left != NULL)
				{
					while (node->left != NULL) // ��������� �� ����� ����� ���� ���� ��� ����
					{
						node = node->left;
					} // �������� � ��� ��� ��� �������� �� ����� � ���� ��� ���������������, � ��� ����� ������� ������ �� ����� ���� ��� ��������������� ����� ������ ���� ��������
				}
				node->left = ntr; // � ������ ���� ������ ������ ������� ���� ���������� ����������� ����� ���� �� ���������, �.�. �� ������ ����� ������ ������ ������ ����������
			} // ������� ���� �� ��������
		}
	}
	if (aData < node->data)
		return del_elem(node->left, aData); // ���� �������� ����� ������ �� ��� � ����� ������� � ����� �������
	else
		return del_elem(node->right, aData); // ���� ������ �� � ������ �������
}

