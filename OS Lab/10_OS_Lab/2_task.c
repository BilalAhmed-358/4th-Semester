#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sig_handler(int signo)
{
    if (signo == SIGSTOP)
        printf("This program is immune to SIGSTOP.\n");
    if (signo == SIGKILL)
        printf("This program is immue to SIGKILL.\n");
}
int main(void)
{
    struct sigaction sa, sa1;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sig_handler;
    sigaction(SIGSTOP, &sa, NULL);
    sa1.sa_flags = SA_RESTART;
    sa1.sa_handler = sig_handler;
    sigaction(SIGKILL, &sa1, NULL);

    while (1)
    {
        sleep(2);
        kill(getpid(), SIGSTOP);
        sleep(2);
        kill(getpid(), SIGKILL);
    }
    return 0;
}