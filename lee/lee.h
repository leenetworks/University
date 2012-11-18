// lee.h : main header file for the LEE application
//

#if !defined(AFX_LEE_H__0BBBD992_5461_46E0_AF5F_ACED779EB015__INCLUDED_)
#define AFX_LEE_H__0BBBD992_5461_46E0_AF5F_ACED779EB015__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLeeApp:
// See lee.cpp for the implementation of this class
//

class CLeeApp : public CWinApp
{
public:
	CLeeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLeeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEE_H__0BBBD992_5461_46E0_AF5F_ACED779EB015__INCLUDED_)
