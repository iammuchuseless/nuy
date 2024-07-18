#ifndef OPENAI_HPP_
#define OPENAI_HPP_
#endif


#if OPENAI_VERBOSE_OUTPUT
#pragma message ("OPENAI_VERBOSE_OUTPUT is ON")
#endif

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <mutex>
#include <cstdlib>
#include <map>

#ifndef CURL_STATICLIB
#include <curl/curl.h>
#else 
#include "curl/curl.h"
#endif

#include "nlohmann/json.hpp"  // nlohmann/json