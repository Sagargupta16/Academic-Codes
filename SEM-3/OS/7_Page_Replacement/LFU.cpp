#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=3,m=20,i,j,k,hit=0;
    int p[]={0,1,20,2,20,21,32,31,0,60,0,0,16,1,17,18,32,31,0,61} ;
    vector<int> hi(m);
    vector<vector<int>> a(n);
    for(i=0;i<n;i++){
        a[i]=vector<int>(m,-1);
    }
    map <int, int> mp;    
    for(i=0;i<m;i++){
        vector<pair<int,int>> c;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<n;j++){
            if(a[j][i]==p[i]){
                hit++;
                hi[i]=1;
                mp[p[i]]=1;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<m;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==n||hasrun==false){
            for(j=0;j<n;j++){
                if(a[j][i]==c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    for(k=i;k<m;k++)
                        a[j][k]=p[i];
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    cout<<"Process ";
    for(i=0;i<m;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
    for(i=0;i<n;i++){
        cout<<"Frame "<<i<<" ";
        for(j=0;j<m;j++){
            if(a[i][j]==-1)
                cout<<"  ";
                else 
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(i=0;i<m;i++){
        if(hi[i]==0)
        cout<<"  ";
        else
        cout<<hi[i]<<" ";
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<m-hit<<'\n';
    return 0;
}