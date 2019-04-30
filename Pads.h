#ifndef _PADS_H_
#define _PADS_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

namespace Pads {
	namespace details {
		constexpr uint8_t maxLength = 15;
		static char buffer[maxLength + 1];
	}

	/*---------------------------------LEFT PADS----------------------------------*/

	char * LeftPad(const char * text, uint8_t length, char placeHolder = ' ') {
		if (placeHolder == 0)
			placeHolder = ' ';

		uint8_t strLength = strlen(text);
		// guard
		if (length >= details::maxLength)
			length = details::maxLength;
		if (strLength >= details::maxLength)
			strLength = details::maxLength;
		if (length < strLength)
			length = strLength;

		memset(details::buffer, placeHolder, length - strLength);
		strncpy(details::buffer + (length - strLength), text, strLength);

		details::buffer[length] = '\0';

		return details::buffer;
	}

	inline char * LeftPad(String & text, uint8_t length, char placeHolder = ' ') {
		char strBuff[details::maxLength];
		text.toCharArray(strBuff, details::maxLength + 1);
		return LeftPad(strBuff, length, placeHolder);
	}

	char * LeftPad(const double value, uint8_t length, uint8_t decimalPlaces = 2, char placeHolder = ' ') {
		dtostrf(value, length, decimalPlaces, details::buffer);
		if (placeHolder == 0)
			placeHolder = ' ';
		if (length >= details::maxLength)
			length = details::maxLength;

		for (uint8_t i = 0; i < length; ++i)
			if (details::buffer[i] == ' ')
				details::buffer[i] = placeHolder;

		return details::buffer;
	}

	inline char * LeftPad(const float value, uint8_t length, uint8_t decimalPlaces = 2, char placeHolder = ' ') {
		return LeftPad((double)value, length, decimalPlaces, placeHolder);
	}

	inline char * LeftPad(const unsigned long value, uint8_t length, char placeHolder = ' ') {
		char tempBuffer[details::maxLength + 1];
		sprintf(tempBuffer, "%lu", value);
		return LeftPad(tempBuffer, length, placeHolder);
	}

	inline char * LeftPad(const long value, uint8_t length, char placeHolder = ' ') {
		char tempBuffer[details::maxLength + 1];
		sprintf(tempBuffer, "%ld", value);
		return LeftPad(tempBuffer, length, placeHolder);
	}

	inline char * LeftPad(const unsigned int value, uint8_t length, char placeHolder = ' ') {
		return LeftPad((unsigned long)value, length, placeHolder);
	}

	inline char * LeftPad(const int value, uint8_t length, char placeHolder = ' ') {
		return LeftPad((long)value, length, placeHolder);
	}

	/*---------------------------------RIGHT PADS----------------------------------*/

	char * RightPad(const char * text, uint8_t length, char placeHolder = ' ') {
		if (placeHolder == 0)
			placeHolder = ' ';

		uint8_t strLength = strlen(text);
		// guard
		if (length >= details::maxLength)
			length = details::maxLength;
		if (strLength >= details::maxLength)
			strLength = details::maxLength;
		if (length < strLength)
			length = strLength;

		strncpy(details::buffer, text, strLength);
		memset(details::buffer + strLength, placeHolder, length - strLength);

		details::buffer[length] = '\0';

		return details::buffer;
	}

	inline char * RightPad(String & text, uint8_t length, char placeHolder = ' ') {
		char strBuff[details::maxLength + 1];
		text.toCharArray(strBuff, details::maxLength);
		return RightPad(strBuff, length, placeHolder);
	}

	char * RightPad(const double value, uint8_t length, uint8_t decimalPlaces = 2, char placeHolder = ' ') {
		if (placeHolder == 0)
			placeHolder = ' ';
		if (length >= details::maxLength)
			length = details::maxLength;

		char tempBuffer[details::maxLength + 1];
		dtostrf(value, length, decimalPlaces, tempBuffer);

		uint8_t startIndex = 0;
		for (uint8_t i = 0; i < length; ++i)
			if (tempBuffer[i] == ' ')
				++startIndex;
			else break;

		strncpy(details::buffer, tempBuffer + startIndex, length - startIndex);
		memset(details::buffer + (length - startIndex), placeHolder, startIndex);
		
		details::buffer[length] = '\0';

		return details::buffer;
	}

	inline char * RightPad(const float value, uint8_t length, uint8_t decimalPlaces = 2, char placeHolder = ' ') {
		return RightPad((double)value, length, decimalPlaces, placeHolder);
	}

	inline char * RightPad(const unsigned long value, uint8_t length, char placeHolder = ' ') {
		char tempBuffer[details::maxLength + 1];
		sprintf(tempBuffer, "%lu", value);
		return RightPad(tempBuffer, length, placeHolder);
	}

	inline char * RightPad(const long value, uint8_t length, char placeHolder = ' ') {
		char tempBuffer[details::maxLength + 1];
		sprintf(tempBuffer, "%ld", value);
		return RightPad(tempBuffer, length, placeHolder);
	}

	inline char * RightPad(const unsigned int value, uint8_t length, char placeHolder = ' ') {
		return RightPad((unsigned long)value, length, placeHolder);
	}

	inline char * RightPad(const int value, uint8_t length, char placeHolder = ' ') {
		return RightPad((long)value, length, placeHolder);
	}
}

#endif
