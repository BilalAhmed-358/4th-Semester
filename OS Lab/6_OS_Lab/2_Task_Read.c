# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
#include<string.h> 

int main()
{
    int id, retval;
    char sentence[30];
    id = open ("pipe", O_RDONLY);
    read(id, sentence, sizeof(sentence));
    fflush(stdin);
    printf("The message read through FIFO for the first time is:\n");
    printf("%s\n",sentence);
    close(id);
    id = open ("pipe", O_RDONLY);
    read(id, sentence, sizeof(sentence));
    fflush(stdin);
    printf("The message read through FIFO for the second time is:\n");
    printf("%s\n",sentence);
    close(id);
    id = open ("pipe", O_RDONLY);
    read(id, sentence, sizeof(sentence));
    fflush(stdin);
    printf("The message read through FIFO for the third time is:\n");
    printf("%s\n",sentence);
    close(id);
    return 0;
}