#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_t thid[10];
int error;
void* randomNumes(void *i) {
    int  db = (intptr_t) i;
char alph[] = "abcdefghijklmnopqrstuvwxyz";
char vowelAlph[]="aeiou";
int vowelNum=0;
int consonantNum;
    pthread_t tid = pthread_self();
 for(int x=1; x<=5000; x++){
  char ch = alph[rand() % 26];

if(ch==vowelAlph[0]){
	vowelNum++; }
if(ch==vowelAlph[1]){
	vowelNum++; }
if(ch==vowelAlph[2]){
	vowelNum++; }
if(ch==vowelAlph[3]){
	vowelNum++; }
if(ch==vowelAlph[4]){
	vowelNum++; }
  }
     consonantNum=5000-vowelNum;

printf("Thread %d : Vowels:%d , consonants:%d\n", db , vowelNum , consonantNum );
pthread_equal(tid,thid[0]);
return NULL; }

int main(void){
 srand((unsigned)time(NULL));
    int a = 0;
while(a < 10) {
   error = pthread_create(&(thid[a]), NULL, &randomNumes, (void*) (intptr_t) a);
 if (error != 0)
          printf("\n ERROR:[%s]", strerror(error));
   else
     pthread_join(thid[a],NULL);
    a++;   }
    return 0;  }
