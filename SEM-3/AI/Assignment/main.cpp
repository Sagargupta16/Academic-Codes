// #include "time.h"
#include<bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#include "Common.h"
#include "AStar.h"
#include "BFS.h"
#include "DFS.h"
#include "DLS.h"
#include "IDS.h"
#include "greedy.h"

int main(){
    do{
        cout<<endl<<"AI Assignment 1"<<endl;
        cout<<"1. A* Search "<<endl;
        cout<<"2. BFS Search "<<endl;
        cout<<"3. DFS Search "<<endl;
        cout<<"4. DLS Search "<<endl;
        cout<<"5. IDS Search "<<endl;
        cout<<"6. Greedy Search "<<endl;
        cout<<"7. Exit "<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        int x=5,sum=0,avg=0;
        switch(choice){
            case 1:
                while(x--){
                    Sleep(500);
                    sum+=Astar();
                }
                break;
            case 2:
                while(x--){
                    Sleep(500);
                    sum+=breadthFirstSearch();
                }
                break;
            case 3:
                while(x--){
                    Sleep(500);
                    sum+=DepthFirstSearch();
                }
                break;
            case 4:
                while(x--){
                    Sleep(500);
                    sum+=DepthLimitedSearch();
                }
                break;
            case 5:
                while(x--){
                    Sleep(500);
                    sum+=IterativeDeepeningSearch();
                }
                break;
            case 6:
                while(x--){
                    Sleep(500);
                    sum+=Greedy();
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                break;
        }
        cout<<"Average: "<<sum/5<<endl;
    }while(1);
}