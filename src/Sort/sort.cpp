#include <iostream>

template<typename T>
void BubleSort(T* array, const int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
};

template<typename T>
void InsertionSort(T* Array, const int size){
    
};

template<typename T>
void SelectionSort(T* Array, const int size){
    
};

int main(){
    int Array[] = {1,2,3,43,1,4,3,1,34,4,5};
    BubleSort(Array,11);
    for(int i = 0 ; i < 11 ; i++){
        std::cout << Array[i] << std::endl;
    }
    return 0;
}