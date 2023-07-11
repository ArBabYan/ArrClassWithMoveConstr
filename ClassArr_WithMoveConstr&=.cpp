#include <iostream>



class Array {
private:
    int* arr; 
    int size; 

public:
    Array(int arraySize) : size(arraySize) {
        arr = new int[size];
    }

    Array(Array&& obj)  : arr(obj.arr), size(obj.size) {
        obj.arr = nullptr;
        obj.size = 0;
    }

    Array& operator=(Array&& obj)  {
        if (this != &obj) {
            delete[] arr;
            arr = obj.arr;
            size = obj.size;
            obj.arr = nullptr;
            obj.size = 0;
        }
        return *this;
    }

    ~Array() {
        delete[] arr;
    }

    int getSize() const {
        return size;
    }

    int& operator[](int index) {
        return arr[index];
    }

    const int& operator[](int index) const {
        return arr[index];
    }
};

int main() {
    Array arr1(5);
    for (int i = 0; i < arr1.getSize(); ++i) {
        arr1[i] = i +1;
    }

    for (int i = 0; i < arr1.getSize(); ++i) {
        std::cout << arr1[i];
    }
    std::cout << std::endl;
    Array arr2 = std::move(arr1);
    for (int i = 0; i < arr2.getSize(); ++i) {
        std::cout << arr2[i];
    }
    
   

    return 0;
}