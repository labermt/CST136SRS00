#include "stdafx.h"
#include "mhdoor.h"


mhdoor::mhdoor()
{
	; //do nothing
}

MHDOOR::MHDOOR(MHDOOR::ContentType ct)
	{
		_content = ct;
	}

MHDOOR::ContentType MHDOOR::show_content() const
{
	return _content;
}

void MHDOOR::setContent(ContentType ct)
{
	_content = ct;
}

