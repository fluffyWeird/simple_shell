#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - PID and PPID
 *
 * Description: Prints the pid and the ppid of the calling process.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid, my_ppid;

	my_pid = getpid();
	my_ppid = getppid();

	printf("my pid = %d and my ppid = %u\n", my_pid, my_ppid);

	return (0);
}
