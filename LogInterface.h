#pragma once

// Variants to time:

// Without spdlog:

// A) The simplest case - a plain function that takes a std::string. (The unit*.cpp files do not do any formatting in this case.)
// B) Same as (A) but #include the `fmt` header for convenience.
// C) Same as (B) but add a template function that makes use of `fmt`.

// With spdlog:

// D) Just #include <spdlog/spdlog.h> and use it normally.
// E) Same as (D) but with SPDLOG_FMT_EXTERNAL which means we use our own copy of fmt and not spdlog's internal header-only copy.

#if defined(VARIANT_A)
	
	#include <string>
	void logit(std::string&& s);

#elif defined(VARIANT_B)
	
	#include <fmt/format.h>
	void logit(std::string&& s);

#elif defined(VARIANT_C)
	
	#include <fmt/format.h>
	void logit(std::string&& s);
	
	template <typename... Args>
	void logit(const char* s, const Args&... args)
	{
		logit(fmt::format(s, args...));
	}
	
#elif defined(VARIANT_D)
	
	#include <spdlog/spdlog.h>

#elif defined(VARIANT_E)
	
	#define SPDLOG_FMT_EXTERNAL 1
	#include <spdlog/spdlog.h>

#else
#error VARIANT_x must be defined.
#endif

