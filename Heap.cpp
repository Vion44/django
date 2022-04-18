#include <iostream>
#include <cstdlib>  //time
#include <ctime>    //rand, srand
#include <time.h>   //시간 측정

using namespace std;

#define MAX_ARRAY_SIZE 100

int maxValue = 0;     

clock_t start, finish, used_time = 0;   

void input_random(int* array, int arrlen) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < arrlen; i++) {
        array[i] = rand() % 99 + 1;
        maxValue = (maxValue < array[i]) ? array[i] : maxValue;
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

/*top-down*/
void top_down_heapify(int* array, int arrlen) {
     */
    for (int i = 1; i < arrlen; i++) {
        int child = i;
        while (child > 0) {
            int parent = (child - 1) / 2;

            if (array[parent] < array[child]) {
                swap(array[parent], array[child]);
            }
            child = parent;
        }
    }
}

/*bottom-up*/
void bottom_up_heapify(int* array, int parent, int arrlen) {
    while (parent <= arrlen) {
        int largest = parent;
        int l = parent * 2 + 1;
        int r = parent * 2 + 2;

        if (l < arrlen && array[largest] < array[l]) {
            largest = l;
        }
        if (r < arrlen && array[largest] < array[r]) {
            largest = r;
        }
        if (largest != parent) {
            swap(array[parent], array[largest]);
            parent = largest;
        }
        else parent = l;
    }
}

void top_down_HeapSort(int* array, int arrlen) {
    top_down_heapify(array, arrlen);  

    for (int i = arrlen - 1; i >= 0; i--) {
        swap(array[i], array[0]);  
        top_down_heapify(array, i);         
    }                              

void bottom_up_HeapSort(int* array, int arrlen) {
    for (int i = arrlen / 2 - 1; i >= 0; i--) {
        bottom_up_heapify(array, i, arrlen);
    }

    for (int i = arrlen - 1; i >= 0; i--) {
        swap(array[i], array[0]);                
        bottom_up_heapify(array, 0, i);          
    }
}



int main() {
    int* array = new int[MAX_ARRAY_SIZE];

    input_random(array, MAX_ARRAY_SIZE);     //배열에 랜덤값 삽입
    start = clock();
    bottom_up_HeapSort(array, MAX_ARRAY_SIZE);         //계수 정렬
    finish = clock();
    display(array, MAX_ARRAY_SIZE);          //show array
    CalcTime();

    return 0;
}
