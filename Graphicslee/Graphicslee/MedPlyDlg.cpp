// MedPlyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "MedPlyDlg.h"
#include "afxdialogex.h"


// CMedPlyDlg 对话框

IMPLEMENT_DYNAMIC(CMedPlyDlg, CDialogEx)

CMedPlyDlg::CMedPlyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMedPlyDlg::IDD, pParent)
{
	
}



BOOL CMedPlyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_control=static_cast<CWMPControls>(m_Player.get_controls());  
    m_setting=m_Player.get_settings();    
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

CMedPlyDlg::~CMedPlyDlg()
{
}

void CMedPlyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_OCX1, m_Player);
}


BEGIN_MESSAGE_MAP(CMedPlyDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CMedPlyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMedPlyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMedPlyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMedPlyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMedPlyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMedPlyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMedPlyDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMedPlyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMedPlyDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CMedPlyDlg 消息处理程序


void CMedPlyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent != 1)    
         return;  
    m_progress.SetPos(m_progress.GetPos()+1);  
	CDialogEx::OnTimer(nIDEvent);
}
BEGIN_EVENTSINK_MAP(CMedPlyDlg, CDialogEx)
	ON_EVENT(CMedPlyDlg, IDC_OCX1, 5101, CMedPlyDlg::PlayStateChangeOcx1, VTS_I4)
END_EVENTSINK_MAP()


void CMedPlyDlg::PlayStateChangeOcx1(long NewState)
{
	// TODO: 在此处添加消息处理程序代码
	if (NewState==3)                //播放状态时, 开启定时器  
        SetTimer(1,1000,NULL);    
    else if (NewState==1)             //停止时, 关闭定时器, 进度条回0  
    {  
        m_progress.SetPos(0);  
        KillTimer(1);  
    }  
    else  
      KillTimer(1);  
}


 //播放
void CMedPlyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 m_control.play(); 
}

//打开
void CMedPlyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	 CString fileName;  
    CFileDialog fileDialog( TRUE,NULL,NULL,OFN_HIDEREADONLY |
		   OFN_OVERWRITEPROMPT,_T("音频、视频文件(*.*)|*.*||"),this);  
    if (fileDialog.DoModal() == IDOK)  
    {  
        fileName=fileDialog.GetPathName();  
        m_Player.put_URL(fileName);   //打开播放  
    }   
    m_media=static_cast<CWMPMedia>(m_Player.newMedia(fileName));  
    m_progress.SetRange(0,(int)m_media.get_duration());  //媒体总长度  
    m_progress.SetPos(0);     
}

//全屏
void CMedPlyDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	 m_Player.put_fullScreen(1);    
}

 //音量增加
void CMedPlyDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_setting.put_volume(m_setting.get_volume()+10);   

}

//音量减少
void CMedPlyDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	 m_setting.put_volume(m_setting.get_volume()-10);     

}

 //暂停
void CMedPlyDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_control.pause();  
}

 //停止
void CMedPlyDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_control.stop();         

}

//快进
void CMedPlyDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_control.fastForward();    
}

//快退
void CMedPlyDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_control.fastReverse();   
}




