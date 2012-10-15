// lower_bound/upper_bound example
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main () {
  int myints[] = {10,20,30,30,20,10,10,20,1,-1,2,23,4,5,6,7,11,2,34,56};
  vector<int> v(myints,myints+20); 
  sort (v.begin(), v.end());           // 10 20 30 30 20 10 10 20
  vector<int>::iterator low,up;

  //sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  // low=lower_bound (v.begin(), v.end(), 0); //          ^
  // up= upper_bound (v.begin(), v.end(), 35); //  


  low=lower_bound (v.begin(), v.end(), 0); //          ^
  up= upper_bound (v.begin(), v.end(), 35); //  
 

  unsigned int lower_index = int(low- v.begin());
  unsigned int upper_index = int(up - v.begin());
  cout<<"density is : "<<upper_index-lower_index<<endl;
  for(int i = lower_index ; i< upper_index; i++){
    cout<< v[i]<<endl;
  }

  cout << "lower_bound at position " << int(low- v.begin()) << endl;
  cout << "upper_bound at position " << int(up - v.begin()) << endl;

  return 0;
}

//////////////////////////////////////////////////////

