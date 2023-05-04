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

void sortt2(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process,vector<int>& exitTime,vector<int>& turnaround,vector<int>& waiting){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arrival[i]>arrival[j]){
                swap(arrival[i],arrival[j]);
                swap(burst[i],burst[j]);
                swap(process[i],process[j]);
                swap(exitTime[i],exitTime[j]);
                swap(turnaround[i],turnaround[j]);
                swap(waiting[i],waiting[j]);
            }
        }
    }
}

int minn(int n,vector<int>& burst,vector<int>& process,int l,int r){
    int mn=burst[l],k=l;
    for(int j=l+1;j<=r;j++){
        if(burst[j]<mn){
            mn=burst[j];
            k=j;
        }
        else if(burst[j]==mn){
            if(process[j]<process[k]){
                mn=burst[j];
                k=j;
            }
        }
    }
    return k;
}


void SRTF(int n,vector<int>& arrival,vector<int>& burst,vector<int>& process){
    for(int i=0;i<n;i++){
        process[i]=i+1;
    }
    sortt1(n,arrival,burst,process);
    int l=0,r=burst[0];
    for(int i=1;i<n-1;i++){
        int j=i;
        while(arrival[j]<=r){
            j++;
            if(j==n-1) break;
        }
        int k = minn(n,burst,process,i,j);
        swap(arrival[i],arrival[k]);
        swap(burst[i],burst[k]);
        swap(process[i],process[k]);
        r++;
    }
}

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
int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<int> arrival(n),burst(n),exitTime(n),turnaround(n),waiting(n),process(n);
    cout<<"Enter the arrival time of processes: ";
    for(int i=0;i<n;i++){
        cin>>arrival[i];
    }
    cout<<"Enter the burst time of processes: ";
    for(int i=0;i<n;i++){
        cin>>burst[i];
    }
    cout<<endl;
    SRTF(n,arrival,burst,process);

    exitTime[0]=arrival[0]+burst[0];
    for(int i=1;i<n;i++){
        exitTime[i]=exitTime[i-1]+burst[i];
        if(exitTime[i]<arrival[i]+burst[i]) exitTime[i]=arrival[i]+burst[i];
    }
    for(int i=0;i<n;i++){
        turnaround[i]=exitTime[i]-arrival[i];
    }
    for(int i=0;i<n;i++){
        waiting[i]=turnaround[i]-burst[i];
    }
    Display(n,arrival,burst,exitTime,turnaround,waiting,process);
}