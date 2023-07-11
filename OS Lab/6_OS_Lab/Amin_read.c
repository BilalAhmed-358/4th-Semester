#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
struct msg{
	long int a;
	char arr[20];
};
int main(){ 
	 struct msg var;
	 int msgid=msgget(12345,0666);
	 if(msgid==-1){
	 	printf("error");
	 }
	 else{
	 	var.a=1;

		//fgets(var.arr,sizeof(var.arr),stdin);

		msgrcv(msgid,&var,sizeof(var),1,0);
		printf("first message:%s\n",var.arr);
		
		msgrcv(msgid,&var,sizeof(var),1,0);
		printf("second message:%s\n",var.arr);
	 	
		msgrcv(msgid,&var,sizeof(var),1,1);
		printf("third message:%s\n",var.arr);
	 } 
}