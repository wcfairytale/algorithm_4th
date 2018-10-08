#include "chapter_1.h"

using namespace std;

void init_funcs(FuncMap& funcs)
{
	init_funcs_1(funcs);
}

void proc_func(FuncMap& funcs, FuncID id)
{
	FuncMap::iterator iter = funcs.find(id);

	if (iter == funcs.end())
	{
		return;
	}

	IFunc* pFunc = iter->second;
	pFunc->Proc();
}

int main()
{
	FuncMap funcs;
	
	init_funcs(funcs);

	proc_func(funcs, FUNC_1_1_16);

	return 0;
}