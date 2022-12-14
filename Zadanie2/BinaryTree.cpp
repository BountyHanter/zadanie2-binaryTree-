#include "BinaryTree.h"
Tree::Tree()
{
	std::cout << this << " start constructor\n";
}
Tree::~Tree()
{
	std::cout << this << " start destructor\n";

}
void Tree::AddToSubTree(Node*& node, Node* newnode) // создаем узел
{
	if (node == NULL)
	{
		node = newnode; // если корня нет то новый узел становится корнем
		return;
	}
	if (newnode->data == node->data) // если данные в новом newnode повторяются с каким то узлом то увиличиваем счётчик у самого первого узла
	{
		node->counter += newnode->counter; // прибавляем к счетчику существующего node счётчик newnode так как в newnode может хранится не одна а несколько узлов.
		newnode = NULL;
		return;
	}
	if (newnode->data < node->data) // если данные нового узла меньше чем старого
		AddToSubTree(node->left, newnode); // то добавляем в левого потомка
	else
		AddToSubTree(node->right, newnode); // иначе в правого
}

void Tree::AddToTree(Tree& tree, int d) // создаем корень
{
	Node* node = new Node; 
	node->data = d; 
	node->left = node->right = NULL; // создаем потомков которые пока что пустые
	node->counter = 1;
	AddToSubTree(tree.root, node); // запускаем создание узла
}

void Tree::PrintSubTreePr(Node* node) // прямой обход дерева ( корень - потом идём по левым поддеревьям до конца, потом идём по правым поддеревьям снизу вверх )
{
	
	if (!node) return;
	printf(" %i", node->data); // (%i т.к. он принимает 8,10,16  системы счисления) когда закончилось левое поддерево выводим корень 
	if (node->counter > 1)
		printf("x%i", node->counter);
	Tree::PrintSubTreePr(node->left);
	Tree::PrintSubTreePr(node->right);
}

void Tree::PrintSubTreeObr(Node* node) // обратный обход дерева ( Левое поддерево снизу, потом правое, потом корень и так снизу вверх )
{
	if (node == NULL) return;
	Tree::PrintSubTreeObr(node->left);
	Tree::PrintSubTreeObr(node->right);
	printf(" %i", node->data);
	if (node->counter > 1)
		printf("x%i", node->counter);

}

void Tree::PrintSubTreeSimmetr(Node* node) // симметричный обход дерева ( начанаем слева снизу - левое - корень - право, и снизу вверх )
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

void Tree::PrintTree(Tree tree, int d) // печатаем дерево, так же тут выбор какой обход дерева использовать
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

	if (node == NULL) return 0; // если нет узла 
	if (node->data == d) return node->counter; // если узел == корень, вернет 1. Если больше 1 вернет counter;
	if (d < node->data)
		return SearchInSubTree(node->left, d); // если заданное число меньше то идём в левый потомок и снова сверяем
	else
		return SearchInSubTree(node->right, d); // если больше то в правый потомок

}

int Tree::SearchInTree(Tree tree, int d)
{
	return SearchInSubTree(tree.root, d);
}

//void Tree::SearchForDelete(Node* node, int d)
//{
//	if (node == NULL) return; // если нет узла 
//	if (node->data == d)
//	DeleteElement(node); // если узел == корень, вернет 1. Если больше 1 вернет counter;
//	if (d < node->data)
//		return SearchForDelete(node->left, d); // если заданное число меньше то идём в левый потомок и снова сверяем
//	else
//		return SearchForDelete(node->right, d); // если больше то в правый потомок
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
/*Инструкци:
Доходим до числа.
Проверяем - есть ли правый узел. 
Если нет то проверяем есть ли левый узел
Если есть то заменяем удаляемый на левый узел, если нет то просто удаляем узел
Если правый есть, левый узел суём в переменную ptr и правый стаим на место заменяемого, идём по левым узлам, если они есть, и в самом нижнем левом узле, к нему в левый узел вставляем ptr
если левых узлов нет то ставим ptr в левый узел заменённого узла
*/
{
	if (node == NULL) return 0; // если нет узла 
	if (node->data == aData) // если узел == указанному значению
	{
		Node* ntr;
		if (node->right == NULL) // если у корня нет правого узла
		{
			if (node->left != NULL) // если у корня есть левый узел
			{
				ntr = node->left; // заносим левый узел в переменную
				node = ntr; // корень = его левому узлу, т.е. мы заменили удаляемый корень на его левый узел, хз работает или нет (проверить!!!!!!!)
			}
			else // если у корня нет ни левого ни правого узла просто удаляем корень
				delete node;
		}
		else // если у корня есть правый узел
		{
			if (node->left == NULL) // и нет левого узла
			{
				ntr = node->right; // заменяем удаляемый на его левый узел 
				node = ntr;
			}
			else // если есть и левый узел
			{
				ntr = node->left; // суем левый в переменную
				Node* ptr = node->right;
				node = ptr; // заменяем удаляемый на его правый узел
				if (node->left != NULL)
				{
					while (node->left != NULL) // двигаемся по левым узлам вниз пока они есть
					{
						node = node->left;
					} // проблема в том что при переходе по узлам у меня идёт переопределение, а мне нужно достать ссылку на левый лист без переопределения иначе правые узлы теряются
				}
				node->left = ntr; // к левому узлу самого левого нижнего узла заменённого прикрепляем левый узел от удалённого, т.к. он всегда будет меньше самого левого заменённого
			} // господи хоть бы работало
		}
	}
	if (aData < node->data)
		return del_elem(node->left, aData); // если заданное число меньше то идём в левый потомок и снова сверяем
	else
		return del_elem(node->right, aData); // если больше то в правый потомок
}

