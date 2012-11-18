#pragma once
#include "afxwin.h"  
#include "CWMPPlayer4.h"     //����ͷ�ļ�  
#include "CWMPControls.h"   //����ͷ�ļ�  
#include "CWMPSettings.h"   //����ͷ�ļ�  
#include "CWMPMedia.h"      //ý��ͷ�ļ�  
#include "afxcmn.h" 
#include "ocx1.h"

// CMedPlyDlg �Ի���

class CMedPlyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMedPlyDlg)

public:
	CMedPlyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMedPlyDlg();

// �Ի�������
	enum { IDD = IDD_MEDPLYDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CWMPPlayer4 m_Player;    //���ŵ�ַ����
	CWMPControls m_control;  //���ư�ť����  
    CWMPSettings m_setting;   //���ð�ť����  
    CWMPMedia m_media;  //ý��   
	CProgressCtrl m_progress;

	BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_EVENTSINK_MAP()
	void PlayStateChangeOcx1(long NewState);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
