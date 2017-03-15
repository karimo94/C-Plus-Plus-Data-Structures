
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
            }
            else
            {
                Node *temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newItem;
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
                }
                else
                {
                    traversal = traversal->next;
                }
            }
            traversal=NULL;

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
        }
        void DisplayList()
        {
            cout<<endl;
            Node *traversal = first;
            while(traversal != NULL)
            {
                cout<<"["<<traversal->data<<"] ";
                traversal = traversal->next;
            }
            delete traversal;
            traversal = NULL;
        }
        bool isEmpty()
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
        void RemoveAll(Node *cur)
        {
            if(cur == NULL)
            {
                return;
            }
            else
            {
                RemoveAll(cur->next);
                delete cur;
                cur = NULL;
            }
        }
};

