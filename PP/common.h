#pragma once

#include "../winz/app.h"
#include "../winz/Frame.h"
#include "../winz/mdi.h"
#include "../inc/idcres.h"
#include "resource.h"

struct GLOBALS_EX : ZGLOBALS
{
	GLOBALS_EX();
	~GLOBALS_EX();
	HFONT _hDlgFont;
	HWND _hwndTask;
};

#ifdef _WIN64
#define uptoul _wcstoui64
#else
#define uptoul wcstoul
#endif

