#ifndef _CORE_H_
#define _CORE_H_

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dellexplort)
	#else
		#define HAZEL_API __declspec(dellimplort)
	#endif
#else
	#error Hazel only support Windows!
#endif

#endif
