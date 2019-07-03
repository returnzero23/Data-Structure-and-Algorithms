#include <iostream>
#include <vector>

using namespace std;

template<class T>
void VectorInsert(vector<T>& pContainer, int pos, const T& pVal){
    int index = pContainer.size();
    while(index > pos){
        cout << pos << " " << index << endl;
        pContainer[index] = pContainer[index - 1];
        index--;
    }
    pContainer[pos] = pVal;
}

// template<class T>
// void VectorErase(vector<T>& pContainer, int pos){
//     int index = pContainer.size();
//     while(index > pos){
//         cout << pos << " " << index << endl;
//         pContainer[index] = pContainer[index - 1];
//         index--;
//     }
//     pContainer[pos] = pVal;
// }

int main(){
    vector<int> vec{0,1,2,3,4,5,6};
    VectorInsert(vec,3,10);

    auto print = [](const int& n) { std::cout << " " << n; };

    cout << "vec:";
    for_each(vec.begin(),vec.end(),print);
    cout << endl;
}