#pragma once
#include "afxwin.h"


// CReverseColorDlg 对话框

class CReverseColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CReverseColorDlg)

public:
	CReverseColorDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CReverseColorDlg();

// 对话框数据

	enum { IDD = IDD_REVERSECOLOR_DIALOG };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CStatic m_npic;
};
