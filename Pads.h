#pragma once

namespace Pads {
	namespace {
		constexpr uint8_t bufferSize = 15;
		static char buffer[bufferSize];
	}

	char * LeftPad(const char * text, uint8_t length, char placeHolder = ' ') {
		if (placeHolder == 0)
			placeHolder = ' ';

		uint8_t i = 0;
		uint8_t strLength = strlen(text);
		if (length < strLength)
			length = strLength;

		while (i < length - strLength)
			buffer[i++] = placeHolder;

		while (i < length) {
			buffer[i] = text[i - (length - strLength)];
			++i;
		}
		buffer[i] = '\0';

		return buffer;
	}

	inline char * LeftPad(String & text, uint8_t length, char placeHolder = ' ') {
		char strBuff[bufferSize];
		text.toCharArray(strBuff, bufferSize);
		return LeftPad(strBuff, length, placeHolder);
	}

	char * LeftPad(const double value, uint8_t length, uint8_t decimalPlaces = 2, char placeHolder = ' ') {
		dtostrf(value, length, decimalPlaces, buffer);
		if (placeHolder == 0)
			placeHolder = ' ';

		for (uint8_t i = 0; i < length; ++i)
			if (buffer[i] == ' ')
				buffer[i] = placeHolder;

		return buffer;
	}

	char * RightPad(const char * text, uint8_t length, char placeHolder = ' ') {
		if (placeHolder == 0)
			placeHolder = ' ';

		uint8_t i = 0;
		uint8_t strLength = strlen(text);

		memcpy(buffer, text, strLength);
		for (uint8_t i = strLength; i < length; ++i)
			buffer[i] = placeHolder;

		buffer[length] = '\0';

		return buffer;
	}

	inline char * RightPad(String & text, uint8_t length, char placeHolder = ' ') {
		char strBuff[bufferSize];
		text.toCharArray(strBuff, bufferSize);
		return RightPad(strBuff, length, placeHolder);
	}

	char * RightPad(const double value, uint8_t length, uint8_t decimalPlaces = 2, char placeHolder = ' ') {
		dtostrf(value, 0, decimalPlaces, buffer);
		if (placeHolder == 0)
			placeHolder = ' ';

		uint8_t strLength = strlen(buffer);

		for (uint8_t i = strLength; i < length; ++i)
			buffer[i] = placeHolder;

		buffer[length] = '\0';

		return buffer;
	}
}