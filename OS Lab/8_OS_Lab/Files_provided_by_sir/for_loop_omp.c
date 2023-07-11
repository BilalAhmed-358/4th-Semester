#include<stdio.h>
#include<omp.h>

int main(){

#pragma omp parallel for
for(int i=0;i<6;i++)
{
printf("Hello World\n");
}  


}
