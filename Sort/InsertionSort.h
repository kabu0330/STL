#pragma once
#include <utility>
#include <vector>

// ���� ������ ���ĵ��� ���� ù ��° ���Һ��� ���ĵ� �κ��� �˸��� ��ġ�� ����
void InsertionSort(std::vector<int>& data, int n)
{
	// �ٽ��� ������ ���� �ӽ� ������ ������ �����ϰ�
	// �ش��ϴ� �ڸ��� ã���� ������ �ڸ����� ������ ���� ��� ��ĭ�� ���������� �����Ű��
	// Key���� �� �ڸ��� �����Ѵ�.

	for (int i = 1; i < n; i++)
	{
		int Key = data[i]; // ������ ��
		int j = i - 1; // �˻��� ������ ����
		int Left = data[j]; 
		while (j >= 0 && data[j] > Key)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = Key;
	}
}