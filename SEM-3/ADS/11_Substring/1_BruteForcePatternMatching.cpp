#include<iostream>
using namespace std;

bool BruteForcePatternMatching(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    for (int i=0;i<=n-m;i++){
        int j;
        for (j=0;j<m;j++){
            if(text[i+j]!=pattern[j])break;
        }
        if(j==m) return true;
    }
    return false;
}

int main(){
    string text = "AABAACAADAABAABA";
    if(BruteForcePatternMatching(text,"BAABA")) cout<<"Pattern found"<<endl;
    else cout<<"Pattern not found"<<endl;

    if(BruteForcePatternMatching(text,"AAABA")) cout<<"Pattern found"<<endl;
    else cout<<"Pattern not found"<<endl;

    return 0;

}