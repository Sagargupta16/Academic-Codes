#include<bits/stdc++.h>
#include<dirent.h>
#include<unistd.h>

using namespace std;

void lsCommand(string path){
    DIR *dir = opendir(path.c_str());
    struct dirent *ent;
    if (dir) {
       while ((ent = readdir(dir)) != NULL) {
          cout<<" "<<endl<<ent->d_name; 
       }
       cout<<endl;
    }
    else cout<<"directory not found"<<endl;
    closedir(dir);
}

void cpCommand(string path1,string path2){
    ifstream file1(path1);
    ofstream file2(path2);
    string line;
    while(getline(file1,line)){
        file2<<line<<endl;
    }
    file1.close();
    file2.close();
}

void cdCommand(string path){
    if(chdir(path.c_str())!=0){
        perror("");
    }
}

void mkdirCommand(string path){
    if(mkdir(path.c_str())!=0){
        perror("");
    }
}

void rmdirCommand(string path){
    if(rmdir(path.c_str())!=0){
        perror("");
    }
}

void psCommand(){
    DIR *dir = opendir("../");
    struct dirent *ent;
    if (dir) {
       while ((ent = readdir(dir)) != NULL) {
          if(isdigit(ent->d_name[0])){
              cout<<" "<<endl<<ent->d_name; 
          }
       }
       cout<<endl;
    }
   else cout<<"directory not found"<<endl;
   closedir(dir);
}

void killCommand(string pid){
    int pid1=stoi(pid);
    // if(kill(pid1,SIGKILL)!=0){
    //     perror("");
    // }
}

void rmCommand(string path){
    if(remove(path.c_str())!=0){
        perror("");
    }
}

void touchCommand(string path){
    ofstream file(path);
    file.close();
}

void catCommand(string path){
    ifstream file(path);
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
}


void mvCommand(string path1,string path2){
    string x = path1.substr(path1.find_last_of("/")+1);
    touchCommand(path2+"/"+x);
    cpCommand(path1,path2+"/"+x);
    rmCommand(path1);
}

void viCommand(string path){
    open(path.c_str(),1);
}

void headCommand(string path){
    ifstream file(path);
    string line;
    int i=0;
    while(getline(file,line)){
        if(i==10)break;
        cout<<line<<endl;
        i++;
    }
    file.close();
}

void tailCommand(string path){
    ifstream file(path);
    string line;
    vector<string> v;
    while(getline(file,line)){
        v.push_back(line);
    }
    file.close();
    int i=v.size()-10;
    if(i<0)i=0;
    for(;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}

void wcCommand(string path){
    ifstream file(path);
    string line;
    int lines=0,words=0,chars=0;
    while(getline(file,line)){
        lines++;
        words+=count(line.begin(),line.end(),' ')+1;
        chars+=line.length();
    }
    cout<<"Lines: "<<lines<<endl;
    cout<<"Words: "<<words<<endl;
    cout<<"Chars: "<<chars<<endl;
    file.close();
}

void pwdCommand(){
    char cwd[1024];
    if(getcwd(cwd,sizeof(cwd))!=NULL) fprintf(stdout, "Current working dir: %s \n", cwd);
    else perror("getcwd() error");
}

int main(){
    int n;
    cout<<"------------------Linux Command------------------"<<endl;
    cout<<"1. ls"<<endl;
    cout<<"2. cd"<<endl;
    cout<<"3. ps"<<endl;
    cout<<"4. kill"<<endl;
    cout<<"5. rm"<<endl;
    cout<<"6. cp"<<endl;
    cout<<"7. mv"<<endl;
    cout<<"8. cat"<<endl;
    cout<<"9. touch"<<endl;
    cout<<"10. wc"<<endl;
    cout<<"11. pwd"<<endl;
    cout<<"12. mkdir"<<endl;
    cout<<"13. rmdir"<<endl;
    cout<<"14. vi"<<endl;
    cout<<"15. head"<<endl;
    cout<<"16. tail"<<endl;
    cout<<"0. Exit"<<endl;

    do{
        cout << "Enter your choice: ";
        cin >> n;

        string path1, path2;
        switch (n)
        {
        case 1:
            cout<<"Enter path: ";
            cin>>path1;
            lsCommand(path1);
            break;
	    case 2:
            cout<<"Enter path: ";
            cin>>path1;
            cdCommand(path1);
            break;
        case 3:
            psCommand();
            break;
        case 4:
            cout<<"Enter pid: ";
            cin>>path1;
            killCommand(path1);
            break;
        case 5:
            cout<<"Enter path: ";
            cin>>path1;
            rmCommand(path1);
            break;
        case 6: 
            cout<<"Enter path1: ";
            cin>>path1;
            cout<<"Enter path2: ";
            cin>>path2;
            cpCommand(path1,path2);
            break;
        case 7:
            cout<<"Enter path1: ";
            cin>>path1;
            cout<<"Enter path2: ";
            cin>>path2;
            mvCommand(path1,path2);
            break;
        case 8:
            cout<<"Enter path: ";
            cin>>path1;
            catCommand(path1);
            break;
        case 9: 
            cout<<"Enter path: ";
            cin>>path1;
            touchCommand(path1);
            break;
        case 10:    
            cout<<"Enter path: ";
            cin>>path1;
            wcCommand(path1);
            break;
        case 11:
            pwdCommand();
            break;
        case 12:
            cout<<"Enter path: ";
            cin>>path1;
            mkdirCommand(path1);
            break;
        case 13:
            cout<<"Enter path: ";
            cin>>path1;
            rmdirCommand(path1);
            break;
        case 14:
            cout<<"Enter path: ";
            cin>>path1;
            viCommand(path1);
            break;
        case 15:
            cout<<"Enter path: ";
            cin>>path1;
            headCommand(path1);
            break;
        case 16:
            cout<<"Enter path: ";
            cin>>path1;
            tailCommand(path1);
            break;
        case 0:
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }while(n!=0);

    return 0;
}