#ifndef _DLLIST_H
#define _DLLIST_H

class Node
{
  public:
     int data;
     Node *next, *prev;
  
  Node(int num): data{num}, next{nullptr}, prev{nullptr} {}
};

class DLList
{
  private:
  Node *head, *tail;
  public:
  DLList(): head{nullptr}, tail{nullptr} {}
  ~DLList() 
  {
    Node *current = head;
    while(current)
    {
      Node *nextnode = current->next;
      delete current;
      current = nextnode;
    }
    head = tail = nullptr;
  }
  
  void add_to_head(int);
  void add_to_tail(int);
  void delete_from_head();
  void delete_from_tail();
  void delete_node(int);
  void display() const;
};

#endif
