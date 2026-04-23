#include "CrossArray.hpp"
#include <iostream>

int main() {
    // Test basic constructor and InsertArrays
    sjtu::CrossArray ca(5);
    
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {6, 7, 8, 9};
    
    std::cout << "Testing InsertArrays..." << std::endl;
    bool result1 = ca.InsertArrays(arr1, 3);
    std::cout << "Insert 1: " << (result1 ? "success" : "failed") << std::endl;
    
    bool result2 = ca.InsertArrays(arr2, 2);
    std::cout << "Insert 2: " << (result2 ? "success" : "failed") << std::endl;
    
    bool result3 = ca.InsertArrays(arr3, 4);
    std::cout << "Insert 3: " << (result3 ? "success" : "failed") << std::endl;
    
    // Test At function
    std::cout << "\nTesting At function..." << std::endl;
    std::cout << "ca.At(0, 0) = " << ca.At(0, 0) << " (expected 1)" << std::endl;
    std::cout << "ca.At(0, 2) = " << ca.At(0, 2) << " (expected 3)" << std::endl;
    std::cout << "ca.At(1, 1) = " << ca.At(1, 1) << " (expected 5)" << std::endl;
    std::cout << "ca.At(2, 3) = " << ca.At(2, 3) << " (expected 9)" << std::endl;
    
    // Test AppendArrays
    std::cout << "\nTesting AppendArrays..." << std::endl;
    int arr4[] = {10, 11};
    ca.AppendArrays(arr4, 0, 2);
    std::cout << "After append, ca.At(0, 3) = " << ca.At(0, 3) << " (expected 10)" << std::endl;
    std::cout << "After append, ca.At(0, 4) = " << ca.At(0, 4) << " (expected 11)" << std::endl;
    
    // Test copy constructor
    std::cout << "\nTesting copy constructor..." << std::endl;
    sjtu::CrossArray ca2(ca);
    std::cout << "ca2.At(0, 0) = " << ca2.At(0, 0) << " (expected 1)" << std::endl;
    std::cout << "ca2.At(2, 3) = " << ca2.At(2, 3) << " (expected 9)" << std::endl;
    
    // Test IsSame
    std::cout << "\nTesting IsSame..." << std::endl;
    std::cout << "ca.IsSame(ca2) = " << (ca.IsSame(ca2) ? "true" : "false") << " (expected false)" << std::endl;
    std::cout << "ca.IsSame(ca) = " << (ca.IsSame(ca) ? "true" : "false") << " (expected true)" << std::endl;
    
    // Test WhichGreater
    std::cout << "\nTesting WhichGreater..." << std::endl;
    sjtu::CrossArray& greater = ca.WhichGreater(ca2);
    std::cout << "WhichGreater returned " << (ca.IsSame(greater) ? "ca" : "ca2") << std::endl;
    
    // Test AtArray
    std::cout << "\nTesting AtArray..." << std::endl;
    const int* arr = ca.AtArray(1);
    if (arr != nullptr) {
        std::cout << "AtArray(1)[0] = " << arr[0] << " (expected 4)" << std::endl;
        std::cout << "AtArray(1)[1] = " << arr[1] << " (expected 5)" << std::endl;
    }
    
    // Test DoubleCrossLength
    std::cout << "\nTesting DoubleCrossLength..." << std::endl;
    ca.DoubleCrossLength();
    std::cout << "After doubling, ca.At(0, 0) = " << ca.At(0, 0) << " (expected 1)" << std::endl;
    
    int arr5[] = {100, 200};
    bool result4 = ca.InsertArrays(arr5, 2);
    std::cout << "Insert after doubling: " << (result4 ? "success" : "failed") << std::endl;
    
    std::cout << "\nAll tests completed!" << std::endl;
    
    return 0;
}
