// Q-3 Data Normalization 

#include <bits/stdc++.h>
using namespace std;
void printValues(vector<double> a){
int n=a.size();
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
}
int main(){
vector<double> a = {20,18,29,88,76,59,39,100,35,89,69,40,70};
cout<<"Data Provided : ";
printValues(a);
int n=a.size();
double maxi=a[0],mini=a[0];
for(int i=0;i<n;i++){
maxi=max(maxi,a[i]);
mini=min(mini,a[i]);
}
double new_mini,new_maxi;
cout<<"Enter new min : ";
cin>>new_mini;
cout<<"Enter new max : ";
cin>>new_maxi;
vector<double> b(n,0);
for(int i=0;i<n;i++)
b[i]=(a[i]-mini)*(new_maxi-new_mini)/double(maxi-mini);
cout<<"Data in new Range : ";
printValues(b);
}


//Z-SCORE///////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
void printValues(vector<double> a){
int n=a.size();
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
}
double calculate_sd(vector<double> data) {
double sum = 0.0, mean, standardDeviation = 0.0;
for(int i = 0; i < 10; i++)
sum += data[i];
mean = sum / 10;
for(int i = 0; i < 10; i++)
standardDeviation += pow(data[i] - mean, 2);
return sqrt(standardDeviation / 10);
}
int main(){
vector<double> a = {20,18,29,88,76,59,39,100,35,89,69,40,70};
double sum=0;
int n=a.size();
for(int i=0;i<n;i++)
sum+=a[i];
double mean = sum/n, sd;
sd = calculate_sd(a);
vector<double> b(n,0);
for(int i=0;i<n;i++)
b[i] = (a[i]-mean)/sd;
cout<<"Data Provided : ";
printValues(a);
cout<<"Data after performing Z-score : ";
printValues(b);}
