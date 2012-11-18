#pragma once
#include "afxwin.h"


// CFetchObj 对话框

class CFetchObj : public CDialogEx
{
	DECLARE_DYNAMIC(CFetchObj)

public:
	CFetchObj(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFetchObj();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_npic31;
	CStatic m_npic32;
	afx_msg void OnBnClickedButton1();
};
