#pragma once
#include <utility>
#include <vector>

// 매번 가장 작은 값을 선택해서 맨 왼쪽부터 정렬하는 방식
void SelectionSort(std::vector<int>& data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int Index = i; // 스왑을 하고 나면 앞쪽 칸을 더 이상 순회하지 않는다.
		// 앞쪽은 정렬의 결과 작은 값이 들어갔으니까.

		for (int j = i + 1; j < n ; j++)
		{
			int Left = data[Index];
			int Right = data[j];

			if (Right < Left)
			{
				// 우측의 값이 더 작으면 그 녀석의 Index를 기억하고 
				// 그 다음 우측의 값과 다시 비교
				Index = j; 
			}
		}
		// 맨 오른쪽까지 다 돌고 나서 현재 위치랑 저장한 인덱스를 교환
		
		std::swap(data[i], data[Index]);
	}
}