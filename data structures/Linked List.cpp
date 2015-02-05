
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
//declare instances of Nodes here

        Node *first;//these also must be pointers
        Node *last;
        int count;

    public:
        LinkedList()//constructor for the LinkedList
        {
            //initiliazation is needed (required)
            first = NULL;
            last = NULL;
            count = 0;
        };
        ~LinkedList(void){};//destructor
        void AddItem(int data)
        {
            Node *newItem = new Node(data);

            if(first == NULL)
            {
              first = newItem;
              last = newItem;
            }
            else
            {
                last->next = newItem;
                last = newItem;
            }
            count++;
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
            count--;
        }
        void RemoveFirst()
        {
            Node *temp = first;
            first = first->next;
            delete temp;
            temp=NULL;
            count--;
        }
        void RemoveLast()
        {
            Node *traversal = first;
            Node *temp = NULL;
            bool isRemoved = false;
            while(traversal->next != NULL && !isRemoved)//keep in mind, 0 is also NULL
            {

                if(traversal->next == last)
                {
	                temp = last;
	                last = traversal;
	                delete temp;
	                temp=NULL;
	                isRemoved = true;

                }
                else 	
                {
		          traversal = traversal->next;
                }
            }
            last->next = NULL;
            traversal = NULL;
            count--;

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
            traversal = nullptr;
        }
        bool isEmpty()
        {
            if(count < 1)
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
};

