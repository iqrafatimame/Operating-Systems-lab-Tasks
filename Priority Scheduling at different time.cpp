#include<iostream>
using namespace std;

void calculateTime(int processes[], int n, int arrival_t[], int burst_t[], int priority[]) {
	int* wt = new int[n];
	int* tat = new int[n];
	int* comp_t = new int[n];
	int total_wt = 0;
	int total_tat = 0;

	//sorting the processes and burst time according to the priority
	for (int i = 0; i < n; i++)
	{
		int pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (priority[j] < priority[pos])
				pos = j;
		}

		int temp = priority[i];
		priority[i] = priority[pos];
		priority[pos] = temp;

		temp = burst_t[i];
		burst_t[i] = burst_t[pos];
		burst_t[pos] = temp;

		temp = processes[i];
		processes[i] = processes[pos];
		processes[pos] = temp;
	}

	cout << "\n\n";


	for (int i = 0; i < n; i++) {
		cout << "Process : " << i + 1 << "\t" << "Burst time: " << burst_t[i] << "\t";

		if (i == 0)
			comp_t[i] = 0;
		else
			comp_t[i] = comp_t[i - 1] + burst_t[i];
		cout << "completion time: " << comp_t[i] << " ";

		if (i == 0)
			wt[i] = 0;
		else
			wt[i] = burst_t[i - 1] + wt[i - 1];
		cout << "Waiting Times: " << wt[i] << "  ";

		tat[i] = wt[i] + burst_t[i];
		cout << "TurnAround Time: " << tat[i] << endl;


	}
	int sum_wt = 0;
	int sum_tat = 0;
	for (int i = 0; i < n; i++) {
		sum_wt = sum_wt + wt[i];
		sum_tat = sum_tat + tat[i];
	}
	float avg_wt = (float)sum_wt / (float)n;
	float avg_tat = (float)sum_tat / (float)n;
	cout << "\nAverage waiting Time :  " << avg_wt << endl;
	cout << "Average turnaound time:  " << avg_tat << endl;
}

int main() {
	int noOfProcesses;

	cout << "enter the number of processes: ";
	cin >> noOfProcesses;
	int* arrival_t = new int[noOfProcesses];
	int* processes = new int[noOfProcesses];
	int* burst_t = new int[noOfProcesses];
	int* priority = new int[noOfProcesses];
	for (int i = 0; i < noOfProcesses; i++) {
		processes[i] = i + 1;
		arrival_t[i] = 0;
	}

	for (int i = 0; i < noOfProcesses; i++) {
		cout << "Enter Burst Time of Process " << i + 1 << "   : ";
		cin >> burst_t[i];
		cout << "Enter priority of process: " << i + 1 << "    : ";
		cin >> priority[i];
		cout << endl;
	}
	cout << endl << "\t\t\t\t-------PRIORITY SCHEDUALING AT SAME ARRIVAL TIME-------- \n\n\n";
	calculateTime(processes, noOfProcesses, arrival_t, burst_t, priority);


}