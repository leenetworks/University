#pragma once
#include "afxwin.h"


// CReverseColorDlg �Ի���

class CReverseColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CReverseColorDlg)

public:
	CReverseColorDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReverseColorDlg();

// �Ի�������

	enum { IDD = IDD_REVERSECOLOR_DIALOG };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CStatic m_npic;
};
