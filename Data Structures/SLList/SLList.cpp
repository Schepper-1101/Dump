#include <iostream>
#include "SLList.h"

int main()
{
	system("clear");
	SLList *list = new SLList();

    while(1)
    {
    std::cout << "1. Add to head\n";
    std::cout << "2. Add to tail\n";
    std::cout << "3. Add node at specific index\n";
    std::cout << "4. Delete from head\n";
    std::cout << "5. Delete from tail\n";
    std::cout << "6. Delete node from specific index\n";
    std::cout << "7. Delete node\n";
    std::cout << "8. Is in list\n";
    std::cout << "9. Display list\n";
    std::cout << "10. Exit\n";
    std::cout << "> ";
    int choice{};
    std::cin >> choice;

    	switch(choice)
    	{
    	case 1:
    		{
    			system("clear");
    		    std::cout << "Enter the number: ";
    		    int num{};
    		    std::cin >> num;
                list->addToHead(num);
                std::cout << "[List after operation] ";
                list->displayList();
                break;
    		}
    	case 2:
    		{
    			system("clear");
    		    std::cout << "Enter the number: ";
    		    int num{};
    		    std::cin >> num;
                list->addToTail(num);
                std::cout << "[List after operation] ";
                list->displayList();
                break;
    		}
    	case 3:
    		{
    			system("clear");
    			int num{}, index{};
    		    std::cout << "Enter the number: ";
    		    std::cin >> num;
    		    std::cout << "Enter the index: ";
    		    std::cin >> index;
                list->addNodeatIndex(num, index);
                std::cout << "[List after operation] ";
                list->displayList();
                break;    			
    		}
    	case 4:
    		{
    			system("clear");
    			list->deleteFromHead();
    			std::cout << "[List after operation] ";
                list->displayList();
    			break;
    		}
    	case 5:
    		{
    			system("clear");
    			list->deleteFromTail();
                std::cout << "[List after operation] ";
                list->displayList();
    			break;
    		}
    	case 6:
    		{
                system("clear");
    			int index{};
    		    std::cout << "Enter the index: ";
    		    std::cin >> index;
                list->deleteNodefromIndex(index);
                std::cout << "[List after operation] ";
                list->displayList();
                break;   
    		}
    	case 7:
    		{
               system("clear");
               std::cout << "Enter the number: ";
               int num{};
               std::cin >> num;
               list->deleteNode(num);
                std::cout << "[List after operation] ";
                list->displayList();
               break;
    		}
       	case 8:
       		{
               system("clear");
               std::cout << "Enter the number: ";
               int num{};
               std::cin >> num;
               if(list->isInList(num))
               {
               	 std::cout << num << " is in the list" << std::endl;
               }
               else
               {
               	 std::cout << num << " is not in the list" << std::endl;
               }
               std::cin.ignore();
               std::cin.get();
               break;
       		}
    	case 9:
            {
            	system("clear");
            	std::cin.ignore();
            	std::cout << "[List] ";
            	list->displayList();
            	break;
            }
        case 10:
        	exit(0);
    	default:
    		system("clear");
    		std::cout << "[Message] Invalid Input! Please Try Again." << std::endl;
    		std::cin.get();
    	}
    }

}

void SLList::addToHead(int num)
{
	head = new Node(num, head);
    if(tail == nullptr)
    {
    	tail = head;
    }
    std::cout << "[Message] " << num << " was succesfully added to the list.";
    std::cin.ignore();
    std::cin.get();
    system("clear");
}

void SLList::addToTail(int num)
{
	if(tail == nullptr)
	head = tail = new Node(num);
    else
    {
       tail->next = new Node(num);
       tail = tail->next;
    }
    std::cout << "[Message] " << num << " was succesfully to from the list." << std::endl;
    std::cin.get();
    system("clear");
}

void SLList::deleteFromHead()
{
    if(head == nullptr)
    {
    	system("clear");
    	std::cout << "[Message] List is empty." << std::endl;
    }
    else
    {
        int num = head->data;
        Node *temp = head;
        if(head == tail)
        {
        	head = tail = nullptr;
        }
        else
        {
        	head = head->next;
        }
        delete temp;
        std::cout << "[Message] " << num << " was succesfully deleted from the list." << std::endl;
        std::cin.get();
        system("clear");
    }
}

void SLList::deleteFromTail()
{
    if(tail == nullptr)
    {
    	system("clear");
    	std::cout << "[Message] List is empty." << std::endl;
    }
    else
    {
        int num = tail->data;
        Node *temp = tail;
        if(head == tail)
        {
        	head = tail = nullptr;
            delete temp;
        }
        else
        {
        	temp = head;
        	while(temp->next != tail)
        	{
        		temp = temp->next;
        	}
        	delete tail;
        	tail = temp;
        	tail->next = nullptr;
        }
        std::cout << "[Message] " << num << " was succesfully deleted from the list." << std::endl;
        std::cin.get();
        system("clear");
    }
}

void SLList::addNodeatIndex(int num, int index)
{
    Node *curr = head;
    if(index == 0)
    {
    	curr = new Node(num);
    	curr->next = head;
    	head = curr;
    }
    else
    {
    	for(int i = 0; i < index - 1; ++i)
    	{
    		if(curr == nullptr)
    		{
    			std::cout << "[Message] Index out of bounds." << std::endl;
    			std::cin.ignore();
    			std::cin.get();
                return;
    		}
    		curr = curr->next;
    	}

    	    if(curr == nullptr)
    		{
    			std::cout << "[Message] Index out of bounds." << std::endl;
    			std::cin.ignore();
    			std::cin.get();
                return;
    		}
         Node *temp = new Node(num);
         temp->next = curr->next;
         curr->next = temp;

    }

    std::cout << "[Message] " << num << " was succesfully added to the list." << std::endl;
    std::cin.get();
    system("clear");
}

void SLList::deleteNodefromIndex(int index)
{
    if (index < 0)
    {
        std::cout << "[Message] Invalid index." << std::endl;
        std::cin.get();
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;

    for (int i = 0; i < index; ++i)
    {
        if (curr == nullptr)
        {
            std::cout << "[Message] Index out of bounds." << std::endl;
            std::cin.ignore();
            std::cin.get();
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        std::cout << "[Message] Index out of bounds." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return;
    }

    if (prev == nullptr)
    {
        // Deleting the first node
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    int num = curr->data;
    delete curr;

    std::cout << "[Message] " << num << " was successfully removed from the list." << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
}

void SLList::deleteNode(int num)
{
    if (head == nullptr)
    {
        system("clear");
        std::cout << "[Message] List is empty." << std::endl;
        std::cin.get();
        return;
    }

	Node *curr = head, *prev = nullptr;
	bool _isFound = false;
	while(curr != nullptr)
	{
		if(num = curr->data)
		{
			_isFound = true;
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	if(!_isFound)
	{
      system("clear");
      std::cout << "[Message] Element not found." << std::endl;
      std::cin.get();
      return;
	}
    
     if (prev == nullptr)
    {
        // Deleting the first node
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    int removedNum = curr->data;
    delete curr;

    std::cout << "[Message] " << num << " was successfully deleted from the list." << std::endl;
    std::cin.ignore();
    std::cin.get();

}

bool SLList::isInList(int num) 
{
   if (head == nullptr)
    {
        return false;
    }

	Node *curr = head, *prev = nullptr;
	bool _isFound = false;
	for(;curr != nullptr;)
	{
		if(num == curr->data)
		{
           return true;
		}
		prev = curr;
		curr = curr->next;
	}
    return false;
}

void SLList::displayList()
{
    Node *curr = head;
    while(curr != nullptr)
    {
       std::cout << curr->data << " ";
       curr = curr->next;
    }
    std::cin.get();
    system("clear");
}
