#include <stdio.h>
#include <assert.h>


typedef enum {NEG, ZERO, POS, OTHER} range_t;

/*
	vxorps	%xmm1, %xmm1, %xmm1
	movq	$1, %rax
	movq	$2, %r8
	movq	$0, %r9
	movq	$3, %r10
	vucomiss %xmm1, %xmm0 # x > 0 ?
	cmovaq	%r8, %rax
	cmovbq	%r9, %rax
	cmovpq	%r10,%rax

*/
range_t find_range(float x) {

	int result;
	if (x < 0) {
		result = NEG;
	}
	else if (x == 0) {
		result = ZERO;
	}
	else if (x > 0) {
		result = POS;
	}
	else {
		result = OTHER;
	}
	return (range_t)result;
}

int main(int argc, char* argv[]) {
	range_t n = NEG, z = ZERO, p = POS, o = OTHER;
	assert(o == find_range(0.0 / 0.0));
	assert(n == find_range(-2.3));
	assert(z == find_range(0.0));
	assert(p == find_range(3.33));
	return 0;
}