#ifndef MHDOOR_H
#define MHDOOR_H


#include "proxyrandom.h"


class MHDOOR
{
public:
	enum ContentType
	{
		Car = 0,
		GOAT,
	};

private:
	//the content behind this door

	ContentType _content;
public:
	//default constructor
	MHDOOR();

	//constructor
	MHDOOR(ContentType ct);



	ContentType show_content() const;

	//
	void setContent(ContentType ct);

};

class mhdoor
{
public:
	mhdoor();
	~mhdoor();
};

#endif


