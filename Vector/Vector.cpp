#include <iostream>
#include <vector>

#include "UVector.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    std::vector<int> Vector;
    for (int i = 0; i < 10; i++)
    {
        Vector.push_back(i);
        std::cout << "vector push : " << Vector[i] << std::endl;
        std::cout << "vector size : " << Vector.size() << std::endl;
        std::cout << "vector capacity : " << Vector.capacity() << std::endl;
    }
    
	std::cout << "vector sizeof : " << sizeof(Vector) << std::endl;

    //Vector.clear();

    std::cout << "clear after vector size : " << Vector.size() << std::endl;
    std::cout << "clear after vector capacity : " << Vector.capacity() << std::endl;

    std::cout << std::endl;

    Vector.resize(5);
    std::cout << "resize after vector size : " << Vector.size() << std::endl;
    std::cout << "resize after vector capacity : " << Vector.capacity() << std::endl;

    std::cout << std::endl;

    UVector<int> MyVector;
    for (int i = 0; i < 10; i++)
    {
        MyVector.push_back(i);
        std::cout << "vector push : " << MyVector[i] << std::endl;
        std::cout << "vector size : " << MyVector.size() << std::endl;
        std::cout << "vector capacity : " << MyVector.capacity() << std::endl;
    }

    std::cout << "vector sizeof : " << sizeof(MyVector) << std::endl;

    MyVector.clear();

    std::cout << "clear after vector size : " << MyVector.size() << std::endl;
    std::cout << "clear after vector capacity : " << MyVector.capacity() << std::endl;

    std::cout << std::endl;

    MyVector.resize(5);

    for (size_t i = 0; i < MyVector.size(); i++)
    {
        std::cout << "MyVector Value " << i  << " Index : " << MyVector[i] << std::endl;
    }

    std::cout << "resize after vector size : " << Vector.size() << std::endl;
    std::cout << "resize after vector capacity : " << Vector.capacity() << std::endl;
  
}
