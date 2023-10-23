#include <iostream>
#include <climits>

struct Queue
{
    int front{-1}, rear{-1}, arr[5] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    void _insert(const int &num); // Function to input
    void _delete();               // Function to delete
};

void gotoxy(short x, short y) // This function is to move the cursor
{
    std::cout << "\033[" << x << ";" << y << "H";
}

int main()
{
    Queue queue;
up:
    system("clear"); // It will clear the screen
    while (1)
    {
        gotoxy(2, 6);
        std::cout << "+------------------------------------------+" << std::endl;
        gotoxy(3, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(4, 6);
        std::cout << "|  |  " << (queue.arr[4] == INT_MAX ? "    " : std::to_string(queue.arr[4])); // Using ternary Operator
        gotoxy(4, 16);
        std::cout << "|  1. For Insert Operation       |" << std::endl;
        gotoxy(5, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(6, 6);
        std::cout << "|  |  " << (queue.arr[3] == INT_MAX ? "    " : std::to_string(queue.arr[3]));
        gotoxy(6, 16);
        std::cout << "|                                |" << std::endl;
        gotoxy(7, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(8, 6);
        std::cout << "|  |  " << (queue.arr[2] == INT_MAX ? "    " : std::to_string(queue.arr[2]));
        gotoxy(8, 16);
        std::cout << "|  2. For Delete Operation       |" << std::endl;
        gotoxy(9, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(10, 6);
        std::cout << "|  |  " << (queue.arr[1] == INT_MAX ? "    " : std::to_string(queue.arr[1]));
        gotoxy(10, 16);
        std::cout << "|                                |" << std::endl;
        gotoxy(11, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(12, 6);
        std::cout << "|  |  " << (queue.arr[0] == INT_MAX ? "    " : std::to_string(queue.arr[0]));
        gotoxy(12, 16);
        std::cout << "|  3. Exit                       |" << std::endl;
        gotoxy(13, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(14, 6);
        std::cout << "+------------------------------------------+" << std::endl;
        gotoxy(15, 6);
        std::cout << "> ";

        int choice{0};
        do
        {
            if (choice != 0)
            {
                system("clear");
                std::cout << "Invalid Input. Please try again." << std::endl;
                std::cin.ignore();
                std::cin.get();
                goto up;
            }
            std::cin >> choice;
        } while (choice < 1 || choice > 3);

        switch (choice)
        {
        case 1:
        {
            int num{};
            std::cout << "Enter the number: ";
            std::cin >> num;
            queue._insert(num);
        }
        break;
        case 2:
            queue._delete();
            break;
        default:
            exit(0);
            break;
        }
        system("clear");
    }
}

void Queue::_insert(const int &num)
{
    if (front <= rear && rear < 4)
    {
        arr[++rear] = num;
        if(front == -1)
        {
            ++front;
        }
    }
    else
    {
        std::cerr << "Queue is full." << std::endl;
        std::cin.ignore();
        std::cin.get();
    }
}

void Queue::_delete()
{
    if (front > -1 && front <= rear)
        arr[front++] = INT_MAX;
    else
    {
        std::cerr << "Queue is empty." << std::endl;
        front = rear = -1;
        std::cin.ignore();
        std::cin.get();
    }
}