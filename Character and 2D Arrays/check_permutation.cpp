#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char str1[], char str2[])
{
	int freq[256] = {0}; // frequency array to store frequency of letters. intially every element is 0.
	for (int i = 0; i < strlen(str1); i++)
	{
		freq[int(str1[i])] += 1;
	}
	for (int j = 0; j < strlen(str2); j++)
	{
		freq[int(str2[j])] -= 1;
	}
	for (int k = 0; k < 256; k++)
	{
		if (freq[k] != 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int size = 1e6;
	char str1[size];
	char str2[size];
	cin >> str1 >> str2;
	cout << (isPermutation(str1, str2) ? "true" : "false");
}

#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
					 int bt[], int wt[])
{
	wt[0] = 0;

	for (int i = 1; i < n; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], twt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt);

	findTurnAroundTime(processes, n, bt, wt, tat);

	cout << "Processes "
		 << " Burst time "
		 << " Waiting time "
		 << " Turn around time\n";

	for (int i = 0; i < n; i++)
	{
		twt = twt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
			 << wt[i] << "\t\t " << tat[i] << endl;
	}

	cout << "Average waiting time = "
		 << (float)twt / (float)n;
	cout << "\nAverage turn around time = "
		 << (float)total_tat / (float)n;
}

// Driver code
int main()
{
	// process id's
	int processes[] = {1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	// Burst time of all processes
	int burst_time[] = {10, 5, 8};

	findavgTime(processes, n, burst_time);
	return 0;
}
