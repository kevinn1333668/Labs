#include <vector>
#include <iostream>

class MyVector {
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    MyVector() {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }
    MyVector(size_t size) {
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
    }
    ~MyVector() {
        if(m_arr != nullptr)
            delete[] m_arr;
    }

    void push_back(int value) {
        if(m_size + 1 <= m_cap) {
            m_arr[m_size] = value;
            m_size++;
            return;
        }
        m_cap = m_cap * 2 + 1;
        int* tmp = new int[m_cap];
        std::copy(m_arr, m_arr+m_size, tmp);
        tmp[m_size] = value;
        delete[] m_arr;
        m_arr = tmp;
        m_size++;
    }

    void reserve(size_t cap) {
        if(m_size >= cap)
            return;
        m_cap = cap;
        int* tmp = new int[m_cap];
        std::copy(m_arr, m_arr+m_size, tmp);
        delete[] m_arr;
        m_arr = tmp;
    }

    void resize(size_t new_size) {
        if (new_size > m_cap) {
            reserve(new_size);
        }
        if (new_size > m_size) {
            std::fill(m_arr + m_size, m_arr + new_size, 0);
        }
        m_size = new_size;
    }

    void shrink_to_fit() {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        std::copy(m_arr, m_arr+m_size, tmp);
        delete[] m_arr;
        m_arr = tmp;
    }

    void insert(size_t pos, int value) {
    if (pos > m_size) {
        return;
    }
        
    if (m_size == m_cap) {
        reserve(m_cap == 0 ? 1 : m_cap * 2);
    }
        
    std::copy_backward(m_arr + pos, m_arr + m_size, m_arr + m_size + 1);
    m_arr[pos] = value;
    m_size++;
    }

    void erase(size_t pos) 
    {
        if (pos >= m_size) {
            return;
        }
        
        std::copy(m_arr + pos + 1, m_arr + m_size, m_arr + pos);
        m_size--;
    }

    bool empty() const {
        return m_size == 0;
    }    

    size_t size() {
        return m_size;
    }

    size_t capacity() {
        return m_cap;
    }

    int& operator[](size_t index) {
        return m_arr[index];
    }

    int& back() {
        return m_arr[m_size - 1];
    }

    int& front() {
        return m_arr[0];
    }

    int& at(size_t index) {
        if(index < m_size)
            return m_arr[index];
    }

    MyVector(const MyVector& other) : MyVector(other.m_size)
    {
        std::copy(other.m_arr, other.m_arr+m_size, m_arr);
    }
    MyVector& operator=(const MyVector& other)
    {
        if (this == &other)
            return *this;
        if (m_arr != nullptr)
        {
            delete[] m_arr;
            m_arr = nullptr;
            m_size = 0;
        }
        if (other.m_size > 0)
        {
            m_size = other.m_size;
            m_cap = other.m_cap;
            m_arr = new int[m_size];
            std::copy(other.m_arr, other.m_arr+m_size, m_arr);
        }
        else
        {
            m_arr = nullptr;
        }
        return *this;

    }

};

void foo(MyVector vec) {

}

int main() {
    std::vector<int> mas;
    mas.resize(20);
    mas[10] = 2;
    for(int i=0;i<100;i++) {
        mas.push_back(i);
        std::cout << mas.size() << " " << mas.capacity() << std::endl;
    }
    mas.shrink_to_fit();
    std::cout << mas.size() << " " << mas.capacity() << std::endl;

    std::cout << mas[10] << std::endl;
    mas[10] = 2;
    std::cout << mas[10] << std::endl;
    MyVector arr1(3);
    arr1.push_back(3);
    arr1.push_back(3);
    arr1.push_back(3);
    MyVector arr2;
    arr2 = arr1;
    std::cout << arr2.back() << std::endl;

    return 0;
}