// FetchColorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "FetchColorDlg.h"
#include "afxdialogex.h"


// CFetchColorDlg �Ի���

IMPLEMENT_DYNAMIC(CFetchColorDlg, CDialogEx)

CFetchColorDlg::CFetchColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFetchColorDlg::IDD, pParent)
{

}

CFetchColorDlg::~CFetchColorDlg()
{
}

void CFetchColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_R, m_red);
	DDX_Control(pDX, IDC_EDIT_G, m_green);
	DDX_Control(pDX, IDC_EDIT_B, m_blue);
	DDX_Control(pDX, IDC_TEST, m_test);
}


BEGIN_MESSAGE_MAP(CFetchColorDlg, CDialogEx)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CFetchColorDlg ��Ϣ�������


void CFetchColorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnMouseMove(nFlags, point);

	CWnd* temp = ChildWindowFromPoint(point);
	if (temp)
	{				
		CDC* m_dc = temp->GetDC();
		COLORREF m_color;

		this->MapWindowPoints(temp,&point,1);

		//��ȡ��ɫֵ
		m_color = m_dc->GetPixel(point);

		int r,g,b;
		r = GetRValue(m_color);
		g = GetGValue(m_color);
		b = GetBValue(m_color);
		CString str;

		str.Format("%d",r);
		m_red.SetWindowText(str);

		str.Format("%d",g);
		m_green.SetWindowText(str);

		str.Format("%d",b);
		m_blue.SetWindowText(str);

		CRect m_rect;
		m_test.GetClientRect(m_rect);
		CDC* dc = m_test.GetDC();
		CBrush m_brush(RGB(r,g,b));
		dc->FillRect(m_rect,&m_brush);
	}
}
