// MedPlyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "MedPlyDlg.h"
#include "afxdialogex.h"


// CMedPlyDlg �Ի���

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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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


// CMedPlyDlg ��Ϣ�������


void CMedPlyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ˴������Ϣ����������
	if (NewState==3)                //����״̬ʱ, ������ʱ��  
        SetTimer(1,1000,NULL);    
    else if (NewState==1)             //ֹͣʱ, �رն�ʱ��, ��������0  
    {  
        m_progress.SetPos(0);  
        KillTimer(1);  
    }  
    else  
      KillTimer(1);  
}


 //����
void CMedPlyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 m_control.play(); 
}

//��
void CMedPlyDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 CString fileName;  
    CFileDialog fileDialog( TRUE,NULL,NULL,OFN_HIDEREADONLY |
		   OFN_OVERWRITEPROMPT,_T("��Ƶ����Ƶ�ļ�(*.*)|*.*||"),this);  
    if (fileDialog.DoModal() == IDOK)  
    {  
        fileName=fileDialog.GetPathName();  
        m_Player.put_URL(fileName);   //�򿪲���  
    }   
    m_media=static_cast<CWMPMedia>(m_Player.newMedia(fileName));  
    m_progress.SetRange(0,(int)m_media.get_duration());  //ý���ܳ���  
    m_progress.SetPos(0);     
}

//ȫ��
void CMedPlyDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 m_Player.put_fullScreen(1);    
}

 //��������
void CMedPlyDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_setting.put_volume(m_setting.get_volume()+10);   

}

//��������
void CMedPlyDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 m_setting.put_volume(m_setting.get_volume()-10);     

}

 //��ͣ
void CMedPlyDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_control.pause();  
}

 //ֹͣ
void CMedPlyDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_control.stop();         

}

//���
void CMedPlyDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_control.fastForward();    
}

//����
void CMedPlyDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_control.fastReverse();   
}




