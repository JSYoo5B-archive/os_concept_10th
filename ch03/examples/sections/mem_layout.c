#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int gUninit;	// Global variable without init value
int gInit = 15;	// Global variable with init value

void by_value(int arg)
{
	int lV;

	printf("  %s()\t&arg = \t%p\n", __func__, &arg);
	printf("  %s()\t&lV = \t%p\n", __func__, &lV);
}

void by_addr(int* pArg)
{
	printf("  %s()\tpArg = \t%p\n", __func__, pArg);
}

int main(int argc, char *argv[])
{
	static int sUninit;		// Static local variable without init
	static int sInit = 10;	// Static local variable with init

	printf("--Codes--\n");
	printf("&main() = \t%p\n", &main);
	printf("&by_value() = \t%p\n", &by_value);
	printf("&by_addr() = \t%p\n", &by_addr);
	printf("&printf() = \t%p\n", &printf);

	printf("--Global variables--\n");
	printf("%s()\t&gInit = \t%p\n", __func__, &gInit);
	printf("%s()\t&gUninit = \t%p\n", __func__, &gUninit);
	
	printf("--Static variables--\n");
	printf("%s()\t&sInit = \t%p\n", __func__, &sInit);
	printf("%s()\t&sUninit = \t%p\n", __func__, &sUninit);


	int lVar;	// Local variable
	int *phVar;	// Pointer to the heap alloc variable

	phVar = (int *)malloc(sizeof(int) * 10000);

	printf("--Local & dynamic variables--\n");
	printf("%s()\t&lVar = \t%p\n", __func__, &lVar);
	printf("%s()\tphVar = \t%p\n", __func__, phVar);

	by_value(lVar);
	by_addr(&lVar);

	pid_t pid;
	pid = getpid();
	printf("\n results of /proc/%d/maps\n", pid);
	
	char map_cmd[80];
	sprintf(map_cmd, "cat /proc/%d/maps", pid);
	system(map_cmd);

	return 0;
}
