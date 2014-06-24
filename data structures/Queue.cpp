#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;
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
            if(isEmpty())
            {
                return 0;
            }
            else
            {
                valueToReturn = front->data;
                front = front->next;
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
};
