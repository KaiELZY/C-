#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

struct Node
{
	
	int data;
	Node *left;
	Node *right;
};

class BinarySearchTree
{
private:

	Node* root;

	int nodes;

	Node* insert(int data, Node *temp)
	{
		if (!temp)
		{
			temp = new Node;
			temp->data = data;
			temp->left = temp->right = NULL;
		}
		else if (data < temp->data)
			temp->left = insert(data, temp->left);
		else if (data > temp->data)
			temp->right = insert(data, temp->right);
		return temp;
	}
	

	bool isBalanced(Node* root)
	{
		if (!root) {
			return true;
		}

		int leftHt = findMaxHeight(root->left);
		int rightHt = findMaxHeight(root->right);

		if (abs(leftHt - rightHt) > 1)
		{
			return false;
		}

		return isBalanced(root->left) && isBalanced(root->right);
	}
	int findMaxHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = findMaxHeight(root->left);
		int rightHeight = findMaxHeight(root->right);

		if (leftHeight > rightHeight)
		{
			return leftHeight + 1;
		}
		else if (leftHeight < rightHeight)
		{
			return rightHeight + 1;
		}
		else //both branches are equal
		{
			return leftHeight + 1;
		}
	}

	bool isComplete(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}
		bool indicator = false;

		queue<Node *> tempQueue;
		tempQueue.push(root);

		while (!tempQueue.empty())
		{
			Node *temp = tempQueue.front();
			tempQueue.pop();

			if (temp->left)
			{
				if (indicator == true)
				{
					return false;
				}
				tempQueue.push(temp->left);
			}
			else
			{
				indicator = true;
			}
			if (temp->right)
			{
				if (indicator == true)
				{
					return false;
				}
				tempQueue.push(temp->right);
			}
			else
			{
				indicator = true;
			}
		}

		return true;

	}

	void InOrder(Node* root)
	{
		if (root == NULL)
			return;
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
	int minDepth(Node* root)
	{

		if (root == NULL)
		{
			return 0;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}
		
		if (!root->left)
		{
			return minDepth(root->right) + 1;
		}

		if (!root->right)
		{
			return minDepth(root->left) + 1;
		}

		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	
public:

	BinarySearchTree()
	{
		root = NULL;
	}

	void insert(int data)
	{
		root = insert(data, root);
	}

	void LoadBST(string fileName)
	{
		fstream file;
		file.open(fileName);
		int num;

		while (!file.eof())
		{
			file >> num;
			nodes += 1;
			insert(num);
		}
	}

	int numberOfNodes()
	{
		return nodes;
	}
	
	int findMinHeight()
	{
		return minDepth(root);
	}

	int findMaxHeight()
	{
		return findMaxHeight(root);
	}

	bool isCompleted()
	{
		return isComplete(root);
	}

	bool isBalanced()
	{
		return isBalanced(root);
	}

	

	void display() {
		cout << "Tree data is: ";
		InOrder(root);
		cout << endl;
		
	}

};
int main()
{

	cout << "Height will start from 1, not from 0! (Root = 1)" << endl;

	cout << "==================================================" << endl;
	
	BinarySearchTree tree1;
	
	tree1.LoadBST("test.txt");
	
	tree1.display();

	cout << "Smallest Branch Height is: " << tree1.findMinHeight() << endl;

	cout << "Largest Branch Height is: " << tree1.findMaxHeight() << endl;

	cout << "Number of Nodes: " << tree1.numberOfNodes() << endl;

	if (tree1.isBalanced())
	{
		cout << "Is the BST balanced: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST balanced: " << "False " << endl;
	}

	if (tree1.isCompleted())
	{
		cout << "Is the BST completed: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST completed: " << "False " << endl;
	}

	cout << "--------------------------------------------------" << endl;

	BinarySearchTree tree2;

	tree2.LoadBST("test2.txt");

	tree2.display();

	cout << "Smallest Branch Height is: " << tree2.findMinHeight() << endl;

	cout << "Largest Branch Height is: " << tree2.findMaxHeight() << endl;

	cout << "Number of Nodes: " << tree2.numberOfNodes() << endl;

	if (tree2.isBalanced())
	{
		cout << "Is the BST balanced: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST balanced: " << "False " << endl;
	}

	if (tree2.isCompleted())
	{
		cout << "Is the BST completed: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST completed: " << "False " << endl;
	}

	cout << "--------------------------------------------------" << endl;

	BinarySearchTree tree3;

	tree3.LoadBST("test3.txt");

	tree3.display();

	cout << "Smallest Branch Height is: " << tree3.findMinHeight() << endl;

	cout << "Largest Branch Height is: " << tree3.findMaxHeight() << endl;

	cout << "Number of Nodes: " << tree3.numberOfNodes() << endl;

	if (tree3.isBalanced())
	{
		cout << "Is the BST balanced: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST balanced: " << "False " << endl;
	}

	if (tree3.isCompleted())
	{
		cout << "Is the BST completed: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST completed: " << "False " << endl;
	}

	BinarySearchTree tree4;

	tree4.LoadBST("test4.txt");

	tree4.display();

	cout << "Smallest Branch Height is: " << tree4.findMinHeight() << endl;

	cout << "Largest Branch Height is: " << tree4.findMaxHeight() << endl;

	cout << "Number of Nodes: " << tree4.numberOfNodes() << endl;

	if (tree4.isBalanced())
	{
		cout << "Is the BST balanced: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST balanced: " << "False " << endl;
	}

	if (tree4.isCompleted())
	{
		cout << "Is the BST completed: " << "True " << endl;
	}
	else
	{
		cout << "Is the BST completed: " << "False " << endl;
	}
}