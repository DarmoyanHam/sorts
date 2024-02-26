#include <iostream>
#include <algorithm>

void bubble_sort(int* arr, int size)
{
    bool swapped;
    for(int i = 0; i < size - 1; ++i)
    {
        swapped = false;
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] < arr[j + 1])
            {
                /* int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp; */
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

void selection_sort(int* arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        int m_index = i;
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] > arr[m_index])
            {
                m_index = j;
            }
        }

        if(i != m_index)
        {
            std::swap(arr[i], arr[m_index]);
        }
    }
}

void sort(int* arr, int n, void (*f_ptr)(int*, int))
{
    f_ptr(arr, n);
}

int main()
{
    int const size = 5;
    int arr[size] = {1, 3, -7, 4, -2};

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int x;

    std::cout << "1 or 2" << std::endl;
    std::cin >> x;

    switch(x)
    {
        case 1:
            sort(arr, size, bubble_sort);
            break;
        case 2:
            sort(arr, size, selection_sort);
            break;
    }

    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}