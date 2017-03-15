#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;
//Queue in C++
//Written by: Karim Oumghar
class Queue
{
    class Node
    {
    public:
        Node* next;
        int data;
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
        ~Node(void){};//destructor
    };
    private:
        Node* front;
        Node* end;

    public:
        Queue()
        {
            front = NULL;
            end = NULL;
        }
        ~Queue(void)
        {
            RemoveAll();
        };
        bool isEmpty()
        {
            if(front == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void Enqueue(int data)
        {
            Node* newItem = new Node(data);

            if(isEmpty())
            {
                end = newItem;
                front = newItem;
            }
            else
            {
                end->next = newItem;
                end = newItem;
            }
        }
        int Dequeue()
        {
            int valueToReturn;
            Node *nodeToDelete = front;
            if(isEmpty())
            {
                return 0;
            }
            else
            {
                valueToReturn = nodeToDelete->data;
                front = front->next;
                delete nodeToDelete;
                nodeToDelete = NULL;
                return valueToReturn;
            }
        }
        void DisplayQueue()
        {
            Node* current = front;
            while(current != NULL)
            {
                cout<<current->data<<" ";
                current = current->next;
            }
        }
        void RemoveAll()
        {
            if(!isEmpty())
            {
                RemoveAll(front);
                end = NULL;
            }
        }
    private:
        void RemoveAll(Node *cur)
        {
            if(cur->next == NULL)
            {
                return;
            }
            else
            {
                RemoveAll(cur->next);
                delete cur;
            }
        }
};
