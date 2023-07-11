# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
#include<string.h> 

int main()
{
    int id, retval;
    printf("Enter the message you want to send\n");
    char sentence[30];
    fgets(sentence, sizeof(sentence),stdin);
    fflush(stdin);
    retval=mkfifo("pipe",0666);
    id = open ("pipe", O_WRONLY);
    write(id, sentence, sizeof(sentence));
    close(id);
    return 0;
}