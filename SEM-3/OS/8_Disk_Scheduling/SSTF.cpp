#include <bits/stdc++.h>
using namespace std;
void calculatedifference(int request[], int head,int diff[][2], int n){
    for (int i = 0; i < n; i++){
        diff[i][0] = abs(head - request[i]);
    }
}
int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(int request[],
                           int head, int n)
{
    if (n == 0)
    {
        return;
    }

    // Create array of objects of class node
    int diff[n][2] = {{0, 0}};

    // Count total number of seek operation
    int seekcount = 0;

    // Stores sequence in which disk access is done
    int seeksequence[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        // Increase the total count
        seekcount += diff[index][0];

        // Accessed track is now new head
        head = request[index];
    }
    seeksequence[n] = head;

    cout << "Total number of seek operations = "
         << seekcount << endl;
    cout << "Seek sequence is : "
         << "\n";

    // Print the sequence
    for (int i = 0; i <= n; i++)
    {
        cout << seeksequence[i] << "\n";
    }
}

// Driver code
int main()
{
    int n = 8;
    int proc[n] = {176, 79, 34, 60, 92, 11, 41, 114};

    shortestSeekTimeFirst(proc, 50, n);

    return 0;
}

// This code is contributed by manish19je0495
