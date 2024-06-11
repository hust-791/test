#pragma once
#include "stdafx.h"

typedef void Func();

struct CallItHelper { template <typename T> CallItHelper(T&& f) { std::forward<T>(f)(); }; };

#define NAME_CAT(name, line) name##line
#define LINENAME(name, line) NAME_CAT(name,line)

#define AutoDoRegisterFunctionBegin static CallItHelper LINENAME(s_textSyle,__LINE__) ([](){

#define AutoRegisterFunctionEnd });

std::map<std::string, Func*> s_Register;

void RegisterFunc(std::string funcName, Func* f)
{
	s_Register[funcName] = f;
}

void Excommond(std::string name)
{
	Func* f = s_Register[name];
	if (f)
	{
		f();
	}
}
