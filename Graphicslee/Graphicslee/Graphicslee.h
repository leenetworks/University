// Graphicslee.h : Graphicslee Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGraphicsleeApp:
// �йش����ʵ�֣������ Graphicslee.cpp
//

class CGraphicsleeApp : public CWinApp
{
public:
	CGraphicsleeApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()


};

extern CGraphicsleeApp theApp;