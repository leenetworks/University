#pragma once
#include "afxwin.h"


// CFetchColorDlg 对话框

class CFetchColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFetchColorDlg)

public:
	CFetchColorDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFetchColorDlg();

// 对话框数据
	enum { IDD = IDD_FETCHCOLOR_DIALOG };
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_red;
	CEdit m_green;
	CEdit m_blue;
	CEdit m_test;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
