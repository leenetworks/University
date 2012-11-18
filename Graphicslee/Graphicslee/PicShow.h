#pragma once


// CPicShow 对话框

class CPicShow : public CDialogEx
{
	DECLARE_DYNAMIC(CPicShow)

public:
	CPicShow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPicShow();

// 对话框数据
	enum { IDD = IDD_PICSHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
