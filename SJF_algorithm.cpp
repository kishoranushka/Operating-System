// SJF - Shortest Job First Implementation

#include <iostream>
using namespace std;
int main()
{
    cout << "SJF - Shortest Job First Implementation\n\n";
    int i, j, no_of_processes;
    cout << "enter the number of processes: ";
    cin >> no_of_processes;
    int process[no_of_processes];
    int B_Time[no_of_processes];
    int W_Time[no_of_processes];
    int T_A_Time[no_of_processes];
    int temp = 0;
    int completion_time[no_of_processes];
    int waiting_time = 0;
    int Avg_w_time = 0, Avg_TA_Time = 0;
    int sum = 0;
    for (i = 1; i <= no_of_processes; i++)
    {
        cout << "Enter the burst time of process P" << i << ": ";
        cin >> B_Time[i];
    }
    for (i = 1; i <= no_of_processes - 1; i++)
    {
        for (j = i; j <= no_of_processes; j++)
        {
            if (B_Time[i] > B_Time[j])
            {
                int temp = B_Time[i];
                B_Time[i] = B_Time[j];
                B_Time[j] = temp;
            }
        }
    }
    cout << "Burst Time in ascending order : ";
    for (i = 1; i <= no_of_processes; i++)
    {
        cout << B_Time[i] << " ";
    }
    cout << "\nProcess completion time: ";
    for (i = 1; i <= no_of_processes; i++)
    {
        temp = temp + B_Time[i];
        completion_time[i] = temp;
    }
    for (i = 1; i <= no_of_processes; i++)
    {
        cout << completion_time[i] << " ";
    }

    for (i = 1; i <= no_of_processes; i++)
    {
        waiting_time = completion_time[i] - B_Time[i];
        W_Time[i] = waiting_time;
    }
    cout << "\nWaiting time: ";
    for (i = 1; i <= no_of_processes; i++)
    {
        cout << W_Time[i] << " ";
    }
    cout << "\nTurn Around Time: ";
    for (i = 1; i <= no_of_processes; i++)
    {
        cout << completion_time[i] << " ";
    }

    cout << "\n Average Waiting Time:  ";
    for (i = 1; i <= no_of_processes; i++)
    {
        Avg_w_time = Avg_w_time + W_Time[i];
    }
    cout << (Avg_w_time / 4);

    cout << "\n Average Turn Around Time:  ";
    for (i = 1; i <= no_of_processes; i++)
    {
        Avg_TA_Time = Avg_TA_Time + completion_time[i];
    }
    cout << (Avg_TA_Time / 4);
    return 0;
}