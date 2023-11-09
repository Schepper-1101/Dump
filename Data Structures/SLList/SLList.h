#ifndef _SLLIST_H
#define _SLLIST_H

class  Node
{
public:
	int data;
	Node *next;

	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node(int d, Node *n = nullptr)
	{
       data = d;
       next = n;
	}
};

class SLList
{
private:
    Node *head, *tail;

public:
	SLList()
	{
		head = tail = nullptr;
	}
	~SLList()
	{
		for(Node *temp; head != nullptr;)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	void addToHead(int);
	void addToTail(int);
	void addNodeatIndex(int, int);
	void deleteFromHead();	
	void deleteFromTail();
	void deleteNodefromIndex(int);
	void deleteNode(int);
	bool isInList(int);
	void displayList();
};

#endif
