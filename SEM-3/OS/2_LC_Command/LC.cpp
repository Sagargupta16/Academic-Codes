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

int main(int argc, char **argv)
{
    string command;
    while(1){
        cout<<"$ ";
        getline(cin,command);
        if(command=="exit")break;
        else if(command=="ls"){
            lsCommand(".");
        }
        else if(command.substr(0,2)=="ls"){
            lsCommand(command.substr(3));
        }
        else if(command.substr(0,2)=="cp"){
            string path1=command.substr(3,command.find_last_of(" ")-3);
            string path2=command.substr(command.find_last_of(" ")+1);
            cpCommand(path1,path2);
        }
        else if(command.substr(0,2)=="cd"){
            string path=command.substr(3);
            cdCommand(path);
        }
        else if(command.substr(0,5)=="mkdir"){
            string path=command.substr(6);
            mkdirCommand(path);
        }
        else if(command.substr(0,5)=="rmdir"){
            string path=command.substr(6);
            rmdirCommand(path);
        }
        else if(command=="ps"){
            psCommand();
        }
        else if(command.substr(0,4)=="kill"){
            string pid=command.substr(5);
            killCommand(pid);
        }
        else if(command.substr(0,2)=="rm"){
            string path=command.substr(3);
            rmCommand(path);
        }
        else if(command.substr(0,5)=="touch"){
            string path=command.substr(6);
            touchCommand(path);
        }
        else if(command.substr(0,3)=="cat"){
            string path=command.substr(4);
            catCommand(path);
        }
        else if(command.substr(0,2)=="mv"){
            string path1=command.substr(3,command.find_last_of(" ")-3);
            string path2=command.substr(command.find_last_of(" ")+1);
            mvCommand(path1,path2);
        }
        else if(command.substr(0,2)=="vi"){
            string path=command.substr(3);
            viCommand(path);
        }
        else if(command.substr(0,4)=="head"){
            string path=command.substr(5);
            headCommand(path);
        }
        else if(command.substr(0,4)=="tail"){
            string path=command.substr(5);
            tailCommand(path);
        }
        else if(command.substr(0,2)=="wc"){
            string path=command.substr(3);
            wcCommand(path);
        }
        else if(command=="pwd"){
            pwdCommand();
        }
        else{
            cout<<"command not found"<<endl;
        }
    }
    return 0;
}