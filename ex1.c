#include <stdio.h>

struct x1 {
	int a;
	char b;
	int c;
	char d;
};

int main() {
	printf("%zu\n", sizeof(struct x1));
	return 0;
}
