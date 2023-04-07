#include "Arduino.h"
#include "tagIn.h"

String tagIn::tagInAll(String tag, String tagX, bool &tagged){
	if (tagged) {
		tagged = false;
		if (tag == tagX) {
			return "1";
		} return "0";
	} else {return "1";}
}
