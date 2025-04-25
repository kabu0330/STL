#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename _Ty>
void Print(const _Ty& _Container);

int main()
{
    int arr[5] = { 3, 4, 2, 5, 1};
    std::sort(std::begin(arr), std::end(arr)/*, std::greater<>()*/);
    Print(arr);

    std::vector<int> Vec = { 20, 50, 40, 10, 30 };
    std::sort(Vec.begin(), Vec.end(), std::greater<>());
    Print(Vec);

    std::vector<std::string> Fruits = { "orange", "banana", "melon", "apple" };
    std::sort(std::begin(Fruits), std::end(Fruits)/*, std::greater<>()*/);
    Print(Fruits);
    
}

template<typename _Ty>
void Print(const _Ty& _Container)
{
    size_t Size = std::size(_Container);

    for (size_t i = 0; i < Size; i++)
    {
        std::cout << i << " Index Value : " << _Container[i] << std::endl;
    }
    std::cout << std::endl;
}
