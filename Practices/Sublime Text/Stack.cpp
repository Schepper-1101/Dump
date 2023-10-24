#include <iostream>
#include <climits>

struct Stack
{
    int top{-1}; // Uniform Initialization
    int arr[5] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    void push(const int &num); // Function to input
    void pop();                // Function to delete
};

void gotoxy(short x, short y) // This function is to move the cursor
{
    std::cout << "\033[" << x << ";" << y << "H";
}

int main()
{
    Stack stack;
up:
    system("clear"); // It will clear the screen
    while (1)
    {
        gotoxy(2, 6);
        std::cout << "+------------------------------------------+" << std::endl;
        gotoxy(3, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(4, 6);
        std::cout << "|  |  " << (stack.arr[4] == INT_MAX ? "    " : std::to_string(stack.arr[4])); // Using ternary Operator
        gotoxy(4, 16);
        std::cout << "|  1. For Push Operation         |" << std::endl;
        gotoxy(5, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(6, 6);
        std::cout << "|  |  " << (stack.arr[3] == INT_MAX ? "    " : std::to_string(stack.arr[3]));
        gotoxy(6, 16);
        std::cout << "|                                |" << std::endl;
        gotoxy(7, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(8, 6);
        std::cout << "|  |  " << (stack.arr[2] == INT_MAX ? "    " : std::to_string(stack.arr[2]));
        gotoxy(8, 16);
        std::cout << "|  2. For Pop Operation          |" << std::endl;
        gotoxy(9, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(10, 6);
        std::cout << "|  |  " << (stack.arr[1] == INT_MAX ? "    " : std::to_string(stack.arr[1]));
        gotoxy(10, 16);
        std::cout << "|                                |" << std::endl;
        gotoxy(11, 6);
        std::cout << "|  +------+                                |" << std::endl;
        gotoxy(12, 6);
        std::cout << "|  |  " << (stack.arr[0] == INT_MAX ? "    " : std::to_string(stack.arr[0]));
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
            stack.push(num);
        }
        break;
        case 2:
            stack.pop();
            break;
        default:
            exit(0);
            break;
        }
        system("clear");
    }
}

void Stack::push(const int &num)
{
    if (top < 4)
        arr[++top] = num;
    else
    {
        std::cerr << "Not enough space. Stack Overflow." << std::endl;
        std::cin.ignore();
        std::cin.get();
    }
}

void Stack::pop()
{
    if (top >= 0)
        arr[top--] = INT_MAX;
    else
    {
        std::cerr << "Stack is empty. Stack underflow." << std::endl;
        std::cin.ignore();
        std::cin.get();
    }
}