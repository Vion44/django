#include <iostream>
#include <cstdlib>  //time
#include <ctime>    //rand, srand
#include <time.h>   //시간 측정

using namespace std;

int sorted[100];

clock_t start, finish, used_time = 0;  

void input_random(int* array, int arrlen) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < arrlen; i++) {
        array[i] = rand() % 100;
    }
}

void display(int* array, int arrlen) {
    for (int i = 0; i < arrlen; i++) {
        cout.width(2);
        cout << i + 1 << ". ";
        cout.width(2);
        cout << array[i] << endl;
    }
}

void CalcTime(void) {
    used_time = finish - start;
    printf("\n*********** 러닝 타임 **********\n     time : %lf sec\n", (double)(used_time) / CLOCKS_PER_SEC);
}

void Merge(int array[], int left, int mid, int right) {
    int l;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            sorted[k++] = array[i++];
        else
            sorted[k++] = array[j++];
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = array[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = array[l];
    }

    for (l = left; l <= right; l++) {
        array[l] = sorted[l];
    }
}
void Merge_sort(int array[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        Merge_sort(array, left, mid);
        Merge_sort(array, mid + 1, right);
        Merge(array, left, mid, right);
    }
}


int main() {
    int array[1];
    int arr_sz = sizeof(array) / sizeof(int);
    input_random(array, arr_sz);   //배열에 랜덤값 삽입

    start = clock();
    Merge_sort(array, 0, arr_sz - 1);    //합병 정렬
    finish = clock();
    display(array, arr_sz);         //show array
    CalcTime();

    return 0;
}
