#include <stdio.h>
#include <stdlib.h>

void variablesLocales(int a,int b,int c){
  int la, lb, lc;
  la = 0; lb = 0; lc = 0;
  printf("a: %p  b: %p  c: %p\n", (void *)&a, (void *)&b, (void *)&c );
  printf("la: %p  lb: %p  lc: %p\n", (void *)&la, (void *)&lb, (void *)&lc );
 }



int main(){
  char *esp, *ebp;
  int a, b, c;
  a = 0; b = 0; c = 0;
  asm(
      "movl %%esp, %0"
      "\n\t"
      "movl %%ebp, %1"
      :"=r" (esp), "=r" (ebp)
      );
  printf("esp: %p  ebp: %p \n", esp, ebp );
  variablesLocales(a, b, c);
	return 0;
}
