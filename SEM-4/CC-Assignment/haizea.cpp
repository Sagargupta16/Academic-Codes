#include<bits/stdc++.h>
using namespace std;

void printTable(vector<vector<int>> &v){
    cout << "ID\tAT\tST\tD\tP\tN\tSlack\t" << endl;
    for(int i = 0; i < v.size(); i++){
        string s1="", s2="", s3="";
        if(v[i][1] / 60 < 10) s1 += "0";
        s1+= to_string(v[i][1] / 60) + ":" ;
        if(v[i][1] % 60 < 10) s1 += "0";
        s1 += to_string(v[i][1] % 60);
        if(v[i][2] / 60 < 10) s2 += "0";
        s2+= to_string(v[i][2] / 60) + ":" ;
        if(v[i][2] % 60 < 10) s2 += "0";
        s2 += to_string(v[i][2] % 60);
        if(v[i][3] / 60 < 10) s3 += "0";
        s3+= to_string(v[i][3] / 60) + ":" ;
        if(v[i][3] % 60 < 10) s3 += "0";
        s3 += to_string(v[i][3] % 60);
        double x = (v[i][3]-v[i][2])*1.0/v[i][4] ;
        cout << v[i][0] << "\t" << s1 << "\t" << s2 << "\t" << s3 << "\t" << v[i][4] << "\t" << v[i][5] << "\t"<< x << endl;
    }
}

void printFinalTable(vector<vector<int>>& Timeline,int initialTime,int finalTime){
    cout << "Time from \t";
    int x = initialTime;
    while(x< finalTime){
        string s = "";
        if(x / 60 < 10) s += "0";
        s+= to_string(x / 60) + ":" ;
        if(x % 60 < 10) s += "0";
        s += to_string(x % 60);
        cout << s << "\t";
        x += 20;
    }
    cout << endl;
    cout<<"Time to\t\t";
    x = initialTime+10;
    while(x<= finalTime){
        string s = "";
        if(x / 60 < 10) s += "0";
        s+= to_string(x / 60) + ":" ;
        if(x % 60 < 10) s += "0";
        s += to_string(x % 60);
        cout << s << "\t";
        x += 20;
    }
    cout << endl;

    for(int i=0;i<Timeline.size();i++){
        cout << "N" << i+1 << "\t\t";
        for(int j=0;j<Timeline[i].size();j++){
            cout <<"  "<< Timeline[i][j] << "\t";
        }
        cout << endl;
    }

}
bool checkAvailable(vector<vector<int>>& Timeline, int i, int j, int n,int m){
    for(int k=i;k<i+n;k++){
        for(int l=j;l<j+m;l++){
            if(Timeline[k][l] != 0) return false;
        }
    }
    return true;
}

void insertInTimeline(vector<vector<int>>& Timeline, int initial, int final, int period, int id,int node){
    for(int i=0;i<4-node;i++){
        for(int j=initial/10;j<(final-period)/20;j++){
            
            if(checkAvailable(Timeline, i, j, node, period/10)){
                for(int k=i;k<i+node;k++){
                    for(int l=j;l<j+period/10;l++){
                        Timeline[k][l] = id;
                    }
                }
                return;
            }
        }
    }

}

int main()
{
    vector<vector<int>> v = {
        {1,0,10,1*60+40,40,3},
        {2,0,10,1*60+40,50,4},
        {3,0,40,2*60,10,1},
        {4,0,2*60,2*60+50,30,3},
        {5,0,2*60+30,4*60+10,30,3},
        {6,0,2*60+30,4*60+40,50,4},
        {7,0,50,1*60+50,30,1},
        {8,1,1*60,2*60,20,4},
        {9,1,10,2*60+30,30,1},
        {10,1,1*60+40,2*60+50,40,3},
        {11,1,10,4*60+20,80,1},
        {12,1,2*60+30,3*60+20,10,2},
        {13,2,3*60+20,5*60,30,1}
    };

    int initialTime = INT_MAX;
    int finalTime = 0;
    for(int i=0 ; i<v.size() ; i++){
        initialTime = min(initialTime, v[i][2]);
        finalTime = max(finalTime, v[i][3]);
    }

    int totalTime = finalTime - initialTime;

    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b){
        if(a[1] == b[1]) return a[5]>b[5];
        return a[1] < b[1];
    });

    int N = 4;
    int n = v.size();
    cout << "Initial Table" << endl;
    printTable(v);
    cout << endl;

    vector<vector<int>> Timeline(N, vector<int>(totalTime/20, 0));

    for(int i=0;i<n;i++){
        int initial = v[i][2]-initialTime;
        int final = v[i][3]-initialTime;
        int period = v[i][4];
        int node = v[i][5];
        int id = v[i][0];
        insertInTimeline(Timeline, initial, final, period, id, node);
    }

    cout << "Final Table" << endl;

    printFinalTable(Timeline, initialTime, finalTime);


    int AcceptedLeases = 0;
    unordered_map<int, int> m;
    for(int i=0;i<N;i++){
        for(int j=0;j<totalTime/20;j++){
            if(Timeline[i][j] != 0){
                m[Timeline[i][j]]++;
            }
        }
    }
    AcceptedLeases = m.size();

    cout << "Accepted Leases: " << AcceptedLeases << endl;
    cout << "Rejected Leases: " << n - AcceptedLeases << endl;

    return 0;
}