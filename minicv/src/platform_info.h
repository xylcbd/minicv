#ifndef _PLATFORM_INFO_H_
#define _PLATFORM_INFO_H_

//os
#define PLATFORM_WIN32
#define PLATFORM_LINUX
#define PLATFORM_ANDROID
//compiler
#define COMPILER_MSVC
#define COMPILER_GCC
#define COMPILER_CLANG

#if defined _MSC_VER
#define COMPILER COMPILER_MSVC
#define PLATFORM PLATFORM_WIN32
#elif defined __GNUC__
#define COMPILER COMPILER_GCC
#endif

#ifdef PLATFORM_WIN32
#ifdef EXPORT_DLL
#define API_DESC extern "C" _declspec(dllexport)
#else
#define API_DESC extern "C" _declspec(dllimport)
#endif //EXPORT_DLL
#else
#define API_DESC extern "C"
#endif //PLATFORM_WIN32

#endif //_PLATFORM_INFO_H_