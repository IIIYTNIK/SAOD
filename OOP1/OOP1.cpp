
#include "test.h"   // модуль с тестоами, в который включается модуль с сортировками
#include "time_count.h"



using namespace std;
using namespace test;
using namespace time_count;




int main() {
    All_test();

    const long long n = 40;

    int TimeRequest = measure_time([&]() {
        int* array = random_array<int>(n, 1, 7);

        quickSort(array, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << array[i];
        }
        delete[] array;
        }// строки от лямда функции и до этой вставляются в функцию подсчёта времени
    ); 

    cout << TimeRequest;


    return 0;
}