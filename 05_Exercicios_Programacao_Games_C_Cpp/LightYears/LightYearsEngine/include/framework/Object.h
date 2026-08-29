#ifndef OBJECT_H
#define OBJECT_H

#include "framework/Core.h"

namespace ly
{
	class Object
	{
	private:
		bool mIsPendingDestroy;

	public:
		Object();
		virtual ~Object();

		void Destroy();
		bool IsPendingDestroy() const { return mIsPendingDestroy; }
	};
}

#endif