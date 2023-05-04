#include <iostream>
using namespace std;

void func1(){
    cout<<"Func1 Called"<<endl;
}

void func2(){
    cout<<"Func2 Called before Return"<<endl;
    return;
    cout<<"Func2 Called after Return"<<endl;
}

double func3(){
    return 10.24;
}

int func4(int a,int b){
    return a+b;
}

int func5(int a,int b){
    if(a+b>0) return 1;
    else if(a+b<0) return -1;
    else return 0;
}

void func6(int a){
    a=a+5;
}

void func7(int &a){
    a=a+5;
}

void func8(int *a){
    *a=*a+5;
}

void func9_1(){
    cout<<"Func9-1 Called!"<<endl;
}
void func9_2(){
    cout<<"Func9-2 Called!"<<endl;
    func9_1();
}
void fun9_3(){
    cout<<"Func9-3 Called!"<<endl;
    func9_2();
}

void func10(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void func11(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]+b[i]<<" ";
    }
    cout<<endl;
}

void func12(int n){
    if(n==0) return;
    cout<<n<<" ";
    func12(n-1);
}

void func13(int n){
    cout<<n<<" ";
}

void func14(bool a){
    if(a) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}

int main(){

    // 1.
    cout<<endl<<"1. Function without return type and without arguments."<<endl;
    func1();

    // 2.
    cout<<endl<<"2. Function without return type and without arguments with return."<<endl;
    func2();

    // 3.
    cout<<endl<<"3. Function with return type and without arguments."<<endl;
    cout<<"Func3 Returned : "<<func3()<<endl;

    // 4.
    cout<<endl<<"4. Function With Return Type and Multiple Parameters or arguments."<<endl;
    cout<<"Func4 Returned : "<<func4(10,-20)<<endl;

    // 5.
    cout<<endl<<"5. Function With Return Type ,Multiple Parameters or arguments and Multiple return State."<<endl;
    cout<<"Func5 Returned : "<<func5(10,-20)<<endl;

    // 6.
    int a=10;
    cout<<endl<<"6. Function With Call By Value."<<endl;
    cout<<"Before Calling Func6 a : "<<a<<endl;
    func6(a);
    cout<<"After Calling Func6 a : "<<a<<endl;

    // 7.
    cout<<endl<<"7. Function With Call By Reference."<<endl;
    cout<<"Before Calling Func7 a : "<<a<<endl;
    func7(a);
    cout<<"After Calling Func7 a : "<<a<<endl;

    // 8.
    cout<<endl<<"8. Function With Call By Address or pointer."<<endl;
    cout<<"Before Calling Func8 a : "<<a<<endl;
    func8(&a);
    cout<<"After Calling Func8 a : "<<a<<endl;

    // 9.
    cout<<endl<<"9. Calling Nested Function."<<endl;
    cout<<"Only Called Func9-3"<<endl;
    fun9_3();

    // 10.
    int b[5]={1,2,3,4,5};
    int n = sizeof(b)/sizeof(b[0]);
    cout<<endl<<"10. Function With Array as Argument."<<endl;
    func10(b,n);

    // 11.
    int c[5]={1,2,3,4,5};
    cout<<endl<<"11. Function With Multiple Array as Argument."<<endl;
    func11(b,c,n);

    // 12.
    cout<<endl<<"12. Function With Recursion."<<endl;
    func12(5);
    cout<<endl;

    // 13.
    cout<<endl<<"13. Function Inside Loop."<<endl;
    for(int i=0;i<5;i++){
        func13(i+1);
    }
    cout<<endl;

    // 14.
    cout<<endl<<"14. Function with condition as argument."<<endl;
    func14(1>2);

    // 15. Dynamic Memory Allocation to Array
    int *x;
    x=new int[5];
    cout<<sizeof(x)/sizeof(x[0])<<endl;

    return 0;
}
