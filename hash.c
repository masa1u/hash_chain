#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 300000

struct entry{
  int data;
};

struct entry table[BUCKET_SIZE];

void hash_build(int delta, int array[]){
  for(int i=0;i<10000;i++){
    int index = array[i] % BUCKET_SIZE;

    while(table[index].data != 0){
      index = (index+delta) % BUCKET_SIZE;
    }
    table[index].data = array[i];
  }
}

void hash_search(int delta, int search_key){
  int index = search_key % BUCKET_SIZE;
  int count = 0;
  do{
    if(table[index].data==search_key){
      break;
    }
    index = (index+delta) % BUCKET_SIZE;
    count += 1;
  }while(table[index].data==0 && count < BUCKET_SIZE%delta);
}


int main(){
  int array[BUCKET_SIZE];
  for(int i=0;i<10000;i++){
    array[i]=array[i-1]+1+ (int)(rand() % 5 );
  }


  int delta = 3;
  // int search_key = 562;

  hash_build(delta, array);
  for(int i=0;i<50000;i++){
    hash_search(delta, i);
  }
}
