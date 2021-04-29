#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
// 15.2 yi içeriyor bu yanlışlıkla burada yazdın
pthread_t thid[5];
  static int numes[2000];
  int count;
  int oneArr,twoArr,threeArr,fourArr,fiveArr;
  int error;

void* randomNumes(void *i) {
      int  number = (intptr_t) i;
      pthread_t tid = pthread_self();

    oneArr=0;
      twoArr=0;
       threeArr=0;
         fourArr=0;
           fiveArr=0;
	
for(int y=(number*2000);y<(number*2000)+1999;y++) {
    int e=numes[y];
   count=0;
  while(e != 0) {
 	++count;
    e /= 10; }

	if(count ==1){
	oneArr++;}
	if(count ==2){
	twoArr++; }
	if(count==3){
	threeArr++; }
	if(count==4){
	fourArr++; }
	if(count==5){
}       

printf("Thread %d:  1 - 9: %d,  10 - 99: %d,  100 - 999: %d,  1000 - 9999: %d,  10000 - 49999: %d\n", number+1 , oneArr , twoArr , threeArr , fourArr , fiveArr);

pthread_equal(tid,thid[0]);
return NULL; }

int main(void) {
srand((unsigned)time(NULL));
    int a = 1;

    for(int x=0; x<10000; x++){
      int number =rand() % 50000;
                  numes[x]=number;}

while(a<=5){
    error = pthread_create(&(thid[a]), NULL, &randomNumes, (void*) (intptr_t) a);
  if (error != 0)
            printf("\n ERROR:[%s]", strerror(error));
  else
            pthread_join(thid[a],NULL);
        a++;  }
return 0;   }
