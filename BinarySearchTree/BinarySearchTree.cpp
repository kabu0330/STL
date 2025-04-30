#include <iostream>
#include "BST.h"
#include <map>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    /*        10
    *     5         15
    * 1      7    13    20
    *   3       11
    */

    BinarySearchTree* BST = new BinarySearchTree();
    BST->Insert(10);
    BST->Insert(5);
    BST->Insert(15);
    BST->Insert(1);
    BST->Insert(3);
    BST->Insert(7);
    BST->Insert(13);
    BST->Insert(11);
    BST->Insert(20);
    BST->Insert(12);
    
    BST->PreOrder();
    std::cout << std::endl;

    //BST->InOrder();
    if (nullptr != BST->Find(1))
    {
        std::cout << "1 is found" << std::endl;
    }
    else
    {
        std::cout << "1 is not found" << std::endl;
    }

    if (nullptr != BST->Find(12))
    {
        std::cout << "12 is found" << std::endl;
    }
    else
    {
        std::cout << "12 is not found" << std::endl;
    }

    std::cout << std::endl;
    BST->Erase(10);
    BST->PreOrder();
    //BST->InOrder();

    BST->Release();
    int a = 0;
}
