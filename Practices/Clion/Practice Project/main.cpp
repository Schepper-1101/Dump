#include <iostream>
#include <vector>

int main()
{
    int n, temp;
    std::cin >> n;
    temp = n;
    std::cout << temp;
    while (n > 9)
    {
        std::vector<int> v;
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            v.push_back(n % 10);
            n /= 10;
        }
        std::cout << " -->  ";
        for (int i = v.size(); i > 0; i--)
        {
            std::cout << v[i - 1];
            if (i != 1)
                std::cout << " + ";
            else
                std::cout << " = ";
        }
        std::cout << sum;
        n = sum;
    }
    std::cout << "\n";
}
