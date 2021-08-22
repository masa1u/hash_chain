#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DATA_SIZE 1000000

int ccount;

int binary(int key, int *array, int size){
  int top = size-1;
  int bottom = 0;
  int count = 0;
  while(1){
    count += 1;
    ccount += 1;
    int target = (bottom+top)/2;
    if(key==array[target]){
      break;}
      else if(key<array[target]){
        top=target;}
        else{
          bottom=target;}
    if(size < pow(2, count)){
      break;
    }
  }
  return 0;
}

int main(){
  ccount = 0;
  int searchkey;
  int array[DATA_SIZE];
  for(int i=0;i<DATA_SIZE;i++){
    array[i]=array[i-1]+1+ (int)( rand() % 5 );
  }
  int arraysize = sizeof(array)/sizeof(array[0]);

  for(int i=0;i<DATA_SIZE;i++){
    binary(array[i], array, arraysize);
  }
  printf("%d\n", ccount);

  // printf("%d\n", binary(53, array, arraysize));
}
