#pragma once
#include <utility>
#include <vector>

// �Ź� ���� ���� ���� �����ؼ� �� ���ʺ��� �����ϴ� ���
void SelectionSort(std::vector<int>& data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int Index = i; // ������ �ϰ� ���� ���� ĭ�� �� �̻� ��ȸ���� �ʴ´�.
		// ������ ������ ��� ���� ���� �����ϱ�.

		for (int j = i + 1; j < n ; j++)
		{
			int Left = data[Index];
			int Right = data[j];

			if (Right < Left)
			{
				// ������ ���� �� ������ �� �༮�� Index�� ����ϰ� 
				// �� ���� ������ ���� �ٽ� ��
				Index = j; 
			}
		}
		// �� �����ʱ��� �� ���� ���� ���� ��ġ�� ������ �ε����� ��ȯ
		
		std::swap(data[i], data[Index]);
	}
}