#include <unistd.h>

int main(void)
{
	char buffer[128];
	ssize_t nread;

	nread = read(0, buffer, sizeof(buffer));
	if (nread == -1) {
		return -1;
	}
	return 0;
}

