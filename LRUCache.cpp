#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
	unsigned long int capacity;
	list<int> dList;
	unordered_map<int, list<int>::iterator> mmap;

	LRUCache(int c)
	{
		capacity = c;
	}

	int get(int key)
	{
		if (mmap.find(key) == mmap.end())
			return -1;
		int ret = *mmap[key];
		dList.erase(mmap[key]);
		dList.push_front(key);
		mmap[key] = dList.begin();

		return ret;
	}

	void insert(int key)
	{
		if (dList.size() == capacity)
		{ // Cache Full
			if (mmap.find(key) == mmap.end())
			{
				// Cache miss ; so replace Least recently used  at back of dList
				int keyToReplace = dList.back();
				dList.erase(mmap[keyToReplace]);
				dList.push_front(key);
				mmap.erase(keyToReplace);
				mmap[key] = dList.begin();
//				 Cache miss ;
			}
			else
			{ // cache hit

				dList.erase(mmap[key]);
				dList.push_front(key);
				mmap[key] = dList.begin();

			}
		} // cache Full
		else
		{
			// cache not full
			if (mmap.find(key) == mmap.end())
			{
				// Cache miss ;
				dList.push_front(key);
				mmap[key] = dList.begin();

			}
			else
			{
				// cache hit but not full
				dList.erase(mmap[key]);
				dList.push_front(key);
				mmap[key] = dList.begin();

			}
		}

	}

	void printCache()
	{
		if (!dList.empty())
		{
			for (auto i : dList)
			{
				cout << i << ", ";

			}

		}
		else
		{
			cout << "LRU Empty!!!!!\n";
		}

		cout << endl;
	}

};

int main(int argc, char **argv)
{
	LRUCache lru(3);
	int c = 1;
	int key;
	while (c)
	{
		cout << "Menu\n";
		cout << "1. insert()\n";
		cout << "2. get()\n";
		cout << "0. to exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "enter key to be inserted\n";
			cin >> key;
			lru.insert(key);
			cout << "\nLRU status now -->  ";
			lru.printCache();
			break;
		case 2:
			cout << "enter key to get from lru\n";
			cin >> key;
			cout << "get Result = " << lru.get(key) << endl;
			cout << "\nLRU status now -->  ";
			lru.printCache();
			break;
		case 0:
			exit(0);
		default: continue;

		}

	}

	return 0;
}
