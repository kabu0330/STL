#pragma once
#include <utility>
#include <vector>

// 맨 끝에서부터 인접한 두 값을 비교해서 작은 값을 맨 앞으로 이동시키는 행위가
// 마치 작은 거품처럼 위로 떠오른다고 하여 버블 정렬
void BubbleSort(std::vector<int>& data, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		// data[n-1]부터 data[i]까지 이동하면서 비교&교환
		for (int j = n - 1; j > i; j--)
		{
			int Right = data[j];
			int Left = data[j - 1];
			if (Right < Left)
			{
				std::swap(data[j], data[j - 1]);
			}
		}
	}
}
