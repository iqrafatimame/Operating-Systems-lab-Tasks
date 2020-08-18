#include<iostream>
using namespace std;

void calculateNeed(int** need, int** maxDemand, int** allocation, int p, int r) {
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++)
			need[i][j] = maxDemand[i][j] - allocation[i][j];
}


bool checkSafe(int** allocation, int* availResources, int** maxDemand, int p, int r) {
	int** need = new int*[p];
	for (int i = 0; i < p; ++i) 
		need[i] = new int[r];

	calculateNeed(need, maxDemand, allocation, p, r);
	bool* finish = new bool[p];
	int* safeSequence = new int[p];
	int* work = new int[r];
	for (int i = 0; i < p; i++) {
		finish[i] = 0;
	}
	for (int i = 0; i < r; i++)
		work[i] = availResources[i];

	int count = 0;
	while (count < p)
	{
		bool found = false;
		for (int i = 0; i < p; i++)
		{
			if (finish[i] == 0)
			{
				int j;
				for (j = 0; j < r; j++)
					if (need[i][j] > work[j])
						break;
				if (j == r)
				{
					for (int k = 0; k < r; k++)
						work[k] += allocation[i][k];

					safeSequence[count++] = i;
					finish[i] = 1;
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "----------------" << endl;
			cout << "|  D A N G E R  |" << endl;
			cout << "----------------" << endl;
			cout << "The system is not in safe state...";
			return false;
		}
	}

	cout << "----------Safe Sequence----------"<< endl << endl;
	for (int i = 0; i < p; i++) {
		cout << "p00" << safeSequence[i] + 1 << " -> ";
	}
	cout << "\n\n";
}


int main() {
	int p;
	int r;
	cout << "Enter the number of processes: ";
	cin >> p;
	cout << endl << "Enter the number of resources for each process: ";
	cin >> r;

	int** allocation = new int*[p];
	int** maxDemand = new int*[p];
	int* availResources = new int[r];
	for (int i = 0; i < p; ++i) {
		allocation[i] = new int[r];
		maxDemand[i] = new int[r];
	}
	
	for (int i = 0; i < p; i++)
	{
		
		for (int j = 0; j < r; j++)
		{
			cout << endl << "Enter " << r << " resources for p00" << i + 1 << ": ";
			cin >> allocation[i][j] ;
		}
	}

	for (int i = 0; i < p; i++)
	{
		cout << endl << "Enter " << r << " maximum demands for p00 " << i + 1 << ": ";
		for (int j = 0; j < r; j++)
		{
			cin >> maxDemand[i][j];
		}
	}

	cout << endl << "Enter the available resources: ";
	for (int i = 0; i < r; i++) 
		cin >> availResources[i];
	
	checkSafe(allocation, availResources, maxDemand, p, r);
	return 0;
}