#pragma once


// CPicShow �Ի���

class CPicShow : public CDialogEx
{
	DECLARE_DYNAMIC(CPicShow)

public:
	CPicShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPicShow();

// �Ի�������
	enum { IDD = IDD_PICSHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

protected:
	/*GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;

	TCHAR m_szFile[MAX_PATH];*/
//	CMyMemDC m_dc;
public:
	afx_msg void OnBnClickedOpen();
	afx_msg void OnPaint();
};
