#include <iostream>

template<typename T>
struct Node{
    //using ptr_t = std::shared_ptr< Node<T> >;

    Node(const T& data):
        data(data),
        next(nullptr)
    {};

    Node(const T& data, Node<T>* next):
        data(data),
        next(next)
    {};
    T data;
    Node<T>* next; 
};

template<typename T>
class Stack{
public:
    //using NodeType = typename Node<T>::ptr_t;
    using NodeType = Node<T>;

    Stack():
        m_top(nullptr)
    {};

    //template<typename T1>
    void push(const T& data){
        m_top = new NodeType(data,m_top);
        m_length++;
    };

    bool top(T& data) const {
        if(!m_top) return false;
        data = m_top->data;
        return true;
    };

    bool pop(T& data){
        if(!m_top) return false;
        data = m_top->data;
        m_top = m_top->next;
        m_length--;
        return true;
    };

    friend std::ostream& operator<< (std::ostream& os,Stack<T>& list){
        NodeType* IndexNode = list.m_top;
        std::cout << "this stack has "<< list.m_length << " eles"<< std::endl;
        while(IndexNode){
            std::cout << IndexNode->data << std::endl;
            IndexNode = IndexNode->next;
        }
        return os;
    };

private:
    NodeType* m_top;
    int m_length = 0;
};

int main(){
    Stack<int> stack;
    stack.push(1);
    stack.push(1);
    stack.push(1);
    std::cout << stack << std::endl;
    int data = 0;
    std::cout << "top" << std::endl;
    if(stack.top(data)){
        std::cout << data << std::endl;
    }
    std::cout << stack << std::endl;
    std::cout << "pop" << std::endl;
    if(stack.pop(data)){
        std::cout << data << std::endl;
    }
    std::cout << stack << std::endl;

    Stack<float> floatstack;
    floatstack.push(1.1f);
    floatstack.push(1.2f);
    floatstack.push(1.4f);
    std::cout << floatstack << std::endl;
    float floatdata = 0.0;
    std::cout << "top" << std::endl;
    if(floatstack.top(floatdata)){
        std::cout << floatdata << std::endl;
    }
    std::cout << floatdata << std::endl;
    std::cout << "pop" << std::endl;
    if(floatstack.pop(floatdata)){
        std::cout << floatdata << std::endl;
    }
    std::cout << floatstack << std::endl;
    
    return 0;
}