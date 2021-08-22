#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUCKET_SIZE 10000
#define DATA_SIZE 1000000

struct entry{
  int key;
  struct entry *next;
};

struct entry *table[BUCKET_SIZE];

void init(){
  for(int i=0;i<BUCKET_SIZE;i++){
    table[i] = NULL;
  }
}


void hash_build(int array[]){
  for(int i=0;i<DATA_SIZE;i++){
    int index = array[i] % BUCKET_SIZE;

    struct entry *list = malloc(sizeof(struct entry));
    list->key = array[i];
    list->next = NULL;

    if(table[index]==NULL){
      table[index] = list;
    }else{
      struct entry *temp = table[index];
      while(temp->next){

        temp = temp->next;
      }

      temp->next = list;
    }
  }
}

void print(){

  for(int i = 0; i < BUCKET_SIZE; i++){
    struct entry *temp = table[i];
    printf("table[%d]-->",i);
    while(temp){
      printf("%d -->",temp->key);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}


void hash_search(int search_key){
  int index = search_key % BUCKET_SIZE;

  struct entry *temp = table[index];
  while(temp){
    if(temp->key==search_key){
      // printf("%d: match\n", search_key);
      break;
    }
    temp = temp->next;
  }
}


int main(){
  int array[DATA_SIZE];
  for(int i=0;i<DATA_SIZE;i++){
    array[i]=array[i-1]+1+ (int)(rand() % 5 );
  }

  hash_build(array);

  // print();

  for(int i=0;i<DATA_SIZE;i++){
    hash_search(array[i]);
  }
}
