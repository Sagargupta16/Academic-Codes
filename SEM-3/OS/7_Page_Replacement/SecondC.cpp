#include <bits/stdc++.h>
using namespace std;
static bool findAndUpdate(int x, int arr[],bool second_chance[], int frames){
    int i;
    for (i = 0; i < frames; i++){

        if (arr[i] == x){
            second_chance[i] = true;
            return true;
        }
    }
    return false;
}

static int replaceAndUpdate(int x, int arr[],bool second_chance[], int frames, int pointer){
    while (true){
        if (!second_chance[pointer]){
            arr[pointer] = x;
            return (pointer + 1) % frames;
        }
        second_chance[pointer] = false;
        pointer = (pointer + 1) % frames;
    }
}

static void printHitsAndFaults(string reference_string,int frames){
    int pointer, i, l = 0, x, pf;
    pointer = 0;
    pf = 0;
    int arr[frames];
    memset(arr, -1, sizeof(arr));
    bool second_chance[frames];
    string str[100];
    string word = "";
    for (auto x : reference_string){
        if (x == ' '){
            str[l] = word;
            word = "";
            l++;
        }
        else word = word + x;
    }
    str[l] = word;
    l++;
    for (i = 0; i < l; i++){
        x = stoi(str[i]);
        if (!findAndUpdate(x, arr, second_chance, frames)){
            pointer = replaceAndUpdate(x, arr,second_chance, frames, pointer);
            pf++;
        }
    }
    cout << "Total page faults were " << pf << "\n";
}

int main()
{
    string reference_string = "";
    int frames = 0;
    reference_string = "0 4 1 4 2 4 3 4 2 4 0 4 1 4 2 4 3 4";
    frames = 3;
    printHitsAndFaults(reference_string, frames);
    reference_string = "2 5 10 1 2 2 6 9 1 2 10 2 6 1 2 1 6 9 5 1";
    frames = 4;
    printHitsAndFaults(reference_string, frames);
    return 0;
}