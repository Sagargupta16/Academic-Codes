#include<bits/stdc++.h>
  
using namespace std;
  
float correlationCoefficient(float X[], float Y[], int n)
{
  
    float sum_X = 0, sum_Y = 0, sum_XY = 0;
    float squareSum_X = 0, squareSum_Y = 0;
  
    for (int i = 0; i < n; i++)
    {
        sum_X = sum_X + X[i];
  
        sum_Y = sum_Y + Y[i];
  
        sum_XY = sum_XY + X[i] * Y[i];
  
        squareSum_X = squareSum_X + X[i] * X[i];
        squareSum_Y = squareSum_Y + Y[i] * Y[i];
    }
    
    cout<<"Sum X = "<<sum_X<<", E(x) = "<<sum_X/n<<endl;
    cout<<"Sum Y = "<<sum_Y<<", E(y) = "<<sum_Y/n<<endl;
    cout<<"Sum XY = "<<sum_XY<<", E(xy) = "<<sum_XY/n<<endl;
    float sigx=sqrt((squareSum_X/n)-((sum_X/n)*(sum_X/n) )),sigy=sqrt((squareSum_Y/n)-((sum_Y/n)*(sum_Y/n) ));
    cout<<"Square Sum X = "<<squareSum_X<<", s.d(x) = "<<sigx<<endl;
    cout<<"Square Sum Y = "<<squareSum_Y<<", s.d(y) = "<<sigy<<endl;

    float corr = (float)(n * sum_XY - sum_X * sum_Y) 
                  / sqrt((n * squareSum_X - sum_X * sum_X) 
                      * (n * squareSum_Y - sum_Y * sum_Y));

    cout<<"Correalation Coefficient is : "<<corr<<endl;
    cout<<"Regression line Y On X : y = "<< (sum_Y/n)-corr * (sigy/sigx) * (sum_X/n) <<" + "<<corr*(sigy/sigx)<<"x"<<endl;
    cout<<"Regression line X On Y : x = "<< (sum_X/n)-corr * (sigx/sigy) * (sum_Y/n)<<" + "<<corr*(sigx/sigy)<<"y"<<endl;
  
    return corr;
}
  

int main()
{
  
    float X[] = {36,64,18,40,35,30,41,32};
    float Y[] = {60,71,72,83,110,84,100,92,113,135};

    int n = sizeof(X)/sizeof(X[0]);
    
    cout<<"n = "<<n<<endl;
    float cor=correlationCoefficient(X, Y, n);
    return 0;
}