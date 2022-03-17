// ProblemBubbleSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

void swap(int* first, int* second)
{
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

void bubbleSortOld(int array[], int const begin, int const end)
{
    int n = end - begin;
    bool swapped;
    do {
        swapped = false;
        for (int i = begin + 1; i < end; ++i)
            if (array[i - 1] > array[i]) {
                swap(&array[i - 1], &array[i]);
                swapped = true;
            }
    } while (swapped);
}

void bubbleSort(int array[], int const begin, int const end)
{
    int n = end - begin;
    do {
        int newn = 0;
        for (int i = begin + 1; i < end; ++i)
            if (array[i - 1] > array[i]) {
                swap(&array[i - 1], &array[i]);
                newn = i;
            }
        n = newn;
    } while (n > 1);
}

std::pair<unsigned int, unsigned int> test(int n)
{
    int* arr = new int[n], * arr1 = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = arr1[i] = rand() % 1000;

    auto start_time = std::chrono::steady_clock::now();
    bubbleSort(arr, 0, n);
    auto end_time = std::chrono::steady_clock::now();

    auto start_time1 = std::chrono::steady_clock::now();
    bubbleSortOld(arr1, 0, n);
    auto end_time1 = std::chrono::steady_clock::now();

    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    auto elapsed_ns1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1);

    return std::make_pair(elapsed_ns.count(), elapsed_ns1.count());
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    std::ofstream fout("test_data.txt");

    for (int n = 1; n < 2000; ++n)
        fout << n << ' ';
    fout << '\n';
    
    std::pair<unsigned int, unsigned int>* arr = new std::pair<unsigned int, unsigned int>[2001];
    for (int n = 1; n < 2000; ++n)
        arr[n] = test(n);
    
    for (int n = 1; n < 2000; ++n)
        fout << arr[n].first << ' ';
    fout << '\n';
    for (int n = 1; n < 2000; ++n)
        fout << arr[n].second << ' ';
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
