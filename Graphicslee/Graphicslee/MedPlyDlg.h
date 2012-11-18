#pragma once
#include "afxwin.h"  
#include "CWMPPlayer4.h"     //播放头文件  
#include "CWMPControls.h"   //控制头文件  
#include "CWMPSettings.h"   //设置头文件  
#include "CWMPMedia.h"      //媒体头文件  
#include "afxcmn.h" 
#include "ocx1.h"

// CMedPlyDlg 对话框

class CMedPlyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMedPlyDlg)

public:
	CMedPlyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMedPlyDlg();

// 对话框数据
	enum { IDD = IDD_MEDPLYDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CWMPPlayer4 m_Player;    //播放地址关联
	CWMPControls m_control;  //控制按钮关联  
    CWMPSettings m_setting;   //设置按钮关联  
    CWMPMedia m_media;  //媒体   
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
