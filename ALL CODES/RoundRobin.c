//#include <stdio.h>
//#define MAX_PROCESS 10
//int main() {
//    int n = 3;  // number of processes
//    int burst_time[MAX_PROCESS] = {24, 3, 3};  // burst time of each process
//    int quantum_time = 4;  // time quantum
//
//    int remaining_time[MAX_PROCESS];
//    for (int i = 0; i < n; i++) {
//        remaining_time[i] = burst_time[i];
//    }
//
//    int current_time = 0;
//    int waiting_time[MAX_PROCESS] = {0};
//    int turnaround_time[MAX_PROCESS] = {0};
//    int total_waiting_time = 0;
//    int total_turnaround_time = 0;
//
//    int flag = 0;  // to check if all processes have been executed
//    while (1) {
//        flag = 1;
//        for (int i = 0; i < n; i++) {
//            if (remaining_time[i] > 0) {
//                flag = 0;
//                if (remaining_time[i] > quantum_time) {
//                    current_time += quantum_time;
//                    remaining_time[i] -= quantum_time;
//                } else {
//                    current_time += remaining_time[i];
//                    waiting_time[i] = current_time - burst_time[i];
//                    remaining_time[i] = 0;
//                }
//            }
//        }
//        if (flag == 1) {
//            break;
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        turnaround_time[i] = burst_time[i] + waiting_time[i];
//        total_waiting_time += waiting_time[i];
//        total_turnaround_time += turnaround_time[i];
//    }
//
//    float avg_waiting_time = (float)total_waiting_time / n;
//    float avg_turnaround_time = (float)total_turnaround_time / n;
//
//    printf("Average Waiting Time: %f ms\n", avg_waiting_time);
//    printf("Average Turnaround Time: %f ms\n", avg_turnaround_time);
//
//    return 0;
//}


#include<stdio.h>
int main()
{
	int n=3;
	int burst_time[10]={24,3,3};
	int quantum=4;
	
	int remaining_time[n];
	for(int i=0;i<n;i++)
	remaining_time[i]=burst_time[i];
	
	int current_time=0;
	int waiting_time[10]={0};
	int turnaround_time[10]={0};
	int wt=0;
	int tat=0;
	int flag=0;
	while(1)
	{
		flag=1;
		for(int i=0;i<n;i++)
		{
			if(remaining_time[i]>0)
			{
				flag=0;
				if(remaining_time[i]>quantum)
				{
					current_time+=quantum;
					remaining_time[i]-=quantum;
				}
				else
				{
					current_time+=remaining_time[i];
					waiting_time[i]=current_time-burst_time[i];
					remaining_time[i]=0;
				}
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	
	
}