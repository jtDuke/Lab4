#pragma once
#include "Reader.h"
class movieReader : public Reader
{
public:
	movieReader() {}
	~movieReader() {}
	virtual void validateData() = 0;
};

class classicReader : public movieReader
{
public:
	classicReader()
	{

	}

	~classicReader()
	{

	}
};

class  comedyReader : public movieReader
{
public:
	comedyReader()
	{

	}
	~comedyReader()
	{

	}
};

class dramaReader : public movieReader
{
public:
	dramaReader()
	{

	}
	~dramaReader()
	{

	}
};
