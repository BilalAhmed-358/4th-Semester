#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void handler_siguser1(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGKILL)
        printf("received SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}
int main(void)
{
    struct sigaction sa1;
    sa1.sa_flags = SA_RESTART;
    sa1.sa_handler = handler_siguser1;

    if (sigaction(SIGUSR1, &sa1, NULL) == -1)
        printf("\ncan't catch SIGUSR1\n");
    if (sigaction(SIGKILL, &sa1, NULL) == -1)
        printf("\ncan't catch SIGKILL\n");
    if (sigaction(SIGSTOP, &sa1, NULL) == -1)
        printf("\ncan't catch SIGSTOP\n");
    // A long long wait so that we can easily issue a signal to this process
    while (1)
    {
        // printf("Program reached here.\n");
        kill(getpid(), SIGUSR1);
        sleep(2);
        kill(getpid(), SIGSTOP);
        sleep(2);
        kill(getpid(), SIGKILL);
    }
    return 0;
}