// SettingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "SettingDlg.h"


// CSettingDlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
	, m_nLineWidth(0)
	, m_nLineStyle(-1)
{

}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LINE_WIDTH, m_nLineWidth);
	DDX_Radio(pDX, IDC_RADIO1, m_nLineStyle);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//ON_BN_CLICKED(IDC_RADIO1, &CSettingDlg::OnBnClickedRadio1)
	//ON_BN_CLICKED(IDC_RADIO2, &CSettingDlg::OnBnClickedRadio2)
	//ON_BN_CLICKED(IDC_RADIO3, &CSettingDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CSettingDlg 消息处理程序



