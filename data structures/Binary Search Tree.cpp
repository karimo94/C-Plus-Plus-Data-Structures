#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

//BST in C++
//Written by: Karim Oumghar
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
		~Node(void)
        {
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
	~BST(void)
	{
        FlushAll(root);
        root = NULL;
	};

public:
	void Add(int data)
	{
        Node *nObj = new Node(data);
        if(root == NULL)
        {
            root = nObj;
            return;
        }
        else
        {
            Node *cur = root;
            while(cur != NULL)
            {
                if(data < cur->data)
                {
                    if(cur->left == NULL)
                    {
                        cur->left = nObj;
                        break;
                    }
                    if(cur->left != NULL)
                    {
                        cur = cur->left;
                    }
                }
                if(data > cur->data)
                {
                    if(cur->right == NULL)
                    {
                        cur->right = nObj;
                        break;
                    }
                    if(cur->right != NULL)
                    {
                        cur = cur->right;
                    }
                }
            }
        }
		itemCount++;
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
		return;
	}
	void Remove(int data)//remove recursively
	{
		if(isEmpty() == true || Find(data) == false)//if we dont find it, then no deletion
		{
			cout<<"Value not found to delete"<<endl;
		}
		else
		{
            cout<<RemoveTarget(data)<<" was deleted from the tree"<<endl;
            itemCount--;
		}
		return;
	}
	bool Find(int target)
	{//if tree is not empty and we found our target
        if(isEmpty() != true && FindTarget(target) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
	}
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
private:
	void PrintInOrder(Node *current)//a private recursive print method
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

	bool FindTarget(int target)
	{/*this private method will print whether a vlaue was found or not and return true or false*/
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
            return true;
        }
        else
        {
            cout<<"Nothing found!"<<endl;
            return false;
        }
	}
	int RemoveTarget(int target)
	{
        int temp;//value to return (the deleted value)
        Node* targetNode = GoToTarget(target);

        //case 1: removing the root node
        if(targetNode == root)
        {
            if(targetNode->left == NULL && targetNode->right == NULL)
            {
                temp = root->data;
                delete targetNode;
                targetNode = NULL;
                return temp;
            }
            if(targetNode->left != NULL)
            {
                //replace the top node with the left node
                //delete left node
                Node* current = root->left;
                temp = root->data;
                if(root->left->right == NULL)//if theres no right child to the left child
                {root->data = root->left->data;}
                else//if there is, we go right until we reach a null right ptr
                {
                    while(current != NULL)
                    {
                        if(current->right->right == NULL)
                        {
                        	root->data = current->right->data;
                        	break;
                        }
                        current = current->right;
                    }
                    if(current->right != NULL)
                    {
                    	current->right = current->right->right;
                    }
                    else
                    {
                    	delete current->right;
                    	current->right = NULL;
                    }
                    return temp;//once we're done with deletion we return the value deleted
                }
                if(root->left->left == NULL)
                {
                    root->left = NULL;
                }
                else{root->left = root->left->left;}
                return temp;
            }
            if(targetNode->right != NULL)//if we have no left node to the root
            {
                temp = root->data;
                root->data = root->right->data;
                if(root->right->right == NULL)
                {
                    root->right = NULL;
                }
                else{root->right = root->right->right;}
                return temp;
            }
        }
        //case 2, removing non root nodes, target will have: 0, 1, or 2 children

        //target has 0 children
        if(targetNode->left == NULL && targetNode->right == NULL)
        {
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
            temp = targetNode->data;
            ParentOfTarget(targetNode)->left = targetNode->left;
            return temp;
        }
        if(targetNode->right != NULL && targetNode->left == NULL)
        {
            temp = targetNode->data;
            //if parent happens to be the root...
            if(ParentOfTarget(targetNode) == root)
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
	Node* GoToTarget(int data)//this will go to the target node, and return that node
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
    void FlushAll(Node *cur)
    {
        if(cur == NULL)
        {
            return;
        }
        else
        {
            FlushAll(cur->left);
            FlushAll(cur->right);
            delete cur;
            cur = NULL;
        }
    }
};
