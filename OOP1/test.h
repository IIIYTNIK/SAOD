#pragma once

#include <random>   // ���������� ��� ��������� ��������� �����
#include <fstream>  // ���������� ��� ������ � �������
#include <cassert>
#include <iostream>
#include "Search_Array.h"
using namespace Search_array;

namespace test {
    // �������������� ����� ��� ��������� ������
    void test_SearchInArray_equal() {
        //����� ��������, ������� ���� � �������
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 5) == 4);
        }
        //����� ��������, �������� ��� � �������
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 11) == size); // 11 ��� � �������
        }
        //����� � ������ �������
        {
            int* arr = nullptr; // ��������� �� ������ �������� �������
            size_t size = 0;
            assert(SearchInArray_equal(arr, size, 1) == size); // ������ ����
        }
        //����� � ������� � �������������� ����������
        {
            int arr[] = { 1, 2, 2, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 2) >= 1 && SearchInArray_equal(arr, size, 2) <= 3); // 2 ����� ���� �� �������� 1, 2 ��� 3
        }
        // ����: ����� ������� ��������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 1) == 0); // 1 ��������� �� ������� 0
        }
        // ����: ����� ���������� ��������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, 5) == 4); // 5 ��������� �� ������� 4
        }
        // ����: ����� � ������� � �������������� �������
        {
            int arr[] = { -5, -3, 0, 2, 4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_equal(arr, size, -3) == 1); // -3 ��������� �� ������� 1
            assert(SearchInArray_equal(arr, size, 6) == size); // 6 ��� � �������
        }
    }

    // �������������� ����� ��� ��������� ������
    void test_SearchInArray_bin() {
        //����� ��������, ������� ���� � �������
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 5) == 4);
        }
        //����� ��������, �������� ��� � �������
        {
            int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 11) == size); // 11 ��� � �������
        }
        //����� � ������ �������
        {
            int* arr = nullptr; // ��������� �� ������ �������� �������
            size_t size = 0;
            assert(SearchInArray_bin(arr, size, 1) == size); // ������ ����
        }
        //����� � ������� � �������������� ����������
        {
            int arr[] = { 1, 2, 2, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 2) >= 1 && SearchInArray_bin(arr, size, 2) <= 3); // 2 ����� ���� �� �������� 1, 2 ��� 3
        }
        // ����: ����� ������� ��������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 1) == 0); // 1 ��������� �� ������� 0
        }
        // ����: ����� ���������� ��������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, 5) == 4); // 5 ��������� �� ������� 4
        }
        // ����: ����� � ������� � �������������� �������
        {
            int arr[] = { -5, -3, 0, 2, 4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            assert(SearchInArray_bin(arr, size, -3) == 1); // -3 ��������� �� ������� 1
            assert(SearchInArray_bin(arr, size, 6) == size); // 6 ��� � �������
        }
    }
    
    // �������������� ����� ��� ��������� ������
    void test_SearchInArray_interpol() {
        //����� ��������, ������� ���� � �������
            {
                int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 5) == 4);
            }
            //����� ��������, �������� ��� � �������
            {
                int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 11) == size); // 11 ��� � �������
            }
            //����� � ������� � �������������� ����������
            {
                int arr[] = { 1, 2, 2, 2, 3, 4, 5 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 2) >= 1 && SearchInArray_interpol(arr, size, 2) <= 3); // 2 ����� ���� �� �������� 1, 2 ��� 3
            }
            // ����: ����� ������� ��������
            {
                int arr[] = { 1, 2, 3, 4, 5 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 1) == 0); // 1 ��������� �� ������� 0
            }
            // ����: ����� ���������� ��������
            {
                int arr[] = { 1, 2, 3, 4, 5 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, 5) == 4); // 5 ��������� �� ������� 4
            }
            // ����: ����� � ������� � �������������� �������
            {
                int arr[] = { -5, -3, 0, 2, 4 };
                size_t size = sizeof(arr) / sizeof(arr[0]);
                assert(SearchInArray_interpol(arr, size, -3) == 1); // -3 ��������� �� ������� 1
                assert(SearchInArray_interpol(arr, size, 6) == size); // 6 ��� � �������
            }
    }

    // �������������� ����� ��� ������� bubblesort
    void test_bubblesort() {
        // ����: ���������� ��� ���������������� �������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� �������, ���������������� � �������� �������
        {
            int arr[] = { 5, 4, 3, 2, 1 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� �� ���������� ����������
        {
            int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� �� ������ ��������
        {
            int arr[] = { 42 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ������ �� ������ �������� ��������� ���������������
        }
        // ����: ���������� ������� � �������������� ����������
        {
            int arr[] = { 5, 3, 2, 5, 1, 2 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� � �������������� �������
        {
            int arr[] = { -5, -1, -3, 0, 2, -4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� � �������� �������
        {
            int arr[] = { 1000, 500, 2000, 100, 3000 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortbubble(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
    }

    // �������������� ����� ��� ������� sortinsertion
    void test_insertionSort() {
        // ����: ���������� ��� ���������������� �������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� �������, ���������������� � �������� �������
        {
            int arr[] = { 5, 4, 3, 2, 1 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� �� ���������� ����������
        {
            int arr[] = { 12, 11, 13, 5, 6, 7 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� �������
        {
            int* arr = nullptr;
            size_t size = 0;
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ������ ������ ��������� ���������������
        }
        // ����: ���������� ������� �� ������ ��������
        {
            int arr[] = { 42 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ������ �� ������ �������� ��������� ���������������
        }
        // ����: ���������� ������� � �������������� ����������
        {
            int arr[] = { 5, 3, 2, 5, 1, 2 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� � �������������� �������
        {
            int arr[] = { -5, -1, -3, 0, 2, -4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� � �������� �������
        {
            int arr[] = { 1000, 500, 2000, 100, 3000 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            sortinsertion(arr, size);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
    }

    //�������������� ����� ��� ������� quickSort
    void test_quickSort() {
        // ����: ���������� ��� ���������������� �������
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� �������, ���������������� � �������� �������
        {
            int arr[] = { 5, 4, 3, 2, 1 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� �� ���������� ����������
        {
            int arr[] = { 12, 11, 13, 5, 6, 7 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� �� ������ ��������
        {
            int arr[] = { 42 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ������ �� ������ �������� ��������� ���������������
        }
        // ����: ���������� ������� � �������������� ����������
        {
            int arr[] = { 5, 3, 2, 5, 1, 2 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� � �������������� �������
        {
            int arr[] = { -5, -1, -3, 0, 2, -4 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
        // ����: ���������� ������� � �������� �������
        {
            int arr[] = { 1000, 500, 2000, 100, 3000 };
            size_t size = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, size - 1);
            assert(is_sorted(arr, size)); // ���������, ��� ������ ������������
        }
    }
    // ����� ��� ������� is_sorted
    void is_sorted_assert() {
        // ����: ������ ������������ �� �����������
        {
            int arr[] = { 1, 3, 4, 7 };
            assert(is_sorted(arr, 4)); // ������ ������������
        }
        // ����: ������ �� ������������
        {
            int arr2[] = { 5, 3, 4, 7 };
            assert(!is_sorted(arr2, 4)); // ������ �� ������������
        }
        // ����: ������ ������ (��������� ���������������)
        {
            int* arr3 = nullptr;
            assert(is_sorted(arr3, 0)); // ������ ������ ��������� ���������������
        }
        // ����: ������ �� ������ �������� (��������� ���������������)
        {
            int arr4[] = { 42 };
            assert(is_sorted(arr4, 1)); // ������ �� ������ �������� ��������� ���������������
        }
        // ����: ������ � �������������� ���������� (������������)
        {
            int arr5[] = { 1, 2, 2, 3, 4, 4, 4, 5 };
            assert(is_sorted(arr5, 8)); // ������ � ������������ ��������� ���������������
        }
        // ����: ������ � �������������� ���������� (�� ������������)
        {
            int arr6[] = { 1, 2, 2, 1, 3, 4 };
            assert(!is_sorted(arr6, 6)); // ������ � ������������ �� ������������
        }
        // ����: ������ � �������������� ������� (������������)
        {
            int arr7[] = { -5, -3, 0, 2, 4 };
            assert(is_sorted(arr7, 5)); // ������ � �������������� ������� ������������
        }
        // ����: ������ � �������������� ������� (�� ������������)
        {
            int arr8[] = { -1, -3, -5, -7 };
            assert(!is_sorted(arr8, 4)); // ������ � �������������� ������� �� ������������
        }
        // ����: ������ �� ��������������� � ������� �����
        {
            int arr9[] = { 1, 2, 2, 3, 4, 4, 7, 3 };
            assert(!is_sorted(arr9, 8));
        }
        // ����: ������ �� ��������������� � ������ �����
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