#include <iostream>
#include <vector> 
#include <algorithm>

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
    
    double smallest = 0; // overwritten on first loop
    double largest = 0;  // overwritten on first loop
    bool first_run = true; 
    double value;
    double conv_val; 
    double conv_val_prev;
    double sum = 0; 
    int count = 0; 
    std::string value_s; 
    std::string unit; 
    std::vector<double> all_values; 

    while (true) {
        std::cout << "Enter a [value] [unit]: ";
        std::cin >> value_s >> unit;
       
        if (value_s == "|") {
            break; 
        } else {
            value = std::stod(value_s); // convert the user value input into a double
        }
        
        // convert the value to a raw value using m
        if (unit == "m") {
            conv_val = value; 
        } else if (unit == "in") {
            conv_val = value * 0.0254;
        } else if (unit == "ft") {
            conv_val = value * 0.3048; 
        } else if (unit == "cm") {
            conv_val = value * 0.01; 
        } else {
            std::cout << "Invalid unit: expected m, in, ft, cm." 
                << "\n";
                std::cin.ignore(32767, '\n'); // clear remainder of the input buffer
                continue;
        }

        // store the converted value into a vector
        all_values.push_back(conv_val); 

        // populate smallest and largest on first run
        if (first_run) {
            smallest = conv_val;
            largest = conv_val;             
        }

        // Set the smallest and largest values: 
        if (conv_val < smallest || first_run == true) {
            std::cout << "the smallest so far.\n";
            smallest = conv_val; 
        }
    
        if (conv_val > largest || first_run == true) {
            std::cout << "the largest so far.\n";
            largest = conv_val; 
        }
        
        if (!first_run) {
            compare(conv_val, conv_val_prev);
        }
        conv_val_prev = conv_val; 
        count++;
        sum += conv_val; 
        first_run = false; 
    }
    std::cout << "Smallest value: " << smallest << "\n";
    std::cout << "Largest value: " << largest << "\n"; 
    std::cout << "Count of values: " << count << "\n";
    std::cout << "Sum of values: " << sum << "\n"; 
    
    // sort all_values and then print them
    std::ranges::sort(all_values); 
    for (double v : all_values) {
        std::cout << v << '\n';
    }
    return 0; 
} // end main()