#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <functional>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>
#include <cmath>
#include <typeinfo>
#include <thread>
#include <mutex>
#include <atomic>

#include "raknet/RakNetTypes.h"
#include "raknet/RakPeer.h"
#include "json/json.h"
#include "hook/Substrate.h"
#include "hook/hook.h"
#include "log.h"

using std::string;
using std::vector;
using std::map;
using std::unique_ptr;
using std::shared_ptr;
using std::function;
using std::ofstream;
using std::ifstream;
using std::find;
using std::getline;
using std::stringstream;
using std::move;
using std::bind;
using std::endl;
using std::regex;
using std::regex_match;
using std::min;
using std::mutex;
using std::lock_guard;
using std::atomic;

#define FUNCTION_HOOK_H(ret, name, ...)			\
static ret (*name##_real)(__VA_ARGS__);			\
static ret name(__VA_ARGS__)

#define FUNCTION_HOOK_CPP(ret, cla, name, ...)	\
ret (*cla::name##_real)(__VA_ARGS__);			\
ret cla::name(__VA_ARGS__)
