#include "../core.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../../json/json.h" // for pretty printing JSON values
#include "../gc/internals.h"

#include "./core-evaluators.c"
#include "./debug-c.c"
#include "./debug-elm.c"
#include "./log.c"

#if PERF_TIMER_ENABLED
#include "./debug-perf.c"
#endif
