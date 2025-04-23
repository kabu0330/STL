#include <iostream>
#include <vector>

#include "UVector.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    std::vector<int> STDVector;
    for (int i = 0; i < 10; i++)
    {
        STDVector.push_back(i);
        std::cout << "vector push : " << STDVector[i] << std::endl;
        std::cout << "vector size : " << STDVector.size() << std::endl;
        std::cout << "vector capacity : " << STDVector.capacity() << std::endl;
    }

	std::cout << "vector sizeof : " << sizeof(STDVector) << std::endl;

    STDVector.clear();

    std::cout << "clear after vector size : " << STDVector.size() << std::endl;
    std::cout << "clear after vector capacity : " << STDVector.capacity() << std::endl;

    std::cout << std::endl;
    // 

    Uvector<int> NewVector;
    for (int i = 0; i < 10; i++)
    {
        NewVector.push_back(i);
        std::cout << "NewVector push : " << NewVector[i] << std::endl;
        std::cout << "NewVector size : " << NewVector.size() << std::endl;
        std::cout << "NewVector capacity : " << NewVector.capacity() << std::endl;
    }

    std::cout << "NewVector sizeof : " << sizeof(NewVector) << std::endl;

    NewVector.clear();

    std::cout << "clear after NewVector size : " << NewVector.size() << std::endl;
    std::cout << "clear after NewVector capacity : " << NewVector.capacity() << std::endl;



    
    

}
