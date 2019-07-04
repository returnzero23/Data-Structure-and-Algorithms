#include <iostream>
#include <list>

using namespace std;

template<class T>
class List: public list<T>
{
public:
    class reverse_iterator : public list<T>::iterator {
    public:
        explicit reverse_iterator(typename list<T>::iterator pItr):
            list<T>::iterator(pItr)
        {}

        reverse_iterator operator++ (){
            return reverse_iterator(list<T>::iterator::operator--());
        }

        reverse_iterator operator-- (){
            return reverse_iterator(list<T>::iterator::operator++());
        }
    };

    reverse_iterator rbegin(){
        return reverse_iterator(--list<T>::end());
    }

    reverse_iterator rend(){
        return reverse_iterator(--list<T>::begin());
    }
};

int main(){
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);

    auto print = [](const int& n) { std::cout << " " << n; };

    cout << "list1:";
    for_each(list.begin(),list.end(),print);
    cout << endl;

    cout << "list1:";
    for_each(list.rbegin(),list.rend(),print);
    cout << endl;



}