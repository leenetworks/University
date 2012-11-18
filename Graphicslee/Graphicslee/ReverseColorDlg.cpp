// ReverseColorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "ReverseColorDlg.h"
#include "afxdialogex.h"


// CReverseColorDlg 对话框

IMPLEMENT_DYNAMIC(CReverseColorDlg, CDialogEx)

CReverseColorDlg::CReverseColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CReverseColorDlg::IDD, pParent)
{

}

CReverseColorDlg::~CReverseColorDlg()
{
}

void CReverseColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE, m_npic);
}


BEGIN_MESSAGE_MAP(CReverseColorDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CReverseColorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CReverseColorDlg 消息处理程序


void CReverseColorDlg::OnBnClickedOk()
{
	
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();

	CDC* pDC = m_npic.GetDC();
	CRect m_rect;
	m_npic.GetClientRect(m_rect);
	//FOLLOWED NODE FOR THE FIRST METHOD	
	 
	BYTE r,g,b;
	for (int i=1; i<m_rect.Width();i++)
		for (int j=1;j<m_rect.Height();j++)
		{
			COLORREF clr= pDC->GetPixel(i,j);
			r = GetRValue(clr);
			g = GetGValue(clr);
			b = GetBValue(clr);
			
			r = abs(255-r);
			g = abs(255-g);
			b = abs(255-b);
			pDC->SetPixel(i,j,RGB(r,g,b));
		}
	

}
