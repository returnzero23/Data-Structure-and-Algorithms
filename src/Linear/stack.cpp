#include <iostream>

template<typename T>
struct Node{
    using ptr_t = std::shared_ptr< Node<T> >;

    Node(const T& data):
        data(data),
        next(nullptr)
    {};

    Node(const T& data, ptr_t next):
        data(data),
        next(next)
    {};
    T data;
    ptr_t next; 
};

template<typename T>
class Stack{
public:
    using NodeType = typename Node<T>::ptr_t;

    Stack():
        m_top(nullptr)
    {};

    void push(const T& data){
        //error
        //m_top = std::make_shared< Node<T> >(new Node<T>(data));
    };

    void top() const {

    };

    T& pop(){

    };

private:
    NodeType m_top;
    
};

int main(){
    Stack<int> stack;
    stack.push(1);
    return 0;
}