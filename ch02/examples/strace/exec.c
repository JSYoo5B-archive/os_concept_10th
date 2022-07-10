#include <unistd.h>

int main(void)
{
	execl("./hello", "./hello", NULL);
}
