#pragma once
#include <iostream>

using namespace std;

struct Object
{
	int serNo;
	int price;
};

class HashTable
{
private:
	Object** arr;
	unsigned long int size;
	int count;			//amount of elemets in table now

public:
	HashTable(int size)
	{
		this->size = size;
		count = 0;
		arr = new Object * [size];

		for (int i = 0; i < size; ++i)
		{
			arr[i] = nullptr;
		}
	}

	int hashFunction(unsigned long int key)
	{
		key *= key;
		key >>= 11;

		return key % 1024;
	}

	int re_hashing(int hashIndex, int i)
	{
		return ((hashIndex + 3 + 7 * i + 19 * i * i) % size);
	}

	void insertItem(int key, int value)
	{
		if (count == size)
		{
			cout << "Hash table is full\n";
			return;
		}
		int hashIndex = hashFunction(key);

		for (int i = 1; arr[hashIndex] != nullptr; ++i)
		{
			hashIndex = re_hashing(hashIndex, i);
		}

		arr[hashIndex] = new Object();
		arr[hashIndex]->serNo = key;
		arr[hashIndex]->price = value;

		count++;
	}

	int getItem(int key)
	{
		if (count == 0)
			cout << "Hash table is empty\n";

		int hashIndex = hashFunction(key);
		int temp = hashIndex;

		while (true)
		{
			int i = 1;

			if (arr[hashIndex] == nullptr)
			{
				hashIndex = re_hashing(hashIndex, i);
			}
			else if (arr[hashIndex]->serNo != key)
			{
				hashIndex = re_hashing(hashIndex, i);
			}
			else if (arr[hashIndex]->serNo == key)
			{
				break;
			}

			if (hashIndex == temp)
			{
				temp = -1;
				break;
			}

			++i;
		}

		if (temp == -1)
		{
			cout << "Elemnt is not in the table\n";
		}
		else
		{
			return arr[hashIndex]->price;
		}

	}
};