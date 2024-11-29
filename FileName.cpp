#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int n, el;
	fin >> n;
	//std::cin >> n;

	int* heap = new int[n + 1];
	for (int i = 1; i <= n; ++i) {
		fin >> el;
		//std::cin >> el;
		heap[i] = el;
	}

	bool isHeap = true; 
	for (int i = 1; i <= n / 2; ++i) {
		int leftChildIndex = 2 * i;
		int rightChildIndex = 2 * i + 1;

		if (leftChildIndex <= n && heap[i] > heap[leftChildIndex]) {
			isHeap = false;
			break;
		}
		if (rightChildIndex <= n && heap[i] > heap[rightChildIndex]) {
			isHeap = false;
			break;
		}
	}

	if (isHeap) {
		fout << "YES\n";
		//std::cout << "YES\n";
	}
	else {
		fout << "NO\n";
		//std::cout << "NO\n";
	}
	fin.close();
	fout.close();
	delete[] heap;
	return 0;

}