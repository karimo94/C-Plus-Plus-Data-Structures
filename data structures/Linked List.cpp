
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
            Node *nextnext = NULL;
            while(traversal->next != NULL)
            {
                nextnext = traversal->next->next;
                if(traversal->next->data == itemToRemove)
                {
                    traversal->next = NULL;
                    traversal->next = nextnext;
                    break;
                }
                else
                {
                    traversal = traversal->next;
                }
            }
            count--;
        }
        void RemoveFirst()
        {
            Node *newFirst = first->next;
            first = NULL;
            first = newFirst;
            count--;
        }
        void RemoveLast()
        {
            int index = 1;
            Node *traversal = first;
            while(traversal->next != NULL)//keep in mind, 0 is also NULL
            {
                traversal = traversal->next;
                index++;
                if(index == count-1)
                {
                    break;
                }
            }
            last = traversal;
            traversal->next = NULL;
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

