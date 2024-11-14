#include <iostream>

using namespace std;

void build(int *ft, int index, const int &add, const int &size){
  for(; index < size ; index += ((index) & -(index))){
    ft[index] += add;
  }
}

int rsq(int *ft, int index){
  int sum = 0;
  for(; index > 0 ; index -= ((index) & -(index))){
    sum += ft[index];
  }

  return sum;
}

int interValSum(int *ft, int i, int j){
  return rsq(ft,j) - rsq(ft, i-1);
}

int main(){
  int size;
  
  cout << "Size of array: "; cin >> size; 
  size += 1;
  
  int *array = new int[size];
  array[0] = 0;
  
  cout << "Put values in array";
  for(int i = 1 ; i < size ; i++){
    cin >> array[i];
  }
  
  int *ft = new int[size]{};

  for(int i = 1 ; i < size ; i++){
    build(ft, i, array[i], size);
  }
  
  cout << rsq(ft, 3) << endl;

  cout << interValSum(ft,2,3);


  return 0;
}
