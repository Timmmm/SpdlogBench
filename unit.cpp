
#include "LogInterface.h"

#if defined(VARIANT_A)

static void logSomeStuff1()
{
	logit("{0} {1} {2} {3} {4}");
}
static void logSomeStuff2()
{
	logit("{0}");
}
static void logSomeStuff3()
{
	logit("{0} {1} {2}");
}

#elif defined(VARIANT_B)

static void logSomeStuff1()
{
	logit(fmt::format("{0} {1} {2} {3} {4}", 34.4f, "Hello", 3, 4, 5));
}
static void logSomeStuff2()
{
	logit(fmt::format("{0}", 34.4f));
}
static void logSomeStuff3()
{
	logit(fmt::format("{0} {1} {2}", 34.4f, 4, 5));
}

#elif defined(VARIANT_C)

static void logSomeStuff1()
{
	logit("{0} {1} {2} {3} {4}", 34.4f, "Hello", 3, 4, 5);
}
static void logSomeStuff2()
{
	logit("{0}", 34.4f);
}
static void logSomeStuff3()
{
	logit("{0} {1} {2}", 34.4f, 4, 5);
}

#elif defined(VARIANT_D)

static void logSomeStuff1()
{
	auto log = spdlog::get("default");
	if (log)
		log->info("{0} {1} {2} {3} {4}", 34.4f, "Hello", 3, 4, 5);
}
static void logSomeStuff2()
{
	auto log = spdlog::get("default");
	if (log)
		log->info("{0}", 34.4f);
}
static void logSomeStuff3()
{
	auto log = spdlog::get("default");
	if (log)
		log->info("{0} {1} {2}", 34.4f, 4, 5);
}

#elif defined(VARIANT_E)

static void logSomeStuff1()
{
	auto log = spdlog::get("default");
	if (log)
		log->info("{0} {1} {2} {3} {4}", 34.4f, "Hello", 3, 4, 5);
}
static void logSomeStuff2()
{
	auto log = spdlog::get("default");
	if (log)
		log->info("{0}", 34.4f);
}
static void logSomeStuff3()
{
	auto log = spdlog::get("default");
	if (log)
		log->info("{0} {1} {2}", 34.4f, 4, 5);
}

#else
#error VARIANT_x must be defined.
#endif



