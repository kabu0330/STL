#include <iostream>
#include <list>

#include "UList.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    std::list<int> List;
	//List.erase(Iter);

	for (int i = 5; i < 10; i++)
	{
		List.push_back(i);
	}
	for (int i = 4; i >= 0; --i)
	{
		List.push_front(i);
	}
	//std::list<int> InsertListA = { 11, 22, 33 };
	std::list<int>::iterator Iter = List.begin();
	++Iter;
	//auto Result = List.insert(Iter, InsertListA.begin(), InsertListA.end());
	//++Result;
	List.insert(Iter, 100);
	
	for (int i = 0; i < 3; i++)
	{
		List.pop_back();
	}
	for (int i = 0; i < 2; i++)
	{
		List.pop_front();
	}
	

	UList MyList;


	//MyList.erase(StartIter);

	for (int i = 5; i < 10; i++)
	{
		MyList.push_back(i);
	}
	for (int i = 4; i >= 0; --i)
	{
		MyList.push_front(i);
	}

	UList::iterator StartIter = MyList.begin();
	UList::iterator EndIter = MyList.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		int Value = *StartIter;
		std::cout << "UList Value : " << Value << std::endl;
	}

	UList::iterator InsertIter = MyList.begin();
	++InsertIter;
	MyList.insert(InsertIter, 100);

	std::cout << std::endl;
	std::cout << "UList Insert Value : " << *(--InsertIter) << std::endl;


	for (int i = 0; i < 3; i++)
	{
		MyList.pop_back();
	}
	for (int i = 0; i < 2; i++)
	{
		MyList.pop_front();
	}
	
	
}

