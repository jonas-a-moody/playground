#include <iostream>
#include <vector> 

void compare(double a, double b) {
    // First: determine and print the smaller and larger of each number. 
    double smaller;
    double larger; 
    if (a > b) {
        std::cout << "The smaller value is: " << b << "\n";
        std::cout << "The larger value is: " << a << "\n"; 
        smaller = b; 
        larger = a; 
    } else if (a < b) {
        std::cout << "The smaller value is: " << a << "\n";
        std::cout << "The larger value is: " << b << "\n"; 
        smaller = a; 
        larger = b; 
    } else {
        std::cout << "The numbers are equal.\n";
        smaller = a;
        larger = b; 
    }

    // Second: Check if the numbers differ by less than 1.0/100. 
    if ((larger - smaller) < 0.01) {
        std::cout << "The numbers are ALMOST equal.\n"; 
    }
}

int main(int argc, char *argv[]) {
    
    double smallest = 0; 
    double largest = 0; 

    std::string input; 
    bool first_run = true; 
    double a;
    double b;  
    while (std::cin >> input && input != "|") {
        double d = std::stod(input); 
        std::cout << "Input: " << d << "\n"; 
        
        // populate smallest and largest on first run
        if (first_run) {
            smallest = d;
            largest = d;             
        }

        // Set the smallest and largest values: 
        if (d < smallest || first_run == true) {
            std::cout << "the smallest so far.\n";
            smallest = d; 
        }
        
        if (d > largest || first_run == true) {
            std::cout << "the largest so far.\n";
            largest = d; 
        }
        first_run = false; 
    }
    return 0; 
} // end main()