#include <iostream>
#include <random>
#include <vector>

namespace {
template <typename T>
void print_array(const std::vector<T> &array)
{
    for (auto it = array.begin(); it != array.end(); it++) {
        std::cout << *it << '\t';
    }
    std::cout << '\n';
}

template <typename T>
void insert_sort(std::vector<T> &array)
{
    int sz = array.size();
    if (sz <= 1) {
        return;
    }
    int j;
    for (int i = 1;i < sz;i++) {
        T key = array[i];
        // insert key into array[0, i-1]; , i-th pos can be written
        j = i - 1;
        // 挪一个合适的坑出来
        while (j >= 0 && key > array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
} // end of namespace

int main()
{
    std::vector<int> array;
    std::uniform_int_distribution<int> distribution(-50, 50);

    std::random_device rand_dev; // uses RDRND or /dev/urandom
    for (int i = 0; i < 10; i++) {
        array.push_back(distribution(rand_dev));
    }

    std::cout << std::endl;
    print_array(array);
    insert_sort(array);
    print_array(array);
    return 0;
}