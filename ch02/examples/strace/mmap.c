#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

int main(void)
{
	struct stat st;
	void* mm;

	fstat(0, &st);
	mm = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
	if (mm == MAP_FAILED) {
		return -1;
	} else if (strcmp(mm, "a\n") != 0) {
		return -2;
	}
	return 0;
}
