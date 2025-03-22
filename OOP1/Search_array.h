#pragma once

namespace Search_array {

    // Функция создания массива заданного размера size, заполненного случайными значениями в заданном интервале от min_val до max_val
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

    // Функция создания массива заданного размера size, заполненного случайными значениями в порядке 
    // возврастания в заданном интервале от min_val (по умолчанию 0) до max_val (по умолчанию 10)
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

    // Функция вывода массива array типа T в файл filename размера size
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
            std::cerr << "Не удалось открыть файл для записи." << std::endl;   ////
        }
    }

    //функция линейного поиска в массиве array типа T размером size, поиск элемента number типа T
    template<typename T>
    size_t SearchInArray_equal(const T* array, size_t size, T number) {
        for (size_t i = 0; i < size; i++) {
            if (number == array[i]) {
                return i; //возвращаем элемент
            }
        }
        return size; //возвращаем размер, такого элемента нет в массиве
    }

    //функция бинарного поиска в массиве array типа T размером size, поиск элемента number типа T
    template<typename T>
    size_t SearchInArray_bin(const T* array, size_t size, T number) {
        size_t L = 0; //Левая граница массива
        size_t R = size; //правая граница массива

        while (L < R) { 
            size_t n = L + (R - L) / 2;

            if (array[n] == number) { return n; } //если угадали, возвращаем элемент
            else if (array[n] < number) { L = n + 1; } //если эллемент больше увеличиваем левую границу
            else { R = n; } // уменьшаем правую границу
        }

        return size; // Возвращаем size, если элемент не найден
    }

    //функция интерполяционного поиска в массиве array типа T размером size, поиск элемента number типа T
    template<typename T>
    size_t SearchInArray_interpol(const T* array, size_t size, T number) {
        size_t x = 0;
        size_t L = 0;
        size_t R = size - 1;

        //Цикл поиска по массиву, пока искомое не найдено 
        //или пределы поиска еще существуют
        while ( number > array[L] && number < array[R]) {

            //Вычисление интерполяцией индекса следующего элемента, который будет сравниваться с искомым
            x = L + ((number - array[L]) * (R - L)) / (array[R] - array[L]); 
            //Получение новых границ области, если искомое не найдено
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

    //проверка сортировки массива array по возратанию размера size
    template<typename T>
    bool is_sorted(const T* array, size_t size) {
        for (size_t i = 1; i < size; i++) {
            if (array[i - 1] > array[i]) {
                return false;
            }
        }
        return true;
    }

    // Функция сортировки пузырьком. Функция принимает массив array типа T, разммер size типа T
    template<typename T>
    void sortbubble (T* array, size_t size) {
        bool swapped; // Флаг для проверки, были ли обмены на текущей итерации
        for (size_t i = 0; i < size - 1; i++) {
            swapped = false; // Сбрасываем флаг перед началом новой итерации
            for (size_t j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) { // Сравниваем соседние элементы
                    // Меняем элементы местами
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = true; // Устанавливаем флаг, если был обмен
                }
            }
            // Если на текущей итерации не было обменов, массив уже отсортирован
            if (!swapped) {
                break;
            }
        }
    }

    // Функция сортировки вставкой. Функция принимает массив array типа T, разммер size типа T
    template<typename T>
    void sortinsertion(T* array, size_t size) {
        for (size_t i = 1; i < size; i++) {
            T key = array[i]; // Текущий элемент, который нужно вставить в отсортированную часть
            size_t j = i;

            // Сдвигаем элементы больше key вправо
            while (j > 0 && array[j - 1] > key) {
                array[j] = array[j - 1];
                j--;
            }

            // Вставляем key на правильное место
            array[j] = key;
        }
    }

    // Функция для слияния двух отсортированных массивов. Принимает массив array типа T, левую и правую границу left rihgt типа size_t, центр массива типа size_t
    template<typename T>
    void merge(T* array, size_t left, size_t mid, size_t right) {
        size_t n1 = mid - left + 1; // Размер левого подмассива
        size_t n2 = right - mid;    // Размер правого подмассива

        // Создаем временные массивы для левой и правой половин
        std::vector<T> L(n1), R(n2);

        // Копируем данные во временные массивы
        for (size_t i = 0; i < n1; i++) {
            L[i] = array[left + i];
        }
        for (size_t j = 0; j < n2; j++) {
            R[j] = array[mid + 1 + j];
        }

        // Слияние временных массивов обратно в основной массив
        size_t i = 0; // Индекс для левого подмассива
        size_t j = 0; // Индекс для правого подмассива
        size_t k = left; // Индекс для основного массива

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

        // Копируем оставшиеся элементы левого подмассива (если они есть)
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        // Копируем оставшиеся элементы правого подмассива (если они есть)
        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }//использовать функцию copy для копирования массива
    }

    // Функция сортировки слиянием. Принимает массив array типа T, левую и правую границу left rihgt типа size_t
    template<typename T>
    void mergeSort(T* array, size_t L, size_t R) {
        if (L < R) {
            size_t mid = L + (R - L) / 2; // Находим середину

            // Рекурсивно сортируем левую и правую половины
            mergeSort(array, L, mid);
            mergeSort(array, mid + 1, R);

            // Сливаем две отсортированные половины
            merge(array, L, mid, R);
        }
    }

    // Функция для разделения массива
    template<typename T>
    size_t partition(T* array, size_t low, size_t high) {
        T pivot = array[high]; // Опорный элемент (последний элемент)
        size_t i = low; // Индекс для элементов меньше опорного

        for (size_t j = low; j < high; j++) {
            if (array[j] < pivot) {
                std::swap(array[i], array[j]); // Меняем местами
                i++;
            }
        }
        std::swap(array[i], array[high]); // Ставим опорный элемент на своё место
        return i; // Возвращаем индекс опорного элемента
    }

    // Основная функция QuickSort
    template<typename T>
    void quickSort(T* array, size_t low, size_t high) {
        if (low < high) {
            size_t pivotIndex = partition(array, low, high); // Индекс опорного элемента

            // Рекурсивно сортируем левую и правую части
            if (pivotIndex > 0) { // Проверка, чтобы избежать underflow
                quickSort(array, low, pivotIndex - 1);
            }
            quickSort(array, pivotIndex + 1, high);
        }
    }
}