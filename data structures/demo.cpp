// demo.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;


class BST
{
	class Node
	{
		public:
		int data;
		Node *left;
		Node *right;

		Node(int data)
		{
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		};
	};
	private:
	Node *root;
	int itemCount;
	public:
	BST()
	{
		root = NULL;
		itemCount = 0;
	}
public:
	void Add(int data)//Add recursively
	{
		AddRecursively(data, root);
	}
	void PrintInOrder()//print recursively
	{
		if(isEmpty())
		{
			cout<<"Nothing to print"<<endl;
		}
		else
		{
			PrintInOrder(root);
		}
	}
	void Remove(int data)//remove recursively
	{
		if(isEmpty() == true)
		{
			cout<<"Nothing to delete"<<endl;
		}
		else
		{
            cout<<RemoveTarget(data)<<" was deleted from the tree"<<endl;
		}
	}
	void Find(int target)
	{
        if(isEmpty() != true)//if tree is not empty
        {
            FindTarget(target);
        }
        else
        {
            return;
        }
	}
private:
	void PrintInOrder(Node *current)
	{
		if(isEmpty())
		{
			cout<<"Nothing to print!"<<endl;
		}
		if(current != NULL)
		{
			PrintInOrder(current->left);
			cout<<"("<<current->data<<") ";
			PrintInOrder(current->right);
		}
	};
	Node* AddRecursively(int data, Node* traversal)
	{
		Node* newItem = new Node(data);
		if(isEmpty())
		{
			root = newItem;
		}
		else
		{
			if(newItem->data < traversal->data)
			{
				if(traversal->left == NULL)
				{
					traversal->left = newItem;
				}
				else
				{
					return AddRecursively(data, traversal->left);
				}
			}
			if (newItem->data > traversal->data)
			{
				if(traversal->right == NULL)
				{
					traversal->right = newItem;
				}
				else
				{
				    return AddRecursively(data, traversal->right);
				}
			}
			else
			{
				return NULL;
			}
		}
	};
	bool isEmpty()
	{
		if(root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	void FindTarget(int target)
	{
	    bool isFound = false;
        Node * current = root;
        while(current != NULL && isFound == false)
        {
            if(current->data == target)
            {
                isFound = true;
            }
            if(target < current->data)
            {
                if(current->left == NULL)
                {
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            if(target > current->data)
            {
                if(current->right == NULL)
                {
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
        if(isFound == true)
        {
            cout<<target<<" was found"<<endl;
        }
        else
        {
            cout<<"Nothing found!"<<endl;
        }
        return;
	}
	int RemoveTarget(int target)
	{
        int temp;
        Node* targetNode = GoToTarget(target);
        //case 1: removing the root node
        if(targetNode == root)
        {
            if(targetNode->left == NULL && targetNode->right == NULL)
            {
                temp = root->data;
                root = NULL;
                return temp;
            }
            if(targetNode->left != NULL)
            {
                //replace the top node with the left node
                //delete left node
                root->data = root->left->data;
                if(root->left->left == NULL)
                {
                    root->left = NULL;
                }
                else{root->left = root->left->left;}
                return root->data;
            }
            if(targetNode->right != NULL)//if we have no left node to the root
            {
                root->data = root->right->data;
                if(root->right->right == NULL)
                {
                    root->right = NULL;
                }
                else{root->right = root->right->right;}
                return root->data;
            }
        }
        //case 2, removing non root nodes, target will have:0, 1, or 2 children
        if(targetNode->left == NULL && targetNode->right == NULL)
        {
            //target has 0 children
            if(ParentOfTarget(targetNode)->left == targetNode)
            {
                temp = targetNode->data;
                ParentOfTarget(targetNode)->left = NULL;
            }
            else
            {
                temp = targetNode->data;
                ParentOfTarget(targetNode)->right = NULL;
            }
            return temp;
        }
        //target has 1 child----------------------------------------
        if(targetNode->left != NULL && targetNode->right == NULL)
        {
            ParentOfTarget(targetNode)->left = targetNode->left;
            return temp;
        }
        if(targetNode->right != NULL && targetNode->left == NULL)
        {
            temp = targetNode->data;
            //if parent happens to be the root...
            if(ParentOfTarget(targetNode)==root)
            {
                ParentOfTarget(targetNode)->left = targetNode->right;
            }
            else
            {
                ParentOfTarget(targetNode)->right = targetNode->right;
            }
            return temp;
        }
        //target has 2 children------------------------------------------
        if(targetNode->left != NULL && targetNode->right != NULL)
        {
            if(ParentOfTarget(targetNode)->left == targetNode)
            {
                //target node left child data will replace target node data
                temp = targetNode->data;
                targetNode->data = targetNode->left->data;
                targetNode->left = NULL;
                return temp;
            }
            else
            {
                temp = targetNode->data;
                targetNode->data = targetNode->left->data;
                //check if target node left child of left child is not null
                if(targetNode->left->left != NULL)
                {
                    targetNode->left = targetNode->left->left;
                }
                else
                {
                    targetNode->left = NULL;
                }
                return temp;
            }
        }
        return 0;
	};
	Node* GoToTarget(int data)//this will go to the target node, and return that node, problem here...
	{
		Node* current = root;
		Node* target = NULL;

        while(current != NULL)
        {
            if(data < current->data)
            {
                current = current->left;
            }
            if(data == current->data)
            {
                target = current;
                break;
            }
            if(data > current->data)
            {
                current = current->right;
            }

        }
        return target;

	};
    Node* ParentOfTarget(Node* target)//this will visit the parent node of the target node
    {
        Node* current = root;
        Node* parent = NULL;
        while(current != NULL)
        {
            if(current->left == target || current->right == target)
            {
                parent = current;
                break;
            }
            if(target->data < current->data && current->left != target)
            {
                current = current->left;
            }
            if(target->data > current->data && current->right != target)
            {
                current = current->right;
            }
        }
        return parent;
    }
};
//int _tmain(int argc, _TCHAR* argv[])
//{
//	printf("Hello World, ");
//	printf("enter your name: ");
//	string name;
//	cin>>name;
//	cout<<name<<" ";
//	int x,y, function;
//	printf("enter a value 1: ");
//
//	cin>>x;
//	printf("enter value 2: ");
//
//	cin>>y;
//	function = x + y;
//	cout<<function;
//	X();
//
//	LinkedList ll;
//	ll.AddItem(5);
//	ll.AddItem(35);
//	ll.AddItem(76);
//	ll.AddItem(44);
//	ll.AddItem(-1);
//	ll.PrintList();
//
//	ll.RemoveItem(5);
//	cout<<"Removed 5"<<endl;
//	ll.PrintList();
//
//	ll.RemoveItem(-1);
//	cout<<"Removed -1"<<endl;
//	ll.PrintList();
//
//	ll.RemoveItem(76);
//    cout<<"Removed 76"<<endl;
//	ll.PrintList();
//	cout<<endl;
//
//	BST tree;
//	tree.Add(5);
//	tree.Add(3);
//	tree.Add(7);
//	tree.Add(2);
//	tree.Add(4);
//	tree.Add(6);
//	tree.Add(8);
//	tree.PrintInOrder();
//	tree.Remove(2);
//	tree.Remove(7);
//	tree.PrintInOrder();
//
//	system("pause");
//
//};
