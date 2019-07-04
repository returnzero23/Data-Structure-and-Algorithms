#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void VectorInsert(vector<T>& pContainer, int pos, const T& pVal){
    int index = pContainer.size();
	pContainer.push_back(0);//vc 包含下标索引检查
    while(index > pos){
        pContainer[index] = pContainer[index - 1];
        index--;
    }
    pContainer[pos] = pVal;
}

template<class T>
void VectorErase(vector<T>& pContainer, int pos){
    const int size = pContainer.size();
    int index = pos;
    while(index < size - 1){
        pContainer[index] = pContainer[index + 1];
        index++;
    }
	pContainer.pop_back();
}

int main() {
	vector<int> vec{ 0,1,2,3,4,5,6 };
	auto print = [](const int& n) { std::cout << " " << n; };


	cout << "vec insert before:";
	for_each(vec.begin(), vec.end(), print);
	cout << endl;

	VectorInsert(vec,3,10);

	cout << "vec insert after:";
	for_each(vec.begin(),vec.end(),print);
	cout << endl;

	VectorErase(vec, 3);

	cout << "vec erase after:";
	for_each(vec.begin(),vec.end(),print);
	cout << endl;
	return 0;
}