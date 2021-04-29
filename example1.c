#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int count=0;
int prime=0;
pthread_t tid[10];
int error;
void* randomNumes(void *i) {
  int numes[1000];
 
for (int sayi = 1; sayi<=1000;sayi++) {
  numes[sayi]= rand () %8999 + 1000;
  count=0;
  for(int j=2; j< numes[sayi]; j++){
  if(numes[sayi]%j == 0)
      count=1; }
if (count==0) {
  prime++;  }  }
  printf(" %d primes. \n", prime);
return NULL;
}
int main(void)
{ srand((unsigned)time(NULL));
  int a = 0;
          while(a < 10)  {
   error = pthread_create(&(tid[a]), NULL, &randomNumes, (void*) (intptr_t) a);
 	if (error != 0)
           printf("\n Error:[%s]", strerror(error));
        else
        printf("Thread  %d  -   ",a+1);
                pthread_join(tid[a],NULL);
                 a++; } 
            return 0;      }

