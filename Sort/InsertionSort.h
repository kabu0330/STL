#pragma once
#include <utility>
#include <vector>

// 삽입 정렬은 정렬되지 않은 첫 번째 원소부터 정렬된 부분의 알맞은 위치에 삽입
void InsertionSort(std::vector<int>& data, int n)
{
	// 핵심은 정렬할 값을 임시 저정할 변수를 선언하고
	// 해당하는 자리를 찾으면 정렬할 자리부터 오른쪽 값을 모두 한칸씩 오른쪽으로 복사시키고
	// Key값을 그 자리에 삽입한다.

	for (int i = 1; i < n; i++)
	{
		int Key = data[i]; // 정렬할 값
		int j = i - 1; // 검색을 시작할 원소
		int Left = data[j]; 
		while (j >= 0 && data[j] > Key)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = Key;
	}
}