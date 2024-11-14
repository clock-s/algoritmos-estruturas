#include <iostream>



int main (int argc, char *argv[]) {
  std::string array;

  std::cin >> array;
  int n = array.size();

  int *z = new int[n];

  for(int i = 1 ; i < array.size() ; ++i){
    while((z[i] + i) < n && (array[i+z[i]] == array[z[i]])){
      ++z[i];
    }
    i += z[i];
  }

  int max = 0; int index = 0;
  for(int i = 0 ; i < n ; ++i){
    std::cout << z[i] << " ";
    if(max < z[i]) {
      max = z[i];
      index = i;
    };
  }

  std::cout << std::endl;

  for(int i = 0 ; i < n ; ++i){
    if(z[i] < max) continue;
    std::cout << array.substr(i,i+z[i]) << std::endl;
  }

  return 0;
}
