// fileRead.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CfileReadApp:
// See fileRead.cpp for the implementation of this class
//

class CfileReadApp :	public CBCGPWinApp
{
public:
	CfileReadApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CfileReadApp theApp;