// Sd3.h : main header file for the SD3 application
//

#if !defined(AFX_SD3_H__34A77386_51B8_4CF7_9390_F1D0B9AC8479__INCLUDED_)
#define AFX_SD3_H__34A77386_51B8_4CF7_9390_F1D0B9AC8479__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSd3App:
// See Sd3.cpp for the implementation of this class
//

class CSd3App : public CWinApp
{
public:
	CSd3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSd3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSd3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SD3_H__34A77386_51B8_4CF7_9390_F1D0B9AC8479__INCLUDED_)
