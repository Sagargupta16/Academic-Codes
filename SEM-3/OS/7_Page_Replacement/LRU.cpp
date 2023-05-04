#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int capacity = 4;
  int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
  deque<int> q(capacity);
  int count=0;
  int page_faults=0;
  deque<int>::iterator itr;
  q.clear();
  for(int i:arr){
    itr = find(q.begin(),q.end(),i);
    if(!(itr != q.end())){
      ++page_faults;
      if(q.size() == capacity)
      {
        q.erase(q.begin());
        q.push_back(i);
      }
      else{
        q.push_back(i);
 
      }
    }
    else{
      q.erase(itr);
      q.push_back(i);        
    }
  }
  cout<<"Page Faults are: "<<page_faults;
}
 