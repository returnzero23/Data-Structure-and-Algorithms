#include <iostream>

class Array{
public:
    Array(const int size){
        m_Array = new int(size);
        m_Length = 0;
        m_Capacity = size;
    };
    ~Array(){
        delete[] m_Array;
        m_Array = nullptr;
        m_Capacity = 0;
        m_Length = 0;
    };
    //添加元素
    void Add(const int ele){
        if(m_Capacity == m_Length || m_Capacity == 0){
            if(m_Capacity == 0) {
                m_Capacity = 4;
            }else{
                m_Capacity *= 2;
            };
            int* New_Array = new int(m_Capacity);
            for(int i = 0; i < m_Length; i++){
                New_Array[i] = m_Array[i];
            };
            delete[] m_Array;
            m_Array = New_Array; 
        }
        m_Array[m_Length] = ele;
        m_Length++;
    }

    //删除某个索引的值
    void Remove(const int index){

    }

    //修改某个索引的值
    void Set(const int index,const int ele){
        
    }

    //获取某个索引的值
    int Get(const int index){

    }
    
    //索引访问
    int& operator [](const int index){
        return m_Array[index];
    };

private:
    int* m_Array = nullptr;
    int m_Length;
    int m_Capacity;
};

int main(){
    Array array(10); //新建十个元素的数组
    array.Add(1);
    array.Add(2); 
    array.Add(3); 
    array.Add(4); 
    array.Add(5); 
    array.Add(6); 
    array.Add(7); 
    array.Add(8); 
    array.Add(9);
    //其他操作 

}