// Graphicslee.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Graphicslee.h"
#include "MainFrm.h"
#include"Splash1.h"
#include "GraphicsleeDoc.h"
#include "GraphicsleeView.h"
#include "CWMPPlayer4.h"
#include "CWMPCdromCollection.h"
#include "CWMPClosedCaption.h"
#include "CWMPClosedCaption2.h"
#include "CWMPControls.h"
#include "CWMPControls2.h"
#include "CWMPControls3.h"
#include "CWMPDVD.h"
#include "CWMPError.h"
#include "CWMPErrorItem.h"
#include "CWMPErrorItem2.h"
#include "CWMPMedia.h"
#include "CWMPMedia2.h"
#include "CWMPMedia3.h"
#include "CWMPMediaCollection.h"
#include "CWMPMetadataPicture.h"
#include "CWMPMetadataText.h"
#include "CWMPPlayer.h"
#include "CWMPPlayer2.h"
#include "CWMPPlayer3.h"
#include "CWMPPlaylist.h"
#include "CWMPPlaylistCollection.h"
#include "CWMPSettings.h"
#include "CWMPSettings2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

ULONG_PTR m_gdiplusToken;
// CGraphicsleeApp

BEGIN_MESSAGE_MAP(CGraphicsleeApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CGraphicsleeApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CGraphicsleeApp ����

CGraphicsleeApp::CGraphicsleeApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGraphicsleeApp ����

CGraphicsleeApp theApp;


// CGraphicsleeApp ��ʼ��

BOOL CGraphicsleeApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)
	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CGraphicsleeDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CGraphicsleeView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);


	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����

	//Gdiplus::GdiplusStartupInput m_gdiplusStartup;
	//GdiplusStartup(&m_gdiplusToken,&m_gdiplusStartup,NULL);

	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CGraphicsleeApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CGraphicsleeApp ��Ϣ�������

