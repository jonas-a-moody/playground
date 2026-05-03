#include <cstddef>    // size_t
#include <stdexcept>  // std::out_of_range

template <typename T>
class DynamicArray {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void resize() {
        capacity_ *= 2; 
        T* new_data = new T[capacity_];

        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
    }

public:
    // Constructor
    explicit DynamicArray(size_t initial_capacity = 2)
        : size_(0), capacity_(initial_capacity)
    {
        data_ = new T[capacity_];
    }

    // Destructor
    ~DynamicArray() {
        delete[] data_;
    }

    DynamicArray(const DynamicArray& other) 
        : size_(other.size_), capacity_(other.capacity_)
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data[i] = other.data_[i];
        }
        return *this; 
    }

    void push_back(const T& value) {
        if (size_ == capacity_) resize();
        data_[size_++] = value;         
    }

    T& operator[](size_t index) { return data_[index]; }

    T& at(size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index]; 
    }

    size_t size()      const { return size_; }
    size_t capacity()  const { return capacity_; }
};    // end class DynamicArray