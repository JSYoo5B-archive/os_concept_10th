#include <unistd.h>

int main(void)
{
	char buffer[128] = "hello";
	ssize_t nwrite;

	nwrite = write(1, buffer, sizeof(buffer));
	if (nwrite == -1) {
		return -1;
	}
	return 0;
}
