#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {
	int i;
	struct stat s;

	for (i=1; i<argc; i++) {
		if (stat(argv[i], &s)) {
			fprintf(stderr, "stat %s: ", argv[i]);
			perror("");
			errno = 0;
		} else {
			printf("%11lu %s\n", s.st_mtime, argv[i]);
		}
	}

	return 0;
}
