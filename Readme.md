# Spdlog Benchmark

This is a simple repository to benchmark *compilation* of [spdlog](https://github.com/gabime/spdlog). Although it is a very cool library, it is entirely header-based which makes compilation quite slow. I wanted to know how slow.

This repo copies a simple C++ file, `unit.cpp` 100 times, and compiles them all using [Ninja](https://ninja-build.org/). Ninja is pretty fast (though not as fast as [QBS](http://doc.qt.io/qbs/)) so it should be insignificant in the build time. Ninja is configured using [Meson](http://mesonbuild.com/) which is basically "CMake done right". I probably wouldn't recommend you use Meson in production as of now though - it still has basic change detection and parser bugs for example, but in this case it works fine (although file globbing would have been *really* useful in this case - they don't support it for reasons I don't entirely agree with).

Anyway, this benchmark tests the following five Spdlog usage scenarios:

## Scenarios

### A: Plain Function

This is a plain function that just takes a `std::string`. It only uses Spdlog internally. This should be the fastest case.

	#include <string>
	void logit(std::string&& s);

### B: Plain Function Plus Fmt

Spdlog uses the [fmt](https://github.com/fmtlib/fmt) library internally. This case is the same as above but we include the Fmt header for convenience.

	#include <fmt/format.h>
	void logit(std::string&& s);

### C: Template Function Using Fmt

This case is as above but we provide a convinience template function for logging that allows you to format without explicitly using Fmt This should compile at a similar speed to B but is significantly more convenient to actually use.

	#include <fmt/format.h>
	void logit(std::string&& s);
	
	template <typename... Args>
	void logit(const char* s, const Args&... args)
	{
		logit(fmt::format(s, args...));
	}

### D: Basic Spdlog

Here we just use Spdlog as intended, by including its header (which internally uses its own header-only copy of Fmt). This is the slowest method.

	#include <spdlog/spdlog.h>

### E: Spdlog with External Fmt

Spdlog helpfully provides an option to use our own copy of Fmt, which we can make non-header-only, so it should be slightly faster than D.

	#define SPDLOG_FMT_EXTERNAL 1
	#include <spdlog/spdlog.h>

## Running

Just run `./benchmark.sh` on Linux or Mac and it should print out some `time` results (in order from A to E). These are the results on my laptop (very high end MacBook Pro):

	A
	real    0m5.403s
	user    0m27.527s
	sys     0m3.558s
	
	B
	real    0m9.138s
	user    0m47.499s
	sys     0m4.686s
	
	C
	real    0m9.946s
	user    0m48.817s
	sys     0m4.882s
	
	D
	real    0m41.674s
	user    3m48.771s
	sys     0m13.925s
	
	E
	real    0m38.772s
	user    3m32.701s
	sys     0m13.462s

Spdlog adds almost exactly 2 seconds of user time per C++ file, compared to the plain function case (A). This is quite a lot, so I am going to use (C) in my code which seems like a decent compromise between usefulness and compilation time.
