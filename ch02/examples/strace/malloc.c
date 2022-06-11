#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 4; i++) {
		char* addr = (char*)malloc(1024 * 1024);
	}
	return 0;
}
