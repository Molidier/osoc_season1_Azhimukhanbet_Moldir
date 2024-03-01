#include <stdio.h>

int main(int argc, char *argv[]){
int i=0;

for(i =1;i<argc;i++){
	printf("arg %d: %s\n", i, argv[i]);
}

char *states[] = {
"Calif", "Oreg", "Wash", "Texas"};

int ns = 4;

for(i = 0; i<ns; i++){
	printf("state %d: %s\n", i, states[i]);
}
return 0;

}
