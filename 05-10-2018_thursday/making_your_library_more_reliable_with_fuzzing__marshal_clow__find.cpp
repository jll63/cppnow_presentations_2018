#include <algorithm>extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t sz){	if (sz == 0) return 0;	const uint8_t  val = data[0];	const uint8_t *first = data + 1;	const uint8_t *last = data + sz;	const uint8_t *pos = std::find(first, last, val);	if (pos != last)		assert(*pos == val);	for (const uint8_t *p = first; p != pos; ++p)		assert(*p != val);	assert(sz != 63); // bug!	return 0;}