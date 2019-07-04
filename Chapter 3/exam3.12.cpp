#include <iostream>

using namespace std;

template<class T>
class SList{
private:
    struct Node{
        Node(const T& pData, Node* pNext = nullptr):
            Data(pData),
            Next(pNext)
        {};
        T Data;
        Node* Next = nullptr;
    };
public:
    SList(){
        Init();
    };

    int Size(){
        return m_Size;
    }

    void Insert(const T& pData){
        Node* Itr = m_Head;
        Node* Pre = m_Head;
        while(Itr->Next != nullptr && pData >= Itr->Next->Data){
            Pre = Itr;
            Itr = Itr->Next;
        }

        if(pData == Itr->Data && Itr != m_Head) {
            Pre->Next = Itr->Next;
            --m_Size;
        }else{
            Itr->Next = new Node(pData, Itr->Next);
            ++m_Size;
        };
    }

    void Print(){
        Node* Index = m_Head;
        while(Index->Next != nullptr)
        {
            Index = Index->Next;
            cout << Index->Data << " ";
        }
        cout << endl;
    }

    bool IsInList(const T& pData){
        Node* Index = m_Head;
        while(Index->Next != nullptr && pData > Index->Data)
        {
            Index = Index->Next;
            if(Index->Data == pData) return true;
        }
        return false;
    }
private:
    Node* m_Head = nullptr;
    int m_Size = 0;

    void Init(){
        m_Head = new Node(0);
    }
};

int main(){
    SList<int> list;
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(4);
    list.Insert(10);
    list.Insert(2);
    list.Insert(5);
    list.Print();
    cout << "size:" << list.Size() << endl; 
    cout << "10 in list : " << list.IsInList(10) << endl;
    cout << "5 in list : " << list.IsInList(5) << endl;
    cout << "2 in list : " << list.IsInList(2) << endl;

    return 0;
}
