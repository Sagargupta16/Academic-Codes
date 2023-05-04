#include<bits/stdc++.h>
using namespace std;

void Display(int n,vector<int>& arrival,vector<int>& burst,vector<int>& completion,vector<int>& turnaround,vector<int>& waiting,vector<int>& process){

    cout<<" Gantt Chart: "<<endl;
    cout<<endl<<"  0";
    for(int i=0;i<n;i++){
    	if((i==0 || arrival[i]>completion[i-1])&&arrival[i]!=0) cout<<"  Idle  "<<arrival[i];
        cout<<"  P"<<process[i]<<"  "<<completion[i];
    }
    cout<<endl<<endl;

    cout<<"Process\t  Arrival\tBurst\t\texit\t\tTurnaround\tWaiting"<<endl;
    for(int i=0;i<n;i++){
        cout<<"P"<<process[i]<<"\t:    "<<arrival[i]<<"\t\t  "<<burst[i]<<"\t\t "<<completion[i]<<"\t\t"<<turnaround[i]<<"\t\t   "<<waiting[i]<<endl;
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

void FCFS(int n,vector<int>& arrival,vector<int>& burst,vector<int>& completion,vector<int>& turnaround,vector<int>& waiting,vector<int>& process){
    sortt1(n,arrival,burst,process);
    completion[0]=arrival[0]+burst[0];
    for(int i=1;i<n;i++){
        completion[i]=completion[i-1]+burst[i];
        if(completion[i]<arrival[i]+burst[i]) completion[i]=arrival[i]+burst[i];
    }
    for(int i=0;i<n;i++){
        turnaround[i]=completion[i]-arrival[i];
    }
    for(int i=0;i<n;i++){
        waiting[i]=turnaround[i]-burst[i];
    }
}

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<int> arrival(n,0),burst(n,0),completion(n,0),turnaround(n,0),waiting(n,0),process(n,0);
    cout<<"Enter the arrival time of processes: ";
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        process[i]=i+1;
    }
    cout<<"Enter the burst time of processes: ";
    for(int i=0;i<n;i++){
        cin>>burst[i];
    }
    cout<<endl;
    FCFS(n,arrival,burst,completion,turnaround,waiting,process);
    Display(n,arrival,burst,completion,turnaround,waiting,process);
    return 0;
}
