#pragma once

namespace Search_array {

    // ������� �������� ������� ��������� ������� size, ������������ ���������� ���������� � �������� ��������� �� min_val �� max_val
    template<typename T>
    T* random_array(long long size, T min_val, T max_val) {
        std::random_device rd;
        std::mt19937 gen(time(NULL));
        T* array = new T[size];

        std::uniform_real_distribution<> distributian(min_val, max_val);
        for (size_t i = 0; i < size; ++i) {
            array[i] = distributian(gen);
        }

        return array;
    }

    // ������� �������� ������� ��������� ������� size, ������������ ���������� ���������� � ������� 
    // ������������ � �������� ��������� �� min_val (�� ��������� 0) �� max_val (�� ��������� 10)
    template<typename T>
    T* random_array_sorted(long long size, T min_val = 0.0, T max_val = 10.0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> distr(min_val, max_val);
        T* array = new T[size];
        array[0] = min_val + rand() % max_val;

        for (size_t i = 1; i < size; ++i) {
            array[i] = array[i - 1] + min_val + rand() % max_val;
        }

        return array;
    }

    // ������� ������ ������� array ���� T � ���� filename ������� size
    template<typename T>
    void print_array_to_file(const T* array, const std::string& filename, size_t size) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (size_t i = 0; i < size; i++) {
                file << array[i] << " ";
            }
            file << std::endl;
            file.close();
        }
        else {
            std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;   ////
        }
    }

    //������� ��������� ������ � ������� array ���� T �������� size, ����� �������� number ���� T.
    template<typename T>
    size_t SearchInArray_equal(const T* array, size_t size, T number) {
        for (size_t i = 0; i < size; i++) {
            if (number == array[i]) {
                return i; //���������� �������
            }
        }
        return size; //���������� ������, ������ �������� ��� � �������
    }

    //������� ��������� ������ � ������� array ���� T �������� size, ����� �������� number ���� T
    template<typename T>
    size_t SearchInArray_bin(const T* array, size_t size, T number) {
        size_t L = 0; //����� ������� �������
        size_t R = size; //������ ������� �������

        while (L < R) { 
            size_t n = L + (R - L) / 2;

            if (array[n] == number) { return n; } //���� �������, ���������� �������
            else if (array[n] < number) { L = n + 1; } //���� �������� ������ ����������� ����� �������
            else { R = n; } // ��������� ������ �������
        }

        return size; // ���������� size, ���� ������� �� ������
    }

    //������� ����������������� ������ � ������� array ���� T �������� size, ����� �������� number ���� T
    template<typename T>
    size_t SearchInArray_interpol(const T* array, size_t size, T number) {
        size_t x = 0;
        size_t L = 0;
        size_t R = size - 1;

        //���� ������ �� �������, ���� ������� �� ������� 
        //��� ������� ������ ��� ����������
        while ( number > array[L] && number < array[R]) {

            //���������� ������������� ������� ���������� ��������, ������� ����� ������������ � �������
            x = L + ((number - array[L]) * (R - L)) / (array[R] - array[L]); 
            //��������� ����� ������ �������, ���� ������� �� �������
            if (array[x] < number)
                L = x + 1;
            else if (array[x] > number)
                R = x - 1;
            else
                return x;
        }
        if (array[L] == number)
            return L;
        else if (array[R] == number)
            return R;
        else
            return size;
    }

    //�������� ���������� ������� array �� ���������� ������� size
    template<typename T>
    bool is_sorted(const T* array, size_t size) {
        for (size_t i = 1; i < size; i++) {
            if (array[i - 1] > array[i]) {
                return false;
            }
        }
        return true;
    }

    // ������� ���������� ���������. ������� ��������� ������ array ���� T, ������� size ���� T
    template<typename T>
    void sortbubble (T* array, size_t size) {
        bool swapped; // ���� ��� ��������, ���� �� ������ �� ������� ��������
        for (size_t i = 0; i < size - 1; i++) {
            swapped = false; // ���������� ���� ����� ������� ����� ��������
            for (size_t j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) { // ���������� �������� ��������
                    // ������ �������� �������
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = true; // ������������� ����, ���� ��� �����
                }
            }
            // ���� �� ������� �������� �� ���� �������, ������ ��� ������������
            if (!swapped) {
                break;
            }
        }
    }

    // ������� ���������� ��������. ������� ��������� ������ array ���� T, ������� size ���� T
    template<typename T>
    void sortinsertion(T* array, size_t size) {
        for (size_t i = 1; i < size; i++) {
            T key = array[i]; // ������� �������, ������� ����� �������� � ��������������� �����
            size_t j = i;

            // �������� �������� ������ key ������
            while (j > 0 && array[j - 1] > key) {
                array[j] = array[j - 1];
                j--;
            }

            // ��������� key �� ���������� �����
            array[j] = key;
        }
    }

    // ������� ��� ������� ���� ��������������� ��������. ��������� ������ array ���� T, ����� � ������ ������� left rihgt ���� size_t, ����� ������� ���� size_t
    template<typename T>
    void merge(T* array, size_t left, size_t mid, size_t right) {
        size_t n1 = mid - left + 1; // ������ ������ ����������
        size_t n2 = right - mid;    // ������ ������� ����������

        // ������� ��������� ������� ��� ����� � ������ �������
        std::vector<T> L(n1), R(n2);

        // �������� ������ �� ��������� �������
        for (size_t i = 0; i < n1; i++) {
            L[i] = array[left + i];
        }
        for (size_t j = 0; j < n2; j++) {
            R[j] = array[mid + 1 + j];
        }

        // ������� ��������� �������� ������� � �������� ������
        size_t i = 0; // ������ ��� ������ ����������
        size_t j = 0; // ������ ��� ������� ����������
        size_t k = left; // ������ ��� ��������� �������

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            }
            else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // �������� ���������� �������� ������ ���������� (���� ��� ����)
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        // �������� ���������� �������� ������� ���������� (���� ��� ����)
        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }//������������ ������� copy ��� ����������� �������
    }

    // ������� ���������� ��������. ��������� ������ array ���� T, ����� � ������ ������� left rihgt ���� size_t
    template<typename T>
    void sortmerge(T* array, size_t L, size_t R) {
        if (L < R) {
            size_t mid = L + (R - L) / 2; // ������� ��������

            // ���������� ��������� ����� � ������ ��������
            sortmerge(array, L, mid);
            sortmerge(array, mid + 1, R);

            // ������� ��� ��������������� ��������
            merge(array, L, mid, R);
        }
    }

    // ������� ������� ����������. ��������� ������ array ���� T, ����� � ������ ������� left rihgt ���� size_t
    template<typename T>
    void sortquick(T* array, size_t L, size_t R) {
        if (L >= R) return; //���� ��������

        T pivot = array[(L + R) / 2];
        size_t i = L;
        size_t j = R;

        while (i <= j) {
            // ���� �������, ������� ������ ��� ����� pivot
            while (i <= R && array[i] < pivot) i++;
            // ���� �������, ������� ������ ��� ����� pivot
            while (j >= L && array[j] > pivot) j--;

            if (i <= j) {
                std::swap(array[i], array[j]);
                i++;
                if (j > 0) j--;
            }
        }
        if (j > L) sortquick(array, L, j);
        if (i < R) sortquick(array, i, R);
    }

    // ������� shell ����������. ��������� ������ array ���� T, ����� � ������ ������� left rihgt ���� size_t
    template<typename T>
    void sortshell(T* array, size_t R) {
        size_t d = R / 2; //d - �������� �� ������� �������
        while (d >= 1) { //���� d ������ 1 - ��������
            for (size_t i = d; i < R; i++) {
                size_t j = i;
                while ((j >= d) && (array[j - d] > array[j])) {
                    std::swap(array[j], array[j - d]);
                    j = j - d;
                }
            }
            d = d / 2; // ��������� ��� � 2 ����
        }
    }

    // ������ ��� ������������� �������. ���������
    template<typename T>
    void shuffle(T* a, size_t n)
    {
        for (size_t i = 0; i < n; i++)
            std::swap(a[i], a[rand() % n]);
    }

    // Sorts array a[0..n-1] using Bogo sort
    template<typename T>
    void bogosort(T* a, size_t n)
    {
        // ���� ������ �� ������������ - ������������
        while (!is_sorted(a, n))
            shuffle(a, n);
    }


}