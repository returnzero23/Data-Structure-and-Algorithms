#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<class T>
list<T> Intersection(const list<T>& list1, const list<T>& list2){
    list<T> result;
    auto itr1 = list1.begin();
    auto itr2 = list2.begin();
    while(itr1 != list1.end() && itr2 != list2.end()){
        cout << "itr1:" << *itr1 << " itr2:" << *itr2 << endl;
        const T val = *itr1 - *itr2;
        if(val == 0){
            cout << "equal" << endl;
            result.push_back(*itr1);
            itr1++;
            itr2++;
        }else if(val < 0){
            cout << "itr1++" << endl;
            itr1++;
        }else{
            cout << "itr2++" << endl;
            itr2++;
        };
    }
    return result;
}

int main(){
    list<int> list1 = {1,2,3,4,5,5,5,9};
    list<int> list2 = {3,4,4,5,5,6,7,8,9,10};

    auto print = [](const int& n) { std::cout << " " << n; };

    cout << "list1:";
    for_each(list1.begin(),list1.end(),print);
    cout << endl;

    cout << "list2:";
    for_each(list2.begin(),list2.end(),print);
    cout << endl;

    list<int> result = Intersection(list1, list2);

    cout << "result:";
    for_each(result.begin(),result.end(),print);
    cout << endl;

    return 0;
}