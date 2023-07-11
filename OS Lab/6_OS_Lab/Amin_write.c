#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
struct msg{
	long int a;
	char arr[20];
};
int main(){ 
	 struct msg var;
	 int msgid=msgget(12345,0666|IPC_CREAT);
	 if(msgid==-1){
	 	printf("error");
	 }
	 else{
	 	var.a=1;
		fgets(var.arr,sizeof(var.arr),stdin);
		if(msgsnd(msgid,&var,sizeof(var),0)==-1)
			printf("error");

	 } 
}
