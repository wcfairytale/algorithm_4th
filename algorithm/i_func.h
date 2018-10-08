#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

class IFunc;

enum FuncID
{
	FUNC_1_1_1,
	FUNC_1_1_3,
	FUNC_1_1_6,
	FUNC_1_1_7,
	FUNC_1_1_8,
	FUNC_1_1_16,
};

typedef map<FuncID, IFunc*> FuncMap;

class IFunc
{
public:
	virtual void Proc() = 0;
};