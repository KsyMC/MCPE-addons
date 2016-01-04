#pragma once

#include <functional>

class Listener;
class Event;

typedef std::function<void(Listener *, Event &)> EventExecutor;
