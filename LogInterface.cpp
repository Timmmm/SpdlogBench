#include "LogInterface.h"

#if defined(VARIANT_A)
	
	#define SPDLOG_FMT_EXTERNAL 1
	#include <spdlog/spdlog.h>
	
	void logit(std::string&& s)
	{
		auto log = spdlog::get("default");
		if (log)
			log->info(s);
	}

#elif defined(VARIANT_B)
	
	#define SPDLOG_FMT_EXTERNAL 1
	#include <spdlog/spdlog.h>

	void logit(std::string&& s)
	{
		auto log = spdlog::get("default");
		if (log)
			log->info(s);
	}

#elif defined(VARIANT_C)
	
	#define SPDLOG_FMT_EXTERNAL 1
	#include <spdlog/spdlog.h>

	void logit(std::string&& s)
	{
		auto log = spdlog::get("default");
		if (log)
			log->info(s);
	}

#elif defined(VARIANT_D)

#elif defined(VARIANT_E)

#else
#error VARIANT_x must be defined.
#endif
