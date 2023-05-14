#include<bits/stdc++.h>
using namespace std;

map<char, int> freq;
void freqFiller(vector<vector<char>> transactions){
    for(auto i:transactions){
        for(auto j:i){
            freq[j]++;
        }
    }
}

vector<vector<pair<string, int>>> remove(vector<vector<pair<string, int>>> Set, int minSup){
    vector<vector<pair<string, int>>> temp;
    for(auto i:Set){
        for(auto j:i){
            if(j.second>minSup){
                temp.push_back(i);
                break;
            }
        }
    }
    return temp;
}

int main(){
    vector<vector<char>> transactions = {
        {'A','B','C'},
        {'B','C','D','E'},
        {'A','B','D','E'},
        {'B','E','F'},
        {'A','B','C','E'},
        {'A','B','D','F'},
        {'A','B','C','D','E'},
        {'A','B','C','D'},
        {'B','C','D','E','F'},
        {'C','E','F'},
        {'C','F'}
    };
    cout<<"Transactions:"<<endl;
    for(auto i:transactions){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    freqFiller(transactions);
    cout<<"Frequencies:"<<endl;
    for(auto i:freq){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    vector<vector<pair<string, int>>> secondSet;
    
    for(auto i:freq){
        for(auto j:freq){
            if(i.first<j.first){
                vector<pair<string, int>> temp;
                string s = "";
                s += i.first;
                s += j.first;
                int count = 0;
                for(auto k:transactions){
                    int flag = 0;
                    for(auto l:k){
                        if(l==i.first || l==j.first){
                            flag++;
                        }
                    }
                    if(flag==2){
                        count++;
                    }
                }
                temp.push_back(make_pair(s, count));
                secondSet.push_back(temp);
            }
        }
    }
    int minSup = INT_MAX;
    cout<<"Second Set:"<<endl;
    for(auto i:secondSet){
        for(auto j:i){
            minSup = min(minSup, j.second);
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    secondSet = remove(secondSet, minSup);
    cout<<"After removing the elements with support less than minSup: "<<minSup<<endl;
    for(auto i:secondSet){
        for(auto j:i){
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    vector<vector<pair<string, int>>> thirdSet;
    for(auto i:secondSet){
        for(auto j:secondSet){
            if(i[0].first[0]==j[0].first[0] && i[0].first[1]<j[0].first[1]){
                vector<pair<string, int>> temp;
                string s = "";
                s += i[0].first[0];
                s += i[0].first[1];
                s += j[0].first[1];
                int count = 0;
                for(auto k:transactions){
                    int flag = 0;
                    for(auto l:k){
                        if(l==i[0].first[0] || l==i[0].first[1] || l==j[0].first[1]){
                            flag++;
                        }
                    }
                    if(flag==3){
                        count++;
                    }
                }
                temp.push_back(make_pair(s, count));
                thirdSet.push_back(temp);
            }
        }
    }

    minSup = INT_MAX;
    cout<<"Third Set:"<<endl;
    for(auto i:thirdSet){
        for(auto j:i){
            minSup = min(minSup, j.second);
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    thirdSet = remove(thirdSet, minSup);
    cout<<"After removing the elements with support less than minSup: "<<minSup<<endl;
    for(auto i:thirdSet){
        for(auto j:i){
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    vector<vector<pair<string, int>>> fourthSet;
    for(auto i:thirdSet){
        for(auto j:thirdSet){
            if(i[0].first[0]==j[0].first[0] && i[0].first[1]==j[0].first[1] && i[0].first[2]<j[0].first[2]){
                vector<pair<string, int>> temp;
                string s = "";
                s += i[0].first[0];
                s += i[0].first[1];
                s += i[0].first[2];
                s += j[0].first[2];
                int count = 0;
                for(auto k:transactions){
                    int flag = 0;
                    for(auto l:k){
                        if(l==i[0].first[0] || l==i[0].first[1] || l==i[0].first[2] || l==j[0].first[2]){
                            flag++;
                        }
                    }
                    if(flag==4){
                        count++;
                    }
                }
                temp.push_back(make_pair(s, count));
                fourthSet.push_back(temp);
            }
        }
    }

    minSup = INT_MAX;
    cout<<"Fourth Set:"<<endl;
    for(auto i:fourthSet){
        for(auto j:i){
            minSup = min(minSup, j.second);
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    fourthSet = remove(fourthSet, minSup);
    cout<<"After removing the elements with support less than minSup: "<<minSup<<endl;
    for(auto i:fourthSet){
        for(auto j:i){
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    vector<vector<pair<string, int>>> fifthSet;
    for(auto i:fourthSet){
        for(auto j:fourthSet){
            if(i[0].first[0]==j[0].first[0] && i[0].first[1]==j[0].first[1] && i[0].first[2]==j[0].first[2] && i[0].first[3]<j[0].first[3]){
                vector<pair<string, int>> temp;
                string s = "";
                s += i[0].first[0];
                s += i[0].first[1];
                s += i[0].first[2];
                s += i[0].first[3];
                s += j[0].first[3];
                int count = 0;
                for(auto k:transactions){
                    int flag = 0;
                    for(auto l:k){
                        if(l==i[0].first[0] || l==i[0].first[1] || l==i[0].first[2] || l==i[0].first[3] || l==j[0].first[3]){
                            flag++;
                        }
                    }
                    if(flag==5){
                        count++;
                    }
                }
                temp.push_back(make_pair(s, count));
                fifthSet.push_back(temp);
            }
        }
    }

    minSup = INT_MAX;
    cout<<"Fifth Set:"<<endl;
    for(auto i:fifthSet){
        for(auto j:i){
            minSup = min(minSup, j.second);
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    cout<<endl;

    return 0;
}