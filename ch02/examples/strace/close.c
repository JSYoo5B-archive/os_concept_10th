#include <unistd.h>

int main(void)
{
	int result;

	result = close(2);
	if (result == -1) {
		return -1;
	}
	return 0;
}
