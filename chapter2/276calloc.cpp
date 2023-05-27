#include <stdio.h>

void* malloc(size_t size);

void* memset(void* s, int c, size_t n);

void* calloc(size_t nmemb, size_t size) {
	if (nmemb == 0 || size == 0) {
		return NULL;
	}
	size_t buf_size = nmemb * size;
	if (nmemb == buf_size / size) {
		void * ptr = malloc(buf_size);
		if (ptr != NULL) {
			memset(ptr, 0, buf_size);
		}
		return ptr;
	}
	return NULL;
}