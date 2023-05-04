#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    unordered_map<string,Trie*> children;
    int count;
    Trie(){
        count = 0;
    }
};

void printTransactions(vector<vector<string>> &transactions){
    int cnt=0;
    cout<<"Transactions are: "<<endl;
    for(auto i:transactions){
        cout<<"T"<<++cnt<<": ";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printFrequentItems(vector<pair<string,int>> &v){
    sort(v.begin(),v.end(),[](pair<string,int> a,pair<string,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    });
    for(auto i:v){
        cout<<i.first<<":"<<i.second;
        if(i!=v.back()) cout<<", ";
    }
    cout<<endl<<endl;
}

void frequencies(vector<vector<string>> &transactions, vector<pair<string, int>> &v, vector<pair<string, int>> &v1)
{
    unordered_map<string,int> mp;
    for(auto i:transactions){
        for(auto j:i){
            mp[j]++;
        }
    }
    for(auto i:mp){
        v1.push_back({i.first,i.second});
    }
    for(auto i:mp){
        if(i.second>=3){
            v.push_back({i.first,i.second});
        }
    }
}

vector<vector<string>> orderedTrans(vector<vector<string>> &transactions, vector<pair<string, int>> &v){
    vector<vector<string>> orderedTransactions;
    for(auto i:transactions){
        vector<string> temp;
        for(auto j:v){
            if(find(i.begin(),i.end(),j.first)!=i.end()){
                temp.push_back(j.first);
            }
        }
        orderedTransactions.push_back(temp);
    }
    return orderedTransactions;
}

void printOrderedTransactions(vector<vector<string>> &orderedTransactions,vector<vector<string>> &transactions){
    int mx = 0;
    for (auto i : transactions){
        mx = max(mx, (int)i.size());
    }
    cout<<"Ordered Transactions are: "<<endl;
    for(int i=0;i<orderedTransactions.size();i++){
        cout<<"T"<<i+1<<"-> ";
        int cnt = 0;
        for(auto j:transactions[i]){
            cout<<j<<" ";
            cnt++;
        }
        for(int j=0;j<mx-cnt;j++){
            cout<<"  ";
        }
        cout<<"-> ";
        for(auto j:orderedTransactions[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

Trie* trieCreation(vector<vector<string>> &orderedTransactions){
    Trie* root = new Trie();
    for(auto i:orderedTransactions){
        Trie* temp = root;
        for(auto j:i){
            if(temp->children[j]==NULL){
                temp->children[j] = new Trie();
            }
            temp = temp->children[j];
            temp->count++;
        }
    }
    return root;
}


void findd(Trie* root, vector<pair<vector<string>,int>> &v,vector<string> s,string &tar,string l){
    if(root==NULL) return;
    if(l!="") s.push_back(l);
    if(root->children[tar]!=NULL){
        v.push_back({s, root->children[tar]->count});
    }
    for(auto i:root->children){
        findd(i.second,v,s,tar,i.first);
    }
}

void conditionals(vector<pair<string, int>> &v, Trie* root){
    int mx = 0;
    vector<pair<string, vector<pair<vector<string>,int>>>> cpb;
    for(auto i:v){
        Trie* temp = root;
        vector<pair<vector<string>, int>> temp1;
        findd(temp,temp1,{},i.first,"");
        cpb.push_back({i.first,temp1});
    }
    reverse(cpb.begin(),cpb.end());
    vector<string> ans,ans2,ans3;
    for(auto i:cpb){
        int cnt = 0;
        string a = i.first;
        unordered_map<string,int> mp;
        a+=": {";
        for(auto j:i.second){
            a+="(";
            for(auto k:j.first){
                a+=k;
                mp[k]+=j.second;
                if(k!=j.first.back()) a+=",";
            }
            a+=": "+to_string(j.second)+")";
            if(j!=i.second.back()) a+=",";
            cnt+=j.second;
        }
        a+="}";
        string b = "";
        if(a[5]==':'){
            b+=a[0];
            b+=": {}";
        }
        else b=a;
        ans.push_back(b);
        string c="";
        vector<pair<int,vector<string>>> mp1;
        mp1.push_back({cnt,{i.first}});
        for(auto j:mp){
            if(j.second>=3){
                mp1.push_back({j.second,{j.first}});
                if(c=="") c+=j.first+": "+to_string(j.second);
                else c+=", "+j.first+": "+to_string(j.second);
            }
        }
        ans2.push_back(c);
        if(mx<b.length()) mx=b.length();
        sort(mp1.begin(),mp1.end());
        string d="";
        for(int j=mp1.size()-1;j>=0;j--){
            
            if(d=="") d+=mp1[j].second[0]+": "+to_string(mp1[j].first);
            else d+=", "+mp1[j].second[0]+": "+to_string(mp1[j].first);
        }
        ans3.push_back(d);
    }

    cout<<"Conditional Patterns Base: "<<endl;
    for(auto i:ans){
        cout<<i<<endl;
    }
    cout<<endl;

    cout<<"Conditional Frequent Pattern Tree: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        for(int j=0;j<mx+1-ans[i].length();j++){
            cout<<" ";
        }
        cout<<"-> "<<ans2[i]<<endl;
    }
    cout<<endl;

    cout<<"Frequent Pattern Generated: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        for(int j=0;j<mx+1-ans[i].length();j++){
            cout<<" ";
        }
        cout<<"-> "<<ans3[i]<<endl;
    }
    cout<<endl;
}

int main(){
    vector<vector<string>> transactions{
        {"E","K","M","N","O","Y"},
        {"D","E","K","N","O","Y"},
        {"A","E","K","M"},
        {"C","K","M","U","Y"},
        {"C","E","I","K","O","O"}
    };
    int minsup = 3;

    printTransactions(transactions);

    vector<pair<string, int>> v,v1;
    frequencies(transactions, v, v1);

    cout<<"Frequency of each item are: ";
    printFrequentItems(v1);

    cout<<"Frequency of each item after pruning are: ";
    printFrequentItems(v);

    vector<vector<string>> orderedTransactions=orderedTrans(transactions,v);
    printOrderedTransactions(orderedTransactions,transactions);

    Trie* root = trieCreation(orderedTransactions);

    conditionals(v,root);

    return 0;
}