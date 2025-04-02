
#include "test.h"   // модуль с тестоами, в который включается модуль с сортировками
#include "time_count.h"



using namespace std;
using namespace test;
using namespace time_count;


int main() {
    All_test();

    const long long n = 15;

    int TimeRequest = measure_time([&]() {
        int* array = random_array<int>(n, 1, 7);

        sortquick(array, 0, n - 1);
        /*for (int i = 0; i < n; i++) {
            cout << array[i] << "";
        }*/
        std::cout << "\n";
        delete[] array;
        }// строки от лямда функции и до этой вставляются в функцию подсчёта времени.
    ); 

    std::cout << TimeRequest;


    return 0;
}