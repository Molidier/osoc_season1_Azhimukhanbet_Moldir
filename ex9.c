#include <stdio.h>

int main(int argc, char *argv[]){
int i = 0;
while(i<5){
printf("%s \n", argv[i]);
i++;
}
return 0;
}
