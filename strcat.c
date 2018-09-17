#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <time.h>
#include <stdlib.h>
#define ANTAL_TAL 100
#include <stdbool.h>


typedef struct matpost {
        double varde;
        int nr;
     } matvarde;

void slump(int v[], int nr) {
  int i;
  srand((unsigned)time(NULL)); 
  for (i = 0; i < nr; i++)
       v[i] = rand()%30;
}


void insort(int * arr, int sz){

  for (int j=1; j<sz-1; ++j){
    int key = *(arr+j);
    int i =j-1;
    while(i>=0 && *(arr+i) > key)
    {

      *(arr+(i+1)) = *(arr+i);
        i--;
    }    
    *(arr+(i+1))=key;  
  } 
  
}

void selsort(int * arr, int sz) {

  int minindex,temp;

  for (int i=0; i<sz; ++i){

    minindex = i;
    for (int j=i+1; j<sz; ++j){ 
      if (arr[j] < arr[minindex])
          minindex = j;
     } 
     temp = arr[i];
     arr[i] =arr[minindex];
     arr[minindex] = temp;  
  }

}

void sortera(int *arr, int sz, void (*f)(int * , int)) {
     f(arr,sz);
 }


void print(int * arr, int sz){

  while (sz--)
    printf("%d\n", *arr++);

}
int main(int c, char *argv[])
{
  int arr[] = {2,5,6,1,7};
 
  sortera(arr,5,insort);
  print(arr,5);

  return 0; 
}