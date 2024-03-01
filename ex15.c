#include <stdio.h>

int main(){
int num[] = {1,2,3};
int arr[] = {4,5,6};

int *p1 = num;
int *p2 = &arr[0];
for(int i=0;i<3;i++){
printf("%d", *p1);
printf("%d", *p2);
p1++;
p2++;
}
}
