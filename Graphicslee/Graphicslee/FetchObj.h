#pragma once
#include "afxwin.h"


// CFetchObj �Ի���

class CFetchObj : public CDialogEx
{
	DECLARE_DYNAMIC(CFetchObj)

public:
	CFetchObj(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFetchObj();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_npic31;
	CStatic m_npic32;
	afx_msg void OnBnClickedButton1();
};
