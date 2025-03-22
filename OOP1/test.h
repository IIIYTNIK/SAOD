#pragma once

#include <random>   // библиотека для генерации случайных чисел
#include <fstream>  // библиотека для работы с файлами
#include <cassert>
#include <iostream>
#include "Search_Array.h"
using namespace Search_array;

namespace test {
    // Автоматические тесты для линейного поиска
    void test_SearchInArray_equal() {
        //Поиск элемента, который есть в массиве
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 5) == 4);
        }
        //Поиск элемента, которого нет в массиве
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 11) == size); // 11 нет в массиве
        }
        //Поиск в пустом массиве
        {
            int* arr = nullptr; // Указатель на массив нулевого размера
            size_t size = 0;
            assert(SearchInArray_equal(arr, size, 1) == size); // Массив пуст
        }
        //Поиск в массиве с повторяющимися элементами
        {
            int arr[] = { 1, 2, 2, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 2) >= 1 && SearchInArray_equal(arr, size, 2) <= 3); // 2 может быть на индексах 1, 2 или 3
        }
        // Тест: Поиск первого элемента
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 1) == 0); // 1 находится на индексе 0
        }
        // Тест: Поиск последнего элемента
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 5) == 4); // 5 находится на индексе 4
        }
        // Тест: Поиск в массиве с отрицательными числами
        {
            int arr[] = { -5, -3, 0, 2, 4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, -3) == 1); // -3 находится на индексе 1
            assert(SearchInArray_equal(arr, size, 6) == size); // 6 нет в массиве
        }
    }

    // Автоматические тесты для бинарного поиска
    void test_SearchInArray_bin() {
        //Поиск элемента, который есть в массиве
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 5) == 4);
        }
        //Поиск элемента, которого нет в массиве
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 11) == size); // 11 нет в массиве
        }
        //Поиск в пустом массиве
        {
            int* arr = nullptr; // Указатель на массив нулевого размера
            size_t size = 0;
            assert(SearchInArray_bin(arr, size, 1) == size); // Массив пуст
        }
        //Поиск в массиве с повторяющимися элементами
        {
            int arr[] = { 1, 2, 2, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 2) >= 1 && SearchInArray_bin(arr, size, 2) <= 3); // 2 может быть на индексах 1, 2 или 3
        }
        // Тест: Поиск первого элемента
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 1) == 0); // 1 находится на индексе 0
        }
        // Тест: Поиск последнего элемента
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 5) == 4); // 5 находится на индексе 4
        }
        // Тест: Поиск в массиве с отрицательными числами
        {
            int arr[] = { -5, -3, 0, 2, 4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, -3) == 1); // -3 находится на индексе 1
            assert(SearchInArray_bin(arr, size, 6) == size); // 6 нет в массиве
        }
    }
    
    // Автоматические тесты для бинарного поиска
    void test_SearchInArray_interpol() {
        //Поиск элемента, который есть в массиве
            {
                int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 5) == 4);
            }
            //Поиск элемента, которого нет в массиве
            {
                int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 11) == size); // 11 нет в массиве
            }
            //Поиск в массиве с повторяющимися элементами
            {
                int arr[] = { 1, 2, 2, 2, 3, 4, 5 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 2) >= 1 && SearchInArray_interpol(arr, size, 2) <= 3); // 2 может быть на индексах 1, 2 или 3
            }
            // Тест: Поиск первого элемента
            {
                int arr[] = { 1, 2, 3, 4, 5 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 1) == 0); // 1 находится на индексе 0
            }
            // Тест: Поиск последнего элемента
            {
                int arr[] = { 1, 2, 3, 4, 5 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 5) == 4); // 5 находится на индексе 4
            }
            // Тест: Поиск в массиве с отрицательными числами
            {
                int arr[] = { -5, -3, 0, 2, 4 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, -3) == 1); // -3 находится на индексе 1
                assert(SearchInArray_interpol(arr, size, 6) == size); // 6 нет в массиве
            }
    }

    // Автоматические тесты для функции bubblesort
    void test_bubblesort() {
        // Тест: Сортировка уже отсортированного массива
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива, отсортированного в обратном порядке
        {
            int arr[] = { 5, 4, 3, 2, 1 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива со случайными элементами
        {
            int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива из одного элемента
        {
            int arr[] = { 42 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Массив из одного элемента считается отсортированным
        }
        // Тест: Сортировка массива с повторяющимися элементами
        {
            int arr[] = { 5, 3, 2, 5, 1, 2 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива с отрицательными числами
        {
            int arr[] = { -5, -1, -3, 0, 2, -4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива с большими числами
        {
            int arr[] = { 1000, 500, 2000, 100, 3000 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
    }

    // Автоматические тесты для функции sortinsertion
    void test_insertionSort() {
        // Тест: Сортировка уже отсортированного массива
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива, отсортированного в обратном порядке
        {
            int arr[] = { 5, 4, 3, 2, 1 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива со случайными элементами
        {
            int arr[] = { 12, 11, 13, 5, 6, 7 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка пустого массива
        {
            int* arr = nullptr;
            size_t size = 0;
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Пустой массив считается отсортированным
        }
        // Тест: Сортировка массива из одного элемента
        {
            int arr[] = { 42 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Массив из одного элемента считается отсортированным
        }
        // Тест: Сортировка массива с повторяющимися элементами
        {
            int arr[] = { 5, 3, 2, 5, 1, 2 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива с отрицательными числами
        {
            int arr[] = { -5, -1, -3, 0, 2, -4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива с большими числами
        {
            int arr[] = { 1000, 500, 2000, 100, 3000 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
    }

    //Автоматические тесты для функции quickSort
    void test_quickSort() {
        // Тест: Сортировка уже отсортированного массива
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива, отсортированного в обратном порядке
        {
            int arr[] = { 5, 4, 3, 2, 1 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива со случайными элементами
        {
            int arr[] = { 12, 11, 13, 5, 6, 7 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива из одного элемента
        {
            int arr[] = { 42 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Массив из одного элемента считается отсортированным
        }
        // Тест: Сортировка массива с повторяющимися элементами
        {
            int arr[] = { 5, 3, 2, 5, 1, 2 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива с отрицательными числами
        {
            int arr[] = { -5, -1, -3, 0, 2, -4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
        // Тест: Сортировка массива с большими числами
        {
            int arr[] = { 1000, 500, 2000, 100, 3000 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // Проверяем, что массив отсортирован
        }
    }
    // Тесты для функции is_sorted
    void is_sorted_assert() {
        // Тест: Массив отсортирован по возрастанию
        {
            int arr[] = { 1, 3, 4, 7 };
            assert(is_sorted(arr, 4)); // Массив отсортирован
        }
        // Тест: Массив не отсортирован
        {
            int arr2[] = { 5, 3, 4, 7 };
            assert(!is_sorted(arr2, 4)); // Массив не отсортирован
        }
        // Тест: Пустой массив (считается отсортированным)
        {
            int* arr3 = nullptr;
            assert(is_sorted(arr3, 0)); // Пустой массив считается отсортированным
        }
        // Тест: Массив из одного элемента (считается отсортированным)
        {
            int arr4[] = { 42 };
            assert(is_sorted(arr4, 1)); // Массив из одного элемента считается отсортированным
        }
        // Тест: Массив с повторяющимися значениями (отсортирован)
        {
            int arr5[] = { 1, 2, 2, 3, 4, 4, 4, 5 };
            assert(is_sorted(arr5, 8)); // Массив с повторениями считается отсортированным
        }
        // Тест: Массив с повторяющимися значениями (не отсортирован)
        {
            int arr6[] = { 1, 2, 2, 1, 3, 4 };
            assert(!is_sorted(arr6, 6)); // Массив с повторениями не отсортирован
        }
        // Тест: Массив с отрицательными числами (отсортирован)
        {
            int arr7[] = { -5, -3, 0, 2, 4 };
            assert(is_sorted(arr7, 5)); // Массив с отрицательными числами отсортирован
        }
        // Тест: Массив с отрицательными числами (не отсортирован)
        {
            int arr8[] = { -1, -3, -5, -7 };
            assert(!is_sorted(arr8, 4)); // Массив с отрицательными числами не отсортирован
        }
        // Тест: Массив не отсортированный с правого конца
        {
            int arr9[] = { 1, 2, 2, 3, 4, 4, 7, 3 };
            assert(!is_sorted(arr9, 8));
        }
        // Тест: Массив не отсортированный с левого конца
        {
            int arr10[] = { 3, 2, 2, 3, 4, 4, 4, 5 };
            assert(!is_sorted(arr10, 8));
        }
    }



    void All_test() {
        test_SearchInArray_equal();
        test_SearchInArray_bin();
        test_SearchInArray_interpol();
        test_bubblesort();
        test_insertionSort();
        is_sorted_assert();
        test_quickSort();
        std::cout << "All tests passed!" << std::endl;
    }
}