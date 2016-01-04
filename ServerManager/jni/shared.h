#pragma once

#define FUNCTION_HOOK_H(ret, name, ...)			\
static ret (*name##_real)(__VA_ARGS__);			\
static ret name(__VA_ARGS__)

#define FUNCTION_HOOK_CPP(ret, cla, name, ...)	\
ret (*cla::name##_real)(__VA_ARGS__);			\
ret cla::name(__VA_ARGS__)
