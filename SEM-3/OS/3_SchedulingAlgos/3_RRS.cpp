#include<bits/stdc++.h>
using namespace std;

void sortt1(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arrival[i]>arrival[j]){
                swap(arrival[i],arrival[j]);
                swap(burst[i],burst[j]);
                swap(process[i],process[j]);
            }
        }
    }
}

void display(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process,vector<int>& exitTime,vector<int>& turnaround,vector<int>& waiting,vector<vector<int>>& gantt){
    cout<<endl;
    cout<<"    Gantt Chart: "<<endl;
    cout<<endl<<"   0\t";
    for(int i=0;i<gantt.size();i++){
        cout<<"P"<<gantt[i][0]<<"  "<<gantt[i][1]<<"\t";
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

void RRS(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process,vector<int>& exitTime,vector<vector<int>>& gantt,int quantum){
    queue<int> q;
    if(arrival[0]!=0) gantt.push_back({0,arrival[0]});
    int time=arrival[0];
    q.push(0);
    int i=1;
    vector<int> burstCopy=burst;
    int smBurst=burst[0];
    for(int i=1;i<n;i++){
        smBurst=smBurst+burst[i];
    }
    int a = arrival[n-1]+burst[n-1];
    a=max(a,smBurst);
    while(time<=a){
        if(q.empty()){
            if(gantt[gantt.size()-1][1]!=time){
                gantt.push_back({0, time});
            }
            
            time++;
        }
        else{
            int p=q.front();
            q.pop();
            if(burstCopy[p]<=quantum){
                time+=burstCopy[p];
                burstCopy[p]=0;
                exitTime[p]=time;
                gantt.push_back({process[p],time});
            }
            else{
                time+=quantum;
                burstCopy[p]-=quantum;
                gantt.push_back({process[p],time});
            }
            if(burstCopy[p]>0) q.push(p);
        }
        while(i<n && arrival[i]<=time){
            q.push(i);
            i++;
        }
        
    }
}

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<int> arrival(n),burst(n),exitTime(n),turnaround(n),waiting(n),process(n);
    cout<<"Enter the arrival time of processes: ";
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        process[i]=i+1;
    }
    cout<<"Enter the burst time of processes: ";
    for(int i=0;i<n;i++){
        cin>>burst[i];
    }
    int quantum;
    cout<<"Enter the quantum: ";
    cin>>quantum;

    vector<vector<int>> gantt;
    sortt1(n,arrival,burst,process);
    RRS(n,arrival,burst,process,exitTime,gantt,quantum);

    for(int i=0;i<n;i++){
        turnaround[i]=exitTime[i]-arrival[i];
    }
    for(int i=0;i<n;i++){
        waiting[i]=turnaround[i]-burst[i];
    }
    display(n,arrival,burst,process,exitTime,turnaround,waiting,gantt);
    
}