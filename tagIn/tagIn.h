#ifndef tagIn_h
#define tagIn_h

#include "Arduino.h"

class tagIn
{
	public:
		String tagInAll(String tag, String tagX, bool &tagged);
};

class checkTagged
{
	public:
		void checkTags(String inX, bool &tagged);
};

#endif