#include<iostream>
using namespace std;


void bestFitAlgorithm(int proces_sizes[], int block_sizes[], int p, int b) {
	int* allocated_blocks = new int[p];

	//step 2: Initialize all memory blocks as free

	for (int i = 0; i < p; i++) {
		allocated_blocks[i] = -1;
	}

	for (int i = 0; i < p; i++) {
		
		for (int j = 0; j < b; j++) {
			if (block_sizes[j] >= proces_sizes[i]) {
				
				allocated_blocks[i] = j;
				block_sizes[j] -= proces_sizes[i];
				break;
			}
		}
	}

	cout << "\n Process id \t Process Size \t Block No. \n";
	for (int i = 0; i < p; i++) {
		cout << "\n  p00" << i + 1 << "\t\t   " << proces_sizes[i] << "\t\t   ";
		if (allocated_blocks[i] != -1)
			cout << allocated_blocks[i] + 1;
		else
			cout << " Not Allocated.. ";
	}
}

int main() {
	int p, b;
	cout << "Enter the number of processes: ";
	cin >> p;
	cout << "\n Enter the number of memory Blocks: ";
	cin >> b;
	int* processSizes = new int[p];
	int* blockSizes = new int[b];
	// Step1: Input process sizes and Block sizes
	for (int i = 0; i < p; i++) {
		cout << "\nEnter the size of process " << i + 1 << " : ";
		cin >> processSizes[i];
	}

	for (int i = 0; i < b; i++) {
		cout << "\n Enter the size of block " << i + 1 << " : ";
		cin >> blockSizes[i];
	}

	cout << "\n\n \t\t------- FIRST FIT ALGORITHM--------\n";
	bestFitAlgorithm(processSizes, blockSizes, p, b);
	return 0;
}