#include <iostream>
#include <vector>

#include "MergeSort.h"
#include "QuickSort.h"

// 분할(divide) : 주어진 문제를 동일한 방식으로 해결할 수 있는 부분 문제로 나누고
// 정복(conquer) : 각 부분 문제에 대한 솔루션을 구하고
// 결합(combine) : 각 부분 문제의 솔루션을 결합하여 전체 문제의 솔루션을 구하기

int main()
{
    std::vector<int> Arr = { 2, 4, 6, 7, 1, 3, 5, 8 };
    //std::vector<int> Result = MergeSort(Arr);
    //for (int i = 0; i < Result.size(); i++)
    //{
    //    std::cout << Result[i] << ", ";
    //}

    QuickSort(Arr, 0, 7);
    for (int i = 0; i < Arr.size(); i++)
    {
        std::cout << Arr[i] << ", ";
    }
}