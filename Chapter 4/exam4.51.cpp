#include <iostream>
#include <list>
#include <string>

using namespace std;

const string gInputString =
"IX: {Series|(}            {2}"
"IX: {Series!geometric|(}  {4}"
"IX: {Euler`s constant}    {4}"
"IX: {Series!geometric|)}  {4}"
"IX: {Series!arithmetic|(} {4}"
"IX: {Series!arithmetic|)} {5}"
"IX: {Series!harmonic|(}   {5}"
"IX: {Euler`s constant}    {5}"
"IX: {Series!harmonic|)}   {5}"
"IX: {Series|)}            {5}";

enum IndexType {
	EStartIndex = 0,
	EStopIndex,
	ESplit,
};

class IndexItem
{
	string m_name;
	int m_StartIndex;
	int m_StopIndex;
	list<int> Indexs;
	list<IndexItem> Subjects;
public:
	void Add(string name, int index, IndexType type) {
		size_t nameStart = name.find_first_of("!");
		if (nameStart == string::npos) {
			m_name = name;
			switch (type) {
				case EStartIndex:m_StartIndex = index; break;
				case EStopIndex:m_StopIndex = index; break;
				case ESplit:Indexs.push_back(index); break;
			}
		}
		else {
			size_t nameEnd = name.find_first_of("!", nameStart + 1);
			size_t subjectNamelength = nameEnd == string::npos ? name.length() - nameStart : nameEnd - nameStart;
			auto itr = Subjects.begin();
			string subjectName = name.substr(nameStart + 1, subjectNamelength - 1);
			IndexItem* NewIndexItem = nullptr;
			bool found = false;
			while (itr != Subjects.end()) {
				if (itr->m_name == subjectName) {
					NewIndexItem = &(*itr);
					found = true;
				}
				++itr;
			}
			if (found) 
			{
				NewIndexItem->Add(name.substr(nameStart + 1, name.length() - 1), index, type);
			}
			else 
			{
				NewIndexItem = new IndexItem();
				NewIndexItem->m_name = subjectName;
				NewIndexItem->Add(name.substr(nameStart + 1, name.length() - 1), index, type);
				Subjects.push_back(*NewIndexItem);
				delete NewIndexItem;
				NewIndexItem = nullptr;
			}		
		}
	}

	void PrintIndex(int Tabsize) {

		int tempTabsize = Tabsize;
		while (tempTabsize--) { cout << "    "; }

		if(m_name.size() > 0) cout << m_name << ": ";

		auto itr = Subjects.begin();


		if (Indexs.size() > 0) {
			auto itr = Indexs.begin();
			while (itr != Indexs.end())
			{
				cout << *itr << ",";
				++itr;
			}
			cout << endl;
		}
		else if(m_StopIndex != 0 && m_StartIndex != 0)
		{
			if ((m_StopIndex - m_StartIndex) > 0) {
				cout << m_StartIndex << "-" << m_StopIndex << endl; 
			}
			else {
				cout << m_StartIndex << endl;
			}
		}

		while (itr != Subjects.end()) {
			itr->PrintIndex(Tabsize + 1);
			++itr;
		}

	}
};

int main()
{
	IndexItem indexItem;
	indexItem.Add("!Series", 2, EStartIndex);
	indexItem.Add("!Series!geometric", 4, EStartIndex);
	indexItem.Add("!Euler`s constant", 4, ESplit);
	indexItem.Add("!Series!geometric", 4, EStopIndex);
	indexItem.Add("!Series!arithmetic", 4, EStartIndex);
	indexItem.Add("!Series!arithmetic", 5, EStopIndex);
	indexItem.Add("!Series!harmonic", 5, EStartIndex);
	indexItem.Add("!Euler`s constant", 5, ESplit);
	indexItem.Add("!Series!harmonic", 5, EStopIndex);
	indexItem.Add("!Series", 5, EStopIndex);
	indexItem.PrintIndex(0);
	return 0;
}