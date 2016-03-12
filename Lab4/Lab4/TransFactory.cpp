//------------------------------ TransFactory.cpp -----------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------
#include "TransFactory.h"



TransFactory::TransFactory()
{
}


TransFactory::~TransFactory()
{
}


char TransFactory::getTransType(string newLine)
{
	return newLine[0];
}

bool TransFactory::ValidateData(const char movieType, string newLine)
{
	return false;
}