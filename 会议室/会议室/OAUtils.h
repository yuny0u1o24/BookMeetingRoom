#pragma once

#define BOOK_SUCCESS 0
#define MEETING_ROOM_BOOKED 1
#define MEETING_ROOM_NOT_FOUND -1

#define CANCEL_MEETING_SUCCESS 0
#define CANCEL_MEETING_NOT_FOUNT -1
#define CANCEL_MEETING_FAIL 1

class OAUtils
{
public:
	static int inputNumber();
};