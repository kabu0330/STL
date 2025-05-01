#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename _Ty>
void Print(const _Ty& _Container);

// 함수 포인터
bool Compare(const int& _Left, const int& _Right)
{
    return std::abs(_Left) < std::abs(_Right);
}

int main()
{
    std::vector<int> Vec = { 2, 5, -4, -1, 3 };
    std::sort(Vec.begin(), Vec.end(), Compare);
    Print(Vec);
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