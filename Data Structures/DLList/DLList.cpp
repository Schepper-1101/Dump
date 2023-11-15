#include <iostream>
#include "DLList.h"

void DLList::add_to_head(int num)
{
   Node *newnode = new Node(num);
   if(head)
   {
     newnode->next = head;
     head->prev = newnode;
     head = newnode;
   }
   else
    head = tail = newnode;
}

void DLList::add_to_tail(int num)
{
  Node *newnode = new Node(num);
  if(tail)
  {
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
  }
  else 
   head = tail = newnode;
}

 void DLList::delete_from_head() {
        if (!head) {
            std::cout << "List is empty. Cannot delete from head." << std::endl;
            return;
        }

        Node* temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = tail = nullptr;
        }

        delete temp;
}
    
void DLList::delete_from_tail() {
        if (!tail) {
            std::cout << "List is empty. Cannot delete from tail." << std::endl;
            return;
        }

        Node* temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = tail = nullptr;
        }

        delete temp;
}

void DLList::delete_node(int value) {
        Node* current = head;

        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }

            current = current->next;
        }

        std::cout << "Element not found in the list." << std::endl;
}

void DLList::display() const
{
  Node *current = head;
  while(current)
  {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

int main()
{
  DLList list;
  list.add_to_tail(5);
  list.add_to_head(7);
  list.add_to_head(98);
  list.add_to_tail(74);
  list.add_to_tail(3);
  list.add_to_head(45);
  
    std::cout << "Original List: ";
    list.display();
    
    list.delete_node(3);
    list.delete_node(5);

    std::cout << "List after deletion: ";
    list.display();
    
     list.delete_from_head();
    std::cout << "List after deleting from head: ";
    list.display();

    list.delete_from_tail();
    std::cout << "List after deleting from tail: ";
    list.display();
}
