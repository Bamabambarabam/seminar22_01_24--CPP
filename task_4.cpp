#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



struct rnd {
    int operator()() {
        return rand() % 250000;
        // We fill the array with random numbers up to 250000
    }
};

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

int main() {
    int count = 1;
    for(int i = 1; i <= 50; i ++){
        const size_t LARGE_SIZE = count;
        int arr[LARGE_SIZE];
        int arr_copy[LARGE_SIZE];
        // Рандомизация по таймеру
        srand(time(nullptr));
        // генерируем случайные данные
        generate( arr, arr + LARGE_SIZE, rnd() );
        copy( arr, arr + LARGE_SIZE, arr_copy );
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        cout << i << " " << count << " ";
        qsort( arr, LARGE_SIZE, sizeof( int ), comp );
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << " ";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort( arr_copy, arr_copy + LARGE_SIZE );
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
        count += 5000;
    }
    return 0;
}
