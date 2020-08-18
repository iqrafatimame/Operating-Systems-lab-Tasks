#include<iostream>
using namespace std;

void calculateTime(int processes[], int n, int arrival_t[], int burst_t[]){
	int* wt = new int[n];
	int* tat = new int[n];
	int* comp_t = new int[n];
	int total_wt = 0;
	int total_tat = 0;

	
	for (int i = 0; i < n; i++) {
		cout << "Process : " << i + 1 << "\t" << "Burst time: " << burst_t[i] << "\t";

		if (i == 0) 
			comp_t[i] = 0;
		else 
			comp_t[i] = comp_t[i - 1] + burst_t[i];
		cout << "completion time: " << comp_t[i]<< " ";

		tat[i] = comp_t[i] - arrival_t[i];
		cout << "TurnAround Time: " << tat[i] << " " ;

		if (i == 0)
			wt[i] = 0;
		else
			wt[i] = tat[i] = burst_t[i];
		cout << "Waiting Times: " << wt[i] << endl ;

		
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
	}
	
	for (int i = 0; i < noOfProcesses; i++) {
		cout << "Enter Burst Time of Process " << i + 1 << "   : ";
		cin >> burst_t[i];
		cout << "Enter arrival time of process: " << i + 1 << "    : ";
		cin >> arrival_t[i];
		cout << endl;
	}
	cout << endl << "\t\t\t\t-------FIRST COME FIRST SERVE AT DIFFERENT ARRIVAL TIME-------- \n\n\n";
	calculateTime(processes, noOfProcesses, arrival_t, burst_t);


}