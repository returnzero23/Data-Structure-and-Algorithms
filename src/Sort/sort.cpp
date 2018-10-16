#include <iostream>

template<typename T>
void BubbleSort(T* array, const int size){
    for(int i = 0; i < size; i++){
        bool flag = false;
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
        }
        if(!flag) break;
    }
};

template<typename T>
void InsertionSort(T* Array, const int size){
    if(size <= 1)return;
    
    for(size_t i = 1; i < size; i++)
    {
        int InsertData = Array[i];
        for(size_t j = 0; j < i; j++)
        {
            if(InsertData < Array[j]){
                for(size_t k = i; k > j; k--)
                {
                    Array[k] = Array[k-1];
                }
                Array[j] = InsertData;
                break;
            }
        }
    }
};

template<typename T>
void SelectionSort(T* Array, const int size){
    
};

int main(){
    int Array1[] = {1,2,3,43,1,4,3,1,34,4,5};
    BubbleSort(Array1,11);
    for(int i = 0 ; i < 11 ; i++){
        std::cout << Array1[i] << std::endl;
    }

    int Array2[] = {1,2,3,43,1,4,3,1,34,4,5};
    InsertionSort(Array2,11);
    for(int i = 0 ; i < 11 ; i++){
        std::cout << Array2[i] << std::endl;
    }
    return 0;
}