#include <iostream>
#include <time.h>
 
using namespace std;

template <typename T>
class array
{
 private:
    int arrSize;
    int cap;
    T * data;
 public:
    array()
    {
        arrSize = 0;
        cap = 0;
        data = NULL;
    }
    array(const array<T> & a)
    {
        arrSize = a.arrSize;
        cap = arrSize;
        data = NULL;
        if (arrSize != 0)
            data = new T[arrSize];
        else
            data = 0;
        for (int i = 0; i < arrSize; ++i)
            data[i] = a.data[i];
    }
    array(int size1)
    {
        arrSize = size1;
        cap = size1;
        if (size1 != 0)
            data = new T[size1];
        else
            data = 0;
    }
    ~array()
    {
        if (data)
            delete[] data;
    }
    void resize(int size1)
    {
        if (size1 > cap)
        {
            int new_cap = max(size1, arrSize * 2);
            T * new_data = new T[new_cap];
            for (int i = 0; i < arrSize; ++i)
                new_data[i] = data[i];
            delete[] data;
            data = new_data;
            cap = new_cap;
        }
        arrSize = size1;
    }
    void push_back(T val)
    {
        resize(arrSize + 1);
        data[arrSize - 1] = val;
    }
    void del(int ind)
    {
        for (int i = ind; i < arrSize-1; ++i)
            data[i] = data[i+1];
        resize(arrSize - 1);
    }
    void insert(int ind, T val)
    {   
        if (ind <= arrSize){
        resize(arrSize + 1);
        for (int i = ind; i < arrSize-1; ++i)
            data[i+1] = data[i];
        data[ind] = val;
        }
        else {
            cout << "Error inserting: index must be less or equal than array size" << endl;
        }
    }
    int size() const
    {
        return arrSize;
    }
    T & operator[] (int i)
    {
        return data[i];
    }
};

template<typename T>
ostream & operator << (ostream & out, array<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}






 
int main()
{
    array<int> arr;
    
    arr.push_back(1);
    arr.push_back(11);
    cout << "Array: " << arr << endl;
    cout << "Array size: " << arr.size() << endl;
    cout << "Array[1]: " << arr[1] << endl;
    arr[1] = 3;
    cout << "New array 1: " << arr << endl;
    //arr.del(1);
    cout << "New array: " << arr << endl;
    cout << arr.size() << endl;
    arr.insert(2, 5);
    cout << arr;
    
    
}