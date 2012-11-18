// PicShow.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "PicShow.h"
#include "afxdialogex.h"


// CPicShow 对话框

IMPLEMENT_DYNAMIC(CPicShow, CDialogEx)

CPicShow::CPicShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPicShow::IDD, pParent)
{
//	GdiplusStartup(&m_gdiplusToken,&m_gdiplusStartupInput,NULL);
}

CPicShow::~CPicShow()
{
//	GdiplusShutdown(m_gdiplusToken);
}

void CPicShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPicShow, CDialogEx)
	ON_BN_CLICKED(ID_OPEN, &CPicShow::OnBnClickedOpen)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPicShow 消息处理程序


void CPicShow::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	LPCTSTR lpFilter="*.bmp;*.jpg;*.gif;*.png;*.tiff;|*.bmp;*.jpg;*.gif*.png;*.tiff||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST,lpFilter,this);
	if(dlg.DoModal()==IDOK)
	{
/*		_tcscpy(m_szFile,dlg.GetPathName());

		if(m_dc.GetDC())
			m_dc.DeleteOj();
		m_dc.CreateFromFile(m_szFile);

		Invalidate(FALSE);*/
	}

}


void CPicShow::OnPaint()
{
	if(IsIconic())
	{
	
	}
	else{
/*	    if(m_dc.GetDC())
		{
		    CRect rect;
			GetClientRect(&rect);
			CPaintDC dc(this);
			int nMode=SetStretchBltMode(dc,COLORONCOLOR);
			::StretchBlt(dc,0,0,rect.right,rect.bottom,m_dc,0,0,m_dc.GetWidth(),m_dc.GetHeight(),SRCCOPY);
			SetStretchBltMode(dc,nMode);
		}
		else
			CDialog::OnPaint();*/
	}
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

}
