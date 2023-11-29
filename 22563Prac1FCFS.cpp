#include<iostream>
using namespace std;

//function to find waiting time
void findWaitingTime(int processes[],int n,int bt[], int wt[])	

// bt = Burst time , wt = waiting time

{
	wt[0] = 0;
	//calculating waiting time
	for(int i = 1; i<n; i++)
		wt[i] = bt[i-1]+wt[i-1];
}
//function for turnaround time
void findTurnAroundTime (int processes[],int n,int bt[],int wt[],int tat[])
{
	//calculating turnaround time by adding
	for(int i = 0;i<n;i++)
		tat[i] = bt[i] + wt[i];
}
//function for average time
void findavgTime( int processes[], int n, int bt[])
{
	int wt[n],tat[n],total_wt = 0,total_tat = 0;
	//function to find waiting time for all processes
	findWaitingTime(processes,n,bt,wt);
	findTurnAroundTime(processes,n,bt,wt,tat);
	//display
	cout<<"processes"<<"Burst_time "<<"Waiting_time "<<"Turn_around_time \n";
	
	//calculate total waiting time and total turn around time
	
	for (int i = 0;i<n;i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout<<""<<i+1<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"average waiting time = "<<(float)total_wt / (float)n;
	cout<<"\nAverage turn around time = "<<(float)total_tat / (float)n;
}

int main()

{
	//process id's
	int processes[] = {1,2,3};
	int n = sizeof(processes) / sizeof(processes[0]);
	//Burst time of all proceses
	int burst_time[] = {10,5,8};
	findavgTime(processes,n,burst_time);
	return 0;
}


