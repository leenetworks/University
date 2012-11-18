// FetchObj.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "FetchObj.h"
#include "afxdialogex.h"


// CFetchObj 对话框

IMPLEMENT_DYNAMIC(CFetchObj, CDialogEx)

CFetchObj::CFetchObj(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFetchObj::IDD, pParent)
{

}

CFetchObj::~CFetchObj()
{
}

void CFetchObj::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC3, m_npic31);
	DDX_Control(pDX, IDC_PIC2, m_npic32);
}


BEGIN_MESSAGE_MAP(CFetchObj, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CFetchObj::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFetchObj 消息处理程序


void CFetchObj::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC* dc = m_npic31.GetDC();
	CDC* m_dc = m_npic32.GetDC();

	CRect m_rect;
	m_npic31.GetClientRect(&m_rect);

	int x,y;

	for (x = 0;x<m_rect.right;x++)
		for (y=0;y<m_rect.bottom;y++)
		{
			COLORREF m_color;
			m_color = dc->GetPixel(x,y);
			if ((m_color ==RGB(255,255,255))||(m_color==RGB(0,0,0))||(m_color == RGB(255,255,30)))
			{
				m_dc->SetPixel(x,y,m_color);
			}
		}

}
