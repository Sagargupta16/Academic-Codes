#include<bits/stdc++.h>  
using namespace std;

float correlationCoefficient(float Xi[],float Yi[] , int n , int m)
{
    float XYi[n][m]={
        {1,2,3,0},
        {8,8,7,1},
        {9,10,7,8},
        {6,5,8,7},
        {0,1,4,5}
    };

    float FYi[m];
    for (int i = 0; i < m; i++)
    {
        FYi[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            FYi[j]+=XYi[i][j];
        }
    }
    cout<<"FYi is : ";
    for(int i=0;i<m;i++){
        cout<<FYi[i]<<" ";
    }
    cout<<endl;

    int N=0;
    float FXi[n];
    for (int i = 0; i < n; i++)
    {
        FXi[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            FXi[i]=FXi[i]+XYi[i][j];
        }
        N = N + FXi[i];
    }
    cout<<"FXi is : ";
    for(int i=0;i<n;i++){
        cout<<FXi[i]<<" ";
    }
    cout<<endl;
    cout<<"N = "<<N<<endl;




    float sum_X = 0, sum_Y = 0, sum_XY = 0;
    float squareSum_X = 0, squareSum_Y = 0;
  
    for (int i = 0; i < n; i++)
    {
        sum_X = sum_X + Xi[i]*FXi[i];
        squareSum_X = squareSum_X + FXi[i]*Xi[i]*Xi[i];
    }
    for (int i = 0; i < m; i++)
    {
        sum_Y = sum_Y + Yi[i]*FYi[i];
        squareSum_Y = squareSum_Y + FYi[i]*Yi[i] * Yi[i];
    }
    for (int i = 0; i < n; i++)
    {   
        for(int j=0 ;j<m;j++){
            sum_XY = sum_XY + Xi[i]*Yi[j]*XYi[i][j];
        }
    }
        
        
    
    cout<<"Sum X = "<<sum_X<<", E(x) = "<<sum_X/N<<endl;
    cout<<"Sum Y = "<<sum_Y<<", E(y) = "<<sum_Y/N<<endl;
    cout<<"Sum XY = "<<sum_XY<<", E(xy) = "<<sum_XY/N<<endl;


    float sigx=sqrt((squareSum_X/N)-((sum_X/N)*(sum_X/N) )),sigy=sqrt((squareSum_Y/N)-((sum_Y/N)*(sum_Y/N) ));
    cout<<"Square Sum X = "<<squareSum_X<<", s.d(x) = "<<sigx<<endl;
    cout<<"Square Sum Y = "<<squareSum_Y<<", s.d(y) = "<<sigy<<endl;

    float corr = (float)(N * sum_XY - sum_X * sum_Y) 
                  / sqrt((N * squareSum_X - sum_X * sum_X) 
                      * (N * squareSum_Y - sum_Y * sum_Y));
    
    cout<<"Correalation Coefficient is : "<<corr<<endl;
    cout<<"Regression line Y On X : y = "<< (sum_Y/N)-corr * (sigy/sigx) * (sum_X/N) <<" + "<<corr*(sigy/sigx)<<"x"<<endl;
    cout<<"Regression line X On Y : x = "<< (sum_X/N)-corr * (sigx/sigy) * (sum_Y/N)<<" + "<<corr*(sigx/sigy)<<"y"<<endl;
    return corr;
}
  

int main()
{
  
    float Xi[] = {2.5,7.5,12.5,17.5,22.5};
    float Yi[] = {5,15,25,35};
  

    int n = sizeof(Xi)/sizeof(Xi[0]);
    int m = sizeof(Yi)/sizeof(Yi[0]);
    cout<<"n = "<<n<<endl;
    cout<<"m = "<<m<<endl;

  
    float cor=correlationCoefficient(Xi, Yi, n , m);
  
    return 0;
}