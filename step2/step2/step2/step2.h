
// step2.h : main header file for the step2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cstep2App:
// See step2.cpp for the implementation of this class
//

class Cstep2App : public CWinApp
{
public:
	Cstep2App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cstep2App theApp;
