
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

int main()
{
	// 끝말잇기
	// car -> radio -> orange -> ear -> radio
	std::unordered_set<std::string> Words;
	Words.insert("car");
	Words.insert("radio");
	Words.insert("orange");
	Words.insert("ear");
	Words.insert("radio");

	std::string Word = "radio";
	if (Words.end() != Words.find(Word))
	{
		std::cout << Word << " is found" << std::endl;
	}
	else
	{
		std::cout << Word << " is not found" << std::endl;
	}

	// 중복되지 않은 숫자 개수를 카운트
	std::vector<int> Numbers{ 1, 5, 3, 1, 5, 7, 4, 5, 6, 3, 2, 7, 3, 6, 2 };
	std::unordered_set<int> NumSet(Numbers.begin(), Numbers.end());
	for (int Value : NumSet)
	{
		std::cout << Value << ", ";
	}
}
