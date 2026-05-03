#include <iostream> 
#include "dynamic_array.h"

int main() {
    // 1. Construction
    DynamicArray<int> a;
    // push some values into a
    a.push_back(1); 
    a.push_back(2); 
    a.push_back(3); 
    std::cout << a[0] << ',' << a[1] << ',' << a[2] << '\n';
    std::cout << "Size: " << a.size() << '\n'; 

    // 2. Copy construction
    // create b as a copy of a
    DynamicArray<int> b(a); 
    std::cout << b[0] << ',' << b[1] << ',' << b[2] << '\n';
    std::cout << "Size: " << b.size() << '\n'; 

    // 3. Copy assignment
    // create c, then assign a to it
    DynamicArray<int> c;
    c = a;  
    std::cout << c[0] << ',' << c[1] << ',' << c[2] << '\n';
    std::cout << "Size: " << c.size() << '\n'; 

    // 4. Move construction
    // create d by moving from a temporary of std::move
    DynamicArray<int> d = std::move(a); 
    std::cout << d[0] << ',' << d[1] << ',' << d[2] << '\n';
    std::cout << "Size: " << d.size() << '\n'; 

    // 5. Move assignment
    // create e, then move-assign into it
    DynamicArray<int> e; 
    e = std::move(b); 

    // Verification
    // print sizes and values to confirm correct behavior
    std::cout << "a Size: " << a.size() << '\n'; 
    std::cout << "b Size: " << b.size() << '\n'; 
    std::cout << "c Size: " << c.size() << '\n'; 
    std::cout << c[0] << ',' << c[1] << ',' << c[2] << '\n';
    std::cout << "d Size: " << d.size() << '\n'; 
    std::cout << d[0] << ',' << d[1] << ',' << d[2] << '\n';
    std::cout << "e Size: " << e.size() << '\n'; 
    std::cout << e[0] << ',' << e[1] << ',' << e[2] << '\n';
    
    return 0; 
}