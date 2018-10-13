#include <iostream>

class List{
    struct Node{
        Node(const int data):
            data(data),
            nextNode(nullptr)
        {};

        Node():
            data(0),
            nextNode(nullptr)
        {};

        int data;
        Node* nextNode = nullptr;
    };
public:
    List(){
        m_head = m_lastNode = new Node;
    }
    ~List(){
        Node* IndexNode = m_head;
        while(IndexNode->nextNode){
            Node* NextNode = IndexNode->nextNode;
            delete IndexNode;
            IndexNode = NextNode;
        }
        delete IndexNode;
        IndexNode = nullptr;
        m_length = 0;
    };

    void Add(const int data){
        m_lastNode->nextNode = new Node(data);
        m_lastNode = m_lastNode->nextNode;
        m_length++;
    };

    void DeleteByElement(const int data){
        Node* IndexNode = m_head->nextNode; // head 的nextNode 可能为空
        Node* PreNode = m_head;
        while(IndexNode){   //判断条件使用当前节点是不是存在而不是下一个节点存不存在。
            Node* NextNode = IndexNode->nextNode;
            if(IndexNode->data == data){
                delete IndexNode;
                m_length--;
                PreNode->nextNode = NextNode;

                //如果删除的是最后一个节点 需要改变m_lastNode
                if(!NextNode){
                    m_lastNode = PreNode;
                }
            }else{
                PreNode = IndexNode;
            }
            IndexNode = NextNode;
        }
    };

    void DeleteByIndex(const int Index){

    };

    void PrintList(){
        Node* IndexNode = m_head->nextNode;
        std::cout << "the list has " << m_length << " elements" << std::endl;
        while(IndexNode){
            std::cout << IndexNode->data << std::endl;
            IndexNode = IndexNode->nextNode;
        }
    };

private:
    Node* m_head = nullptr;
    Node* m_lastNode = nullptr;
    int m_length = 0;
};
int main(){
    List list;
    list.Add(1);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(4);
    list.PrintList();
    list.DeleteByElement(1);
    list.PrintList();
    list.DeleteByElement(4);
    list.PrintList();

}