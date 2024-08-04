#include <stdio.h>
#include <string.h>

void secret(){
  char word[]={73,67,78,72,84,118,31,90,112,110,28,74,112,104,31,64,75,112,110,91,112,102,107,110,82};
  int word_len = strlen(word);
  char nword[word_len];
  for(int i=0; i < word_len - 1; i++){
    nword[i] = word[i]^0x2f;
  }
  printf("Try to find flag here!\n");
}

int main(){
  secret();
  printf("Hello World!");
  return 0;
}
