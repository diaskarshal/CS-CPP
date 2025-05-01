#include <iostream>
 
int main()
{
    int n {5};
    int&& tempRef = std::move(n);   // преобразуем int в int&&
    std::cout << tempRef << std::endl; // 5
}