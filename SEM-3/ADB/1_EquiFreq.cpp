#include<iostream>
using namespace std;

void printHistogram(int arr[], int n){
    int maxEle = arr[0];
    cout<<endl;
    for(int i=1; i<n; i++){
        if(arr[i] > maxEle) maxEle = arr[i];
    }
    for (int i = maxEle; i >= 0; i--) {
        cout.width(2);
        cout << right << i << " | ";
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i) cout << " x ";
            else cout << "   ";
        }
        cout << endl;
    }
    for (int i = 0; i < n + 3; i++){
        cout << "---";
    }
 
    cout << "\n";
    cout << "     ";
 
    for (int i = 0; i < n; i++) {
        cout.width(2);
        cout << right << arr[i] << " ";
    }
}

int main(){
    cout<<"Enter the number of Frequency: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the Frequencies: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl<<"Histogram before: "<<endl;
    printHistogram(arr, n);
    cout<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int avg=sum/n;
    for(int i=0;i<n;i++){
        if(arr[i]>avg){
            arr[i+1]+=(arr[i]-avg);
        }
        else if(arr[i]<avg){
            arr[i+1]-=(avg-arr[i]);
        }
        arr[i]=avg;
    }
    cout<<endl<<"Histogram after: "<<endl;
    printHistogram(arr, n);
    return 0;
}