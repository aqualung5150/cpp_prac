#include "Data.hpp"

int main()
{
    Data data("John", 20, 180, 75);
    uintptr_t ptr;

    ptr = serialize(&data);
    deserialize(ptr)->print();

    std::cout << &data << std::endl;
    std::cout << std::hex << ptr << std::endl;

    return 0;
}