#pragma once
#include <utility>
#include <vector>

// �� ���������� ������ �� ���� ���ؼ� ���� ���� �� ������ �̵���Ű�� ������
// ��ġ ���� ��ǰó�� ���� �������ٰ� �Ͽ� ���� ����
void BubbleSort(std::vector<int>& data, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		// data[n-1]���� data[i]���� �̵��ϸ鼭 ��&��ȯ
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
