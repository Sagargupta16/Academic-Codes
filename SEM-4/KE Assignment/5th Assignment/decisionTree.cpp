#include <bits/stdc++.h>
using namespace std;

void printTree(vector<vector<string>> data, vector<string> attributes){
    int n = data.size(), m = data[0].size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

void printData(vector<string> head, vector<vector<string>> data){
    cout << "------------------------------------------------------------------" << endl;
    for (int i = 0; i < head.size(); i++){
        cout << head[i] << "\t";
        if (head[i].size() < 8) cout << "\t";
    }
    cout << endl << endl;
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].size(); j++){
            cout << data[i][j] << "\t";
            if (data[i][j].size() < 8) cout << "\t";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

double findEntropy(vector<vector<string>> data){
    int n = data.size(), m = data[0].size();
    int yes = 0, no = 0;
    for (int i = 0; i < n; i++){
        if (data[i][m - 1] == "Yes") yes++;
        else no++;
    }
    double p = (double)yes / (yes + no);
    double q = (double)no / (yes + no);
    if (p == 0 || q == 0) return 0;
    double entropy = -1 * p * log2(p) - q * log2(q);
    return entropy;
}

double findEntropyWRT(vector<vector<string>> data, int col){
    int n = data.size(), m = data[0].size();
    unordered_map<string, int> mp;
    vector<string> temp;
    for (int i = 0; i < n; i++){
        mp[data[i][col]]++;
    }
    double entropyWRT = 0;
    for (auto it = mp.begin(); it != mp.end(); it++){
        int yes = 0, no = 0;
        for (int i = 0; i < n; i++){
            if (data[i][col] == it->first){
                if (data[i][m - 1] == "Yes") yes++;
                else no++;
            }
        }
        double p = (double)yes / (yes + no);
        double q = (double)no / (yes + no);
        if (p == 0 || q == 0) continue;
        double entropy = -1 * p * log2(p) - q * log2(q);
        entropyWRT += (double)(it->second) * entropy / n;
    }
    return entropyWRT;
}

void performDT(vector<vector<string>> data, vector<string> attributes, vector<string> &paths, string s){
    int n = data.size(), m = data[0].size();
    double entropy = findEntropy(data);
    if (entropy == 0){
        paths.push_back(s + data[0][m - 1]);
        cout << "Decision: " << data[0][m - 1] << endl;
        cout << endl << endl;
        return;
    }
    cout << "Entropy: " << entropy << endl;
    double maxGain = INT_MIN;
    int maxGainCol = -1;
    for (int i = 0; i < m - 1; i++){
        double entropyWRT = findEntropyWRT(data, i);
        double gain = entropy - entropyWRT;
        cout << "Gain for " << attributes[i] << ": " << gain << endl;
        if (gain > maxGain){
            maxGain = gain;
            maxGainCol = i;
        }
    }
    cout << "Max Gain: " << maxGain << endl;
    cout << "Max Gain Column: " << attributes[maxGainCol] << endl;
    s += attributes[maxGainCol] + "--";
    unordered_map<string, int> mp;
    vector<string> temp;
    for (int i = 0; i < n; i++){
        if (mp.find(data[i][maxGainCol]) == mp.end()){
            mp[data[i][maxGainCol]] = 1;
            temp.push_back(data[i][maxGainCol]);
        }
    }
    vector<vector<vector<string>>> newData;
    for (int i = 0; i < temp.size(); i++){
        vector<vector<string>> tempData;
        for (int j = 0; j < n; j++){
            if (data[j][maxGainCol] == temp[i]){
                vector<string> tempRow;
                for (int k = 0; k < m; k++){
                    if (k != maxGainCol) tempRow.push_back(data[j][k]);
                }
                tempData.push_back(tempRow);
            }
        }
        newData.push_back(tempData);
    }
    cout << endl << "------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for (int i = 0; i < newData.size(); i++){
        string t = s;
        t += temp[i] + "--> ";
        cout << "For " << attributes[maxGainCol] << " = " << temp[i] << endl;
        vector<string> newAttributes;
        for (int j = 0; j < attributes.size(); j++){
            if (j != maxGainCol) newAttributes.push_back(attributes[j]);
        }
        printData(newAttributes, newData[i]);
        if (findEntropy(newData[i]) == 0){
            paths.push_back(t+attributes[attributes.size()-1]+"--"+newData[i][0][newData[i][0].size()-1]);
            cout << "Decision: " << newData[i][0][newData[i][0].size() - 1] << endl;
        }
        else performDT(newData[i], newAttributes, paths, t);
        cout << "------------------------------------------------------------------" << endl << endl;
    }
}

int main()
{
    vector<string> attributes = { "Age", "Income", "Student", "Credit_Rating" , "Buys_Computer" };
    vector<vector<string>> data = {
        { "Youth", "High", "No", "Fair", "No" },
        { "Youth", "High", "No", "Excellent", "No" },
        { "Middle_Aged", "High", "No", "Fair", "Yes" },
        { "Senior", "Medium", "No", "Fair", "Yes" },
        { "Senior", "Low", "Yes", "Fair", "Yes" },
        { "Senior", "Low", "Yes", "Excellent", "No" },
        { "Middle_Aged", "Low", "Yes", "Excellent", "Yes" },
        { "Youth", "Medium", "No", "Fair", "No" },
        { "Youth", "Low", "Yes", "Fair", "Yes" },
        { "Senior", "Medium", "Yes", "Fair", "Yes" },
        { "Youth", "Medium", "Yes", "Excellent", "Yes" },
        { "Middle_Aged", "Medium", "No", "Excellent", "Yes" },
        { "Middle_Aged", "High", "Yes", "Fair", "Yes" },
        { "Senior", "Medium", "No", "Excellent", "No" }
    };


    cout << endl << endl << "Decision Tree For "<<attributes[attributes.size()-1]<<" as Final Result" << endl;
    printData(attributes, data);
    vector<string> paths;
    performDT(data, attributes, paths, "");
    cout << "All Paths: " << endl;
    for (int i = 0; i < paths.size(); i++){
        cout << paths[i] << endl;
    }
    return 0;
}