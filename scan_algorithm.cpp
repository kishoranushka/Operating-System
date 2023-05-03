// SCAN Algorithm implementation

#include <iostream>
using namespace std;
int main()
{
    int disk_size, seek_time = 0;
    int temp = 0;
    int head, num;
    int direction;

    cout << "enter disk size: ";
    cin >> disk_size;
    cout << "enter head position: ";
    cin >> head;
    cout << "enter the number of request to be served: ";
    cin >> num;
    int scan[num + 2], i, j;
    scan[0] = 0;
    // scan[1] = head;
    scan[num + 1] = 199;
    cout << "enter the requests to be served: ";
    for (i = 1; i < num + 1; i++)
    {
    repeat:
        cin >> scan[i];
        if (scan[i] < 0 || scan[i] > disk_size || scan[i] == head)
        {
            cout << "Invalid number inserted. choose another number between 0 and " << disk_size << "\n";
            goto repeat;
        }
    }
    cout << "***Before Sorting***\n";
    {
        for (i = 0; i < num + 2; i++)
        {
            cout << scan[i] << " ";
        }
    }
    cout << "\n";
    cout << "***After Sorting***\n";
    {
        for (i = 0; i < num + 2; i++)
        {
            for (j = i; j < num + 2; j++)
            {
                if (scan[j] < scan[i])
                {
                    int temp = scan[j];
                    scan[j] = scan[i];
                    scan[i] = temp;
                }
            }
        }

        for (i = 0; i < num + 2; i++)
        {
            cout << scan[i] << " ";
        }
    }

    for (i = 0; i < num + 2; i++)
    {
        if (scan[i] < head && scan[i + 1] > head)
        {
            break;
        }
        else
        {
            temp++;
        }
    }
    cout << "\nThe header lies between: " << scan[temp] << " and " << scan[temp + 1] << "\n";
    {
        if ((head - scan[temp]) < (scan[temp + 1] - head))
        {
            cout << "left direction: \n";
            direction = 0;
        }
        else
        {
            cout << "Right direction: \n";
            direction = 1;
        }
    }

    if (direction == 0)
    {
        seek_time = (head - scan[0]) + (scan[num] - scan[0]);
    }
    else
    {
        seek_time = (scan[num + 1] - head) + (scan[num + 1] - scan[1]);
    }

    cout << "Total seek time is: " << seek_time;

    return 0;
}