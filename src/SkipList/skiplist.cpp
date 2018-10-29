#include <iostream>

template<typename T>
class SkipList{
public:
    bool find(const T& data,const int index){
        return false;
    };

    bool insert(const T& data){
        return false;
    };

    bool deleteByIndex(const int index){
        return false;
    };

private:
    void randomLevel(){

    };

private:
    template< typename U>
    class Node {
        T data;
        Node* NextNode = nullptr;

    };

};

int main(){

    return 0;
}