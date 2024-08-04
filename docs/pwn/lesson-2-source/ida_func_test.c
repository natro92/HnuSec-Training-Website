#include <stdio.h>

void hi(){
  char word[]="Hi CTFer~";
  for(int i=0; i<10;i++){
    printf("%c",word[i]);
  }
  printf("\n");
}

int main(){
  hi();
  printf("Hello World!\n");
  return 0;
}
