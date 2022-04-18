#include <iostream>
#include <cstdlib>  //time
#include <ctime>    //rand, srand
#include <time.h>   //시간 측정

using namespace std;

clock_t start, finish, used_time = 0;    //실행 시간 측정을 위한 변수

void input_random(int* array, int arrlen) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < arrlen; i++) {
        array[i] = rand() % 100;
    }
}

void display(int* array, int arrlen) {
    for (int i = 0; i < arrlen; i++) {
        cout.width(3);
        cout << i + 1 << ". ";
        cout.width(2);
        cout << array[i] << endl;
    }
}

void CalcTime(void) {
    used_time = finish - start;
    printf("\n*********** 러닝 타임 **********\n     time : %lf sec\n", (double)(used_time) / CLOCKS_PER_SEC);
}

void Exchange_sort(int* array, int arrlen) {

    for (int i = arrlen - 1; i > 0; i--) {

        for (int j = 0; j < i; j++)
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
    }
}

int main() {
    int array[100];

    int arr_sz = sizeof(array) / sizeof(int);
    input_random(array, arr_sz);   //배열에 랜덤값 삽입
    start = clock();
    Exchange_sort(array, arr_sz);    //교환 정렬
    finish = clock();
    display(array, arr_sz);         //show array
    CalcTime();

    return 0;
}
