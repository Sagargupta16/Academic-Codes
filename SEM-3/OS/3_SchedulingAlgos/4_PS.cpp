#include<bits/stdc++.h>
using namespace std;

void display(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process,vector<int>& exitTime,vector<int>& turnaround,vector<int>& waiting,vector<vector<int>>& gantt){
    cout<<endl;
    cout<<"    Gantt Chart: "<<endl;
    cout<<endl<<"  0  ";
    for(int i=0;i<gantt.size();i++){
        cout<<"P"<<gantt[i][0]<<"  "<<gantt[i][1]<<"  ";
        if(gantt[i][1]<=arrival[gantt[i][0]]){
            cout<<"P0  "<<arrival[gantt[i][0]]<<"  ";
        }
    }
    
    cout<<endl<<endl<<endl;

    cout << "Process\t  Arrival\tBurst\t\texit\t\tTurnaround\tWaiting" << endl;
    for(int i=0;i<n;i++){
        cout<<"P"<<process[i]<<"\t:    "<<arrival[i]<<"\t\t  "<<burst[i]<<"\t\t "<<exitTime[i]<<"\t\t     "<<turnaround[i]<<"\t\t   "<<waiting[i]<<endl;
    }
    cout<<endl<<endl;

    float avg_turnaround=0,avg_waiting=0;
    for(int i=0;i<n;i++){
        avg_turnaround+=turnaround[i];
        avg_waiting+=waiting[i];
    }
    cout<<"Average Turnaround Time: "<<avg_turnaround/n<<endl;
    cout<<"Average Waiting    Time: "<<avg_waiting/n<<endl;
    
}

void sortt1(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process,vector<int>& priority){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arrival[i]>arrival[j]){
                swap(arrival[i],arrival[j]);
                swap(burst[i],burst[j]);
                swap(process[i],process[j]);
                swap(priority[i],priority[j]);
            }
        }
    }
}

void PS(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process,vector<int>& exitTime,vector<int>& priority,vector<vector<int>>& gantt){
    if(arrival[0]!=0){
        gantt.push_back({0,arrival[0]});
    }
    int i=0,currTime=arrival[0];
    while(i<n){
        int z = i;
        while(z<n && arrival[z]<=currTime){
            if(priority[z]>priority[i]){
                swap(arrival[z],arrival[i]);
                swap(burst[z],burst[i]);
                swap(process[z],process[i]);
                swap(priority[z],priority[i]);
            }
            z++;
        }
        currTime+=burst[i];
        gantt.push_back({process[i],currTime});
        if(currTime<arrival[i+1]){
            currTime=arrival[i+1];
        }
        exitTime[i]=currTime;
        i++;
    }
}

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<int> arrival(n),burst(n),exitTime(n),turnaround(n),waiting(n),process(n),priority(n);
    cout<<"Enter the arrival time of processes: ";
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        process[i]=i+1;
    }
    cout<<"Enter the burst time of processes: ";
    for(int i=0;i<n;i++){
        cin>>burst[i];
    }
    cout<<"Enter the priority of processes: ";
    for(int i=0;i<n;i++){
        cin>>priority[i];
    }

    vector<vector<int>> gantt;
    sortt1(n,arrival,burst,process,priority);
    PS(n,arrival,burst,process,exitTime,priority,gantt);

    for(int i=0;i<n;i++){
        turnaround[i]=exitTime[i]-arrival[i];
    }
    for(int i=0;i<n;i++){
        waiting[i]=turnaround[i]-burst[i];
    }
    display(n,arrival,burst,process,exitTime,turnaround,waiting,gantt);
    
}