// FCFS algorithm implementation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int disk_max, header;
    int no_of_requests;
    int seek_time = 0;
    int i;

    cout << "enter the maximum size of the disk: ";
    cin >> disk_max;
    cout << "enter the number of requests to be served: ";
    cin >> no_of_requests;
header:
    cout << "enter the header postion: ";
    cin >> header;
    if (header >= disk_max)
    {
        cout << "invalid header\nenter the header less than disk size.\n";
        goto header;
    }

    int ary[no_of_requests];
    for (i = 0; i < no_of_requests; i++)
    {
    loop:
        cout << "enter the request : ";
        cin >> ary[i];
        if (ary[i] >= disk_max)
        {
            cout << "Enter the request less than disk size.\n";
            goto loop;
        }
        else
        {
            seek_time = seek_time + abs(header - ary[i]);
        }
    }
    cout << "total seek_time is: " << seek_time;
}