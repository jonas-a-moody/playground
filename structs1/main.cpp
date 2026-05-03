#include <cstddef>    // size_t
#include <stdexcept>  // std::out_of_range

template <typename T>
class DynamicArray {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    // Constructor
    explicit DynamicArray(size_t initial_capacity = 2)
        : size(0), capacity_(initial_capacity)
    {
        data_ = new T[capacity_];
    }

    // Destructor
    ~DynamicArray() {
        delete[] data_;
    }
};    // end class DynamicArray

