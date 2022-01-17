#include <iostream>
struct Node
{
	int value;
	Node* left;
	Node* right;
};
class Tree
{
	Node* root;
public:
	Tree()
	{
		this->root = NULL;
	}
	void ADD(int value)
	{
		add(value, root);
	}
	void add(int value,Node*&tmp)
	{
		if (tmp == NULL)
		{
			tmp = new Node;
			tmp->value = value;
			tmp->left = tmp->right = NULL;
		}
		else
		{
			if (tmp->value > value)
			{
				add(value, tmp->left);
			}
			else
			{
				add(value, tmp->right);
			}
		}
	}
	void show(Node*tmp)
	{
		if (tmp == NULL)
		{
			return;
		}
		else
		{
			show(tmp->left);
			std::cout << tmp->value << "\n";
		}
		show(tmp->right);
	}
	void SHOW()
	{
		show(root);
	}
};
int main()
{
	setlocale(0, "");
	Tree tree;
	int n;
	int val;
	std::cout << "Введите количество чисел: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Введите значение: ";
		std::cin >> val;
		tree.ADD(val);
	}
	std::cout << "Полученное дерево:\n";
	tree.SHOW();
}
