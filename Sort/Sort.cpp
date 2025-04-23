#include <iostream>
#include <vector>

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

// 버블 정렬(Bubble Sort) : 맨 오른쪽부터 두 개의 값을 비교해서 가장 작은 값을 왼쪽으로 
// 선택 정렬(Selection Sort) : 매번 가장 작은 값을 찾아서 맨 왼쪽부터 하나씩 배치하는 방법
// 삽입 정렬(Insertion Sort) : 정렬되지 않은 첫 번째 원소부터 정렬된 부분의 알맞은 위치에 삽입
int main()
{
    std::vector<int> Arr = { 4, 2, 3, 5, 1 };
    //BubbleSort(Arr, 5);
    //SelectionSort(Arr, 5);
    InsertionSort(Arr, 5);
    for (int i = 0; i < Arr.size(); i++)
    {
        std::cout << Arr[i] << ", ";
    }

}