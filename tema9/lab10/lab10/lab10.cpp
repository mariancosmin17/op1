#include <iostream>
#include <stdexcept>

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    int Current;
    T** List;
    int Size;
public:
    ArrayIterator(T** list, int size, int current = 0) : List(list), Size(size), Current(current) {}

    ArrayIterator& operator++() {
        if (Current >= Size) throw std::out_of_range("Iterator out of range");
        ++Current;
        return *this;
    }

    ArrayIterator& operator--() {
        if (Current <= 0) throw std::out_of_range("Iterator out of range");
        --Current;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return List == other.List && Current == other.Current;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }

    T* GetElement() {
        if (Current < 0 || Current >= Size) throw std::out_of_range("Iterator out of range");
        return List[Current];
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void resize(int new_capacity) {
        T** new_list = new T * [new_capacity];
        for (int i = 0; i < Size; ++i) {
            new_list[i] = List[i];
        }
        delete[] List;
        List = new_list;
        Capacity = new_capacity;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size) {
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) {
            resize(Capacity == 0 ? 1 : Capacity * 2);
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) throw std::out_of_range("Index out of range");
        if (Size >= Capacity) {
            resize(Capacity == 0 ? 1 : Capacity * 2);
        }
        for (int i = Size; i > index; --i) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size) throw std::out_of_range("Index out of range");
        if (Size + otherArray.Size > Capacity) {
            resize(Size + otherArray.Size);
        }
        for (int i = Size - 1; i >= index; --i) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; ++i) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
        delete List[index];
        for (int i = index; i < Size - 1; ++i) {
            List[i] = List[i + 1];
        }
        --Size;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) return true;
        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
        return true;
    }

    void Sort() {
        // Implement default sorting (e.g., std::sort)
    }

    void Sort(int(*compare)(const T&, const T&)) {
        // Implement sorting using the compare function
    }

    void Sort(Compare* comparator) {
        // Implement sorting using the comparator object
    }

    int BinarySearch(const T& elem) {
        // Implement binary search
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        // Implement binary search using the compare function
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        // Implement binary search using the comparator object
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; ++i) {
            if (*List[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; ++i) {
            if (compare(*List[i], elem) == 0) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; ++i) {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0) {
                return i;
            }
        }
        return -1;
    }

    int GetSize() const {
        return Size;
    }

    int GetCapacity() const {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, Size, 0);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size, Size);
    }
};

// Example usage of exceptions
class MyCompare : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int a = *(int*)e1;
        int b = *(int*)e2;
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }
};

int main() {
    try {
        Array<int> arr(10);
        arr += 1;
        arr += 2;
        arr += 3;

        std::cout << "Element at index 1: " << arr[1] << std::endl;

        arr.Insert(1, 4);
        std::cout << "Element at index 1 after insertion: " << arr[1] << std::endl;

        arr.Delete(1);
        std::cout << "Element at index 1 after deletion: " << arr[1] << std::endl;

        MyCompare cmp;
        int index = arr.Find(2, &cmp);
        std::cout << "Index of element 2: " << index << std::endl;

        for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it) {
            std::cout << *(it.GetElement()) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
