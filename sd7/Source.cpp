#include "Header.h"
#include <chrono>
//test gihub
//1000 < serNo < 2000000
int main()
{
	srand(time(NULL));

	int N = 1000;

	HashTable* table = new HashTable(N * 1.5);
	
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 100; ++i)
	{
		table->insertItem(10000 + i, rand() % 1000);	
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Add first 100: " << duration.count() << "s" << endl;

	for (int i = 100; i < N - 100; ++i)
	{
		table->insertItem(10000 + i, rand() % 1000);
	}

	start = chrono::high_resolution_clock::now();
	for (int i = N - 100; i < N; ++i)
	{
		table->insertItem(10000 + i, rand() % 1000);
	}
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Add last 100: " << duration.count() << "s" << endl;

	start = chrono::high_resolution_clock::now();
	table->getItem(10022);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Search: " << duration.count() << "s" << endl;

	return 0;
}