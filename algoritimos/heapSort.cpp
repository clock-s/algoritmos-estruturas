#include <iostream>
#include <vector>


#define MAX 1
#define MIN 0

using namespace std;




void heapfy(vector<int> &heap, int index, int size, bool max = 1, int first_index = 1){
  int left = index*2 - (first_index - 1);
  int right = index*2 + 1 - (first_index - 1);
  int key = index;


  if(max == 1){
    if(left < size && heap[left] > heap[key]){
      key = left;
    }

    if(right < size && heap[right] > heap[key]){
      key = right;
    }
  }else {
    if(left < size && heap[left] < heap[key]){
      key = left;
    }

    if(right < size && heap[right] < heap[key]){
      key = right;
    }
  }


  if(key != index){
    swap(heap[index], heap[key]);

    heapfy(heap, key, size, max, first_index);
  }


  return;
}


void get_heap(vector<int> &heap, int size, bool max = 1, int first_index = 1){

  for(int i = size/2 ; i >= first_index ; i--){
    heapfy(heap, i, size, max, first_index);
  }

}



void heap_sort(vector<int> &heap, bool max = 1, int first_index = 1){
  int size = heap.size();
  get_heap(heap, size, max, first_index);
  int count = 1;

  for(int i = first_index ; i < size ; i++){
    swap(heap[first_index], heap[size - count]);
    heapfy(heap, first_index, size - count, max, first_index);
    count++;
  }

}



int main(int argc, char const *argv[]){
  
  vector<int> array = {0, 20, 5, 10, 15, 35, 10, 28, 9, 7, 8, 10, 11};

  heap_sort(array, MAX, 2);

  for(int i = 1 ; i < array.size() ; i++){
    cout << array[i] << " ";
  }

  cout << endl;


  return 0;
}

