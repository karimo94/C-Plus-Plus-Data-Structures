#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;
//Doubly Linked list in C++
//Written by: Karim Oumghar
class Doubly_Linked_List
{
    class Node
    {
    public:
        int data;
        Node* next;
        Node* previous;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->previous = NULL;
        };
        ~Node(void){};//destructor
    };
private:
    Node* first;
public:
    Doubly_Linked_List()
    {
        first = NULL;
    }
    ~Doubly_Linked_List(void)
    {
        //destructor
        RemoveAll();
    };
    void Add(int data)
    {
        Node* newItem = new Node(data);
        if(IsEmpty() == true)
        {
            first = newItem;
        }
        else
        {
            Node *cur = first;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = newItem;
            newItem->previous = cur;
        }
    }
    void PrintForward()
    {
        Node* current = first;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    void PrintReverse()
    {
        Node* current = first;
        //go to the last
        while(current->next != NULL)
        {
            current = current->next;
        }
        //print in reverse
        while(current->previous != NULL)
        {
            cout<<current->data<<" ";
            current = current->previous;
        }
        cout<<endl;
    }
    bool Find(int target)
    {
        bool isFound = false;
        Node* current = first;
        while(current != NULL)
        {
            if(current->data == target)
            {
                isFound = true;
                break;
            }
            else{current = current->next;}
        }
        current = NULL;
        return isFound;
    }
    void Delete(int target)
    {
        if(target == first->data)
        {
            DeleteFirst();
        }
        else
        {
            Node* current = first;
            Node* temp = NULL;//node to delete
            while(current != NULL)
            {
                if(current->next->data == target)
                {
                    temp = current->next;//set temp to the target
                    //if we're not deleting the last thing...
                    if(temp->next != NULL)
                    {
                        current->next->next->previous = current;
                        current->next = temp->next;
                    }
                    else
                    {
                        current->next = NULL;
                    }
                    delete temp;
                    temp = NULL;

                    break;
                }
                else
                {
                    current = current->next;
                }
            }
        }
    }
private:
    bool IsEmpty()
    {
        if(first == NULL)
        {
            return true;
        }
        else{return false;}
    }
    void DeleteFirst()
    {
        Node* temp = first;
        first = first->next;
        delete temp;
        temp = NULL;
        first->previous = NULL;
    }
    void DeleteLast()
    {
        Node *temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp = temp->previous;
        Node *target = temp->next;
        delete target;
        target = NULL;
        temp->next = NULL;
    }
    void RemoveAll()
    {
        RemoveAll(first);
        first = NULL;
        
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
        }
    }
};
