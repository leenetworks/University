#pragma once
#include "afxwin.h"


// CFetchColorDlg �Ի���

class CFetchColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFetchColorDlg)

public:
	CFetchColorDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFetchColorDlg();

// �Ի�������
	enum { IDD = IDD_FETCHCOLOR_DIALOG };
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_red;
	CEdit m_green;
	CEdit m_blue;
	CEdit m_test;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
