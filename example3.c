#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thid[10];
int numes[10000];
int count=0;
int prime=0;
int error;

void* randomNumes(void *i)
{  int  db = (intptr_t) i;
    pthread_t tid = pthread_self();
for(int sayi=(db*1000);sayi<(db*1000)+999;sayi++) {
     count=0;
    for(int j=2;j<numes[sayi];j++) {
   if(numes[sayi]%j==0) {
         count=1;
break; }
  }
      if(count==0) {
prime++;  }
 }
printf(" %d prime number one tenth of array\n",prime);
pthread_equal(tid,thid[0]);
	return NULL;
}

int main(void) {
srand((unsigned)time(NULL));
  int a = 0;
 for(int x=1; x<=10000; x++){
  int number = rand() % 8999 +  1000;
          	numes[x]=number; }
      while(a < 10) {
    error = pthread_create(&(thid[a]), NULL, &randomNumes, (void*) (intptr_t) a);
        if (error != 0)
       printf("\n ERROR:[%s]", strerror(error));
          else
       printf("Thread %d -",a+1);
             pthread_join(thid[a],NULL);
              a++;
    }
         return 0; 
         
         }
