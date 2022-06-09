#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("/dev/stdout", O_CREAT|O_TRUNC);
	if (fd == -1) {
		return -1;
	}
	return 0;
}
