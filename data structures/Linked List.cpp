
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;
//Linked List in C++
//Written by: Karim Oumghar
class Node
{
public:
    int data;
    Node *next;
    //add a constructor here
    Node(int data)//done
    {
        this->data = data;
        next = NULL;
    };
    ~Node(void){};//destructor
};

class LinkedList
{

        Node *first;//these also must be pointers

    public:
        LinkedList()//constructor for the LinkedList
        {
            //initiliazation is needed
            first = NULL;
        };
        ~LinkedList()
        {
            //destructor
            RemoveAll();

        };
        void AddItem(int data)
        {
            Node *newItem = new Node(data);

            if(first == NULL)
            {
                first = newItem;
                return;
            }
            else
            {
                Node *temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newItem;
                return;
            }
        }
        void RemoveItem(int itemToRemove)
        {
            Node *traversal = first;
            Node *temp;
            bool isRemoved = false;
            while(traversal->next != NULL && !isRemoved)
            {

                if(traversal->next->data == itemToRemove)
                {
	                temp = traversal->next;
                    traversal->next = temp->next;
                    delete temp;
                    temp=NULL;
                    isRemoved = true;
                    break;
                }
                else
                {
                    traversal = traversal->next;
                }
            }

        }
        void RemoveFirst()
        {
            Node *temp = first;
            first = first->next;
            delete temp;
            temp = NULL;
        }
        void RemoveAll()
        {
            RemoveAll(first);
            first = NULL;
        }
        void RemoveLast()
        {
            //if theres only 1 item in the list
            if(first->next == NULL)
            {
                RemoveFirst();
                return;
            }

            Node *traversal = first;
            Node *temp = NULL;
            while(traversal->next->next != NULL)
            {
                traversal = traversal->next;
            }
            temp = traversal->next;
            delete temp;
            temp = NULL;
            traversal->next = NULL;
        }
        void DisplayList() const
        {
            cout<<endl;
            Node *traversal = first;
            while(traversal != NULL)
            {
                cout<<"["<<traversal->data<<"] ";
                traversal = traversal->next;
            }
            traversal = NULL;
        }
        bool isEmpty() const
        {
            if(first == NULL)
            {
                cout<<"List is empty";
                return true;
            }
            else
            {
                cout<<"List is not empty";
                return false;
            }
        }
    private:
        void RemoveAll(Node *current)
        {
            if(current == NULL)
            {
                return;
            }
            else
            {
                RemoveAll(current->next);
                delete current;
            }
        }
};

