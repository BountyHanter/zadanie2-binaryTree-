#include <iostream>
#include "BinaryTree.h"
int main()
{
	Tree tree;
	tree.Is_Empty(tree.root);
	int n;
	std::cin >> n;
	int d;
	for (int i = 0; i < n; i++)
	{
		std::cin >> d;
		tree.AddToTree(tree, d);
	}
	std::cout << "Choose a workaround\n 0 - forward\n 1 - simmetrical\n 2 - reverse";
	std::cout << std::endl;
	int g;
	g = 2;
	tree.PrintTreeStructure(tree.root);
	///*int a = 0;
	//std::cin >> a;
	//int res = tree.SearchInTree(tree, a);
	//std::cout << res << std::endl;
	//std::cout << "This tree have " << res << " specified nodes == " << d;*/
	//std::cout << "tree cleared\n";
	//tree.ClearTree(tree.root);
	//std::cout << "print tree\n";
	//tree.Is_Empty(tree.root);
	tree.del_elem(tree.root, 21);
	tree.PrintTreeStructure(tree.root);
}


