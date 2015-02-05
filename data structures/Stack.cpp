#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;
//Stack in C++
//Written by: Karim Oumghar
class Stack
{
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
    //implement the stack class here using linked lists
    /*make this non visible to anything outside,
    llstack is short for linkedliststack*/

    /*most of the implementation will be done here*/
    private:
    Node *topOfStack;
    int itemCount;
    public: Stack()
    {
        topOfStack = NULL;
        itemCount = 0;
    }
    ~Stack(void){};//destructor
    void Push(int data)
    {
        Node *newObject = new Node(data);
        if(IsEmpty())
        {
            topOfStack = newObject;
        }
        else
        {
            newObject->next = topOfStack;
            topOfStack = newObject;
            itemCount++;
        }
    }
    int Pop()
    {
        if(IsEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else
        {
            Node *removed = topOfStack;
            topOfStack = topOfStack->next;
            itemCount--;
            return removed->data;
        }
    }
    void Display()
    {
        if(IsEmpty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            cout<<"\n";
            Node *current = topOfStack;
            while(current != NULL)
            {
                cout<<"["<<current->data<<"]\n";
                current = current->next;
            }
        }
    }
    int Peek()
    {
        return topOfStack->data;
    }
    bool IsEmpty()
    {
        if(topOfStack == NULL)
        {
            cout<<"Yes ";
            return true;
        }
        else{return false;}
    }
};

