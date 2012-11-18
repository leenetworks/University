// GraphicsleeView.cpp : CGraphicsleeView ���ʵ��
//

#include "stdafx.h"
#include "Graphicslee.h"

#include "GraphicsleeDoc.h"
#include "GraphicsleeView.h"

#include "SettingDlg.h"
#include"FetchColorDlg.h"
#include"ReverseColorDlg.h"
#include"FetchObj.h"
#include"MedPlyDlg.h"
#include"windows.h"
#include"gdiplus.h"
//#include "String.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsleeView

IMPLEMENT_DYNCREATE(CGraphicsleeView, CView)

BEGIN_MESSAGE_MAP(CGraphicsleeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DOT, &CGraphicsleeView::OnDot)
	ON_COMMAND(IDM_LINE, &CGraphicsleeView::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CGraphicsleeView::OnRectangle)
	//ON_COMMAND(IDM_ELLIPSE, &CGraphicsleeView::OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SETTING, &CGraphicsleeView::OnSetting)
	ON_COMMAND(IDM_COLOR, &CGraphicsleeView::OnColor)
	ON_COMMAND(IDM_FONT, &CGraphicsleeView::OnFont)
	ON_COMMAND(IDM_GRADUAL, &CGraphicsleeView::OnGradual)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_MULTCOLOR, &CGraphicsleeView::OnMultcolor)
	ON_COMMAND(IDM_MCOLORL, &CGraphicsleeView::OnMcolorl)
	ON_WM_CHAR()
	ON_WM_CREATE()
	
	ON_WM_TIMER()
	
	ON_COMMAND(IDM_EMPTYFONT, &CGraphicsleeView::OnEmptyfont)
	ON_COMMAND(IDM_SPARINFONT, &CGraphicsleeView::OnSparinfont)
	ON_COMMAND(IDM_GRANDUALFONT, &CGraphicsleeView::OnGrandualfont)
	ON_COMMAND(IDC_FETCHCOLOR, &CGraphicsleeView::OnFetchcolor)
	ON_COMMAND(IDC_REVERSECOLOR, &CGraphicsleeView::OnReversecolor)
	ON_COMMAND(IDC_FETCHOBJ, &CGraphicsleeView::OnFetchobj)
	ON_COMMAND(ID_LOOK, &CGraphicsleeView::OnLook)
	ON_COMMAND(ID_MIN, &CGraphicsleeView::OnMin)
	ON_COMMAND(ID_MAX, &CGraphicsleeView::OnMax)
	ON_COMMAND(ID_FULL, &CGraphicsleeView::OnFull)
	ON_COMMAND(ID_SPRIN, &CGraphicsleeView::OnSprin)
	ON_COMMAND(ID_SRC, &CGraphicsleeView::OnSrc)
	ON_COMMAND(ID_MedPly, &CGraphicsleeView::OnMedply)
	ON_COMMAND(ID_SNAP, &CGraphicsleeView::OnSnap)
	ON_COMMAND(UDM_ELLIPSE, &CGraphicsleeView::OnEllipse)
END_MESSAGE_MAP()

// CGraphicsleeView ����/����

CGraphicsleeView::CGraphicsleeView()
{
	// TODO: �ڴ˴���ӹ������
    m_nDrawType=0;
	m_ptOrigin=0;
	m_nLineWidth=0;
	m_nLineStyle=0;
	m_clr=RGB(255,0,0);
    m_strFontName="";
	m_bDraw=FALSE;
	m_bColor=FALSE;
	m_strLine="";
	m_nRed=215;
	m_nGreen=123;
	m_nBlue=51;
	ilook=0;
}

CGraphicsleeView::~CGraphicsleeView()
{
}

BOOL CGraphicsleeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGraphicsleeView ����

void CGraphicsleeView::OnDraw(CDC* pDC)
{
	CGraphicsleeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect r;
	GetClientRect(&r);
	long scrW,scrH,desW=0.0,desH=0.0;
	
	scrW=BMap.bmWidth;	//��λͼ��Ϣ�õ�λͼ��С
	scrH=BMap.bmHeight;

	switch (m_bmZoom)		//ȷ��Ŀ��λͼ��С
	{
	case ZOOMFIT:
		desW=r.Width();
		desH=r.Height();
		break;
	case ZOOMSCR:
		desW=scrW;
		desH=scrH;
		break;
	case ZOOMOUT:
		desW=scrW*2;
		desH=scrH*2;
		break;
	case ZOOMIN:
		desW=(long)(scrW/2);
		desH=(long)(scrH/2);
		break;
	default:
		break;

	}
	
	CSize sizeTotal;
	sizeTotal.cx = desW;
	sizeTotal.cy = desH;
	//SetScrollSizes(MM_TEXT, sizeTotal);//�������ù�����������
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);		//������pDC���ݵ��豸������
	dcMem.SelectObject(&bitmap);		//��λͼ����ѡ���豸������
//	::SetBrushOrgEx(*pDC,0,0,NULL);
	pDC->SetStretchBltMode(HALFTONE);	//����λͼ
	//��Դ�豸�����Ŀ���λͼ��Ŀ���豸������
	pDC->StretchBlt(0,0,desW,desH,&dcMem,0,0,scrW,scrH,SRCCOPY);
	
}


// CGraphicsleeView ��ӡ

BOOL CGraphicsleeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGraphicsleeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGraphicsleeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CGraphicsleeView ���

#ifdef _DEBUG
void CGraphicsleeView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicsleeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicsleeDoc* CGraphicsleeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsleeDoc)));
	return (CGraphicsleeDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsleeView ��Ϣ�������

void CGraphicsleeView::OnDot()
{
	// TODO: �ڴ���������������
	m_nDrawType=1;
}

void CGraphicsleeView::OnLine()
{
	// TODO: �ڴ���������������
	m_nDrawType=2;
}

void CGraphicsleeView::OnRectangle()
{
	// TODO: �ڴ���������������
	m_nDrawType=3;
}

void CGraphicsleeView::OnEllipse()
{
	// TODO: �ڴ���������������
	m_nDrawType=4;
}

void CGraphicsleeView::OnGradual()
{
	// TODO: �ڴ���������������
	m_nDrawType=5;
}


void CGraphicsleeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
        m_ptOrigin=point;
		m_bDraw=TRUE;
		SetCaretPos(point);
		m_strLine.Empty();
		m_ptOrigin=point;
}

void CGraphicsleeView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	    m_bDraw=FALSE;
        CClientDC dc(this);
	CPen pen(m_nLineStyle,m_nLineWidth,m_clr);
	dc.SelectObject(pen);
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);
	switch(m_nDrawType){
		case 1:
			dc.SetPixel(point,m_clr);
			break;
		case 2: 
			dc.MoveTo(m_ptOrigin);
			dc.LineTo(point);
			break;
		case 3: 
			dc.Rectangle(CRect(m_ptOrigin,point));		
            break;
		case 4:
			dc.Ellipse(CRect(m_ptOrigin,point));
			break;
	}
			
	CView::OnLButtonUp(nFlags, point);
}

void CGraphicsleeView::OnSetting()
{
	// TODO: �ڴ���������������
	CSettingDlg dlg;
	dlg.m_nLineWidth=m_nLineWidth;
	dlg.m_nLineStyle=m_nLineStyle;
	if(IDOK==dlg.DoModal())
	{
		m_nLineWidth=dlg.m_nLineWidth;
		m_nLineStyle=dlg.m_nLineStyle;
	}
	
	
}

void CGraphicsleeView::OnColor()
{
	// TODO: �ڴ���������������
	CColorDialog dlg;
    dlg.m_cc.Flags|=CC_RGBINIT|CC_FULLOPEN;
    dlg.m_cc.rgbResult=m_clr;
    if(IDOK==dlg.DoModal())
	{
        m_clr=dlg.m_cc.rgbResult;
	}
}

void CGraphicsleeView::OnFont()
{
	// TODO: �ڴ���������������
	CFontDialog dlg;
	if(IDOK==dlg.DoModal())
	{
		if(m_font.m_hObject)
			m_font.DeleteObject();
		m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
		m_strFontName=dlg.m_cf.lpLogFont->lfFaceName;
		Invalidate();
	}
}


void CGraphicsleeView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CClientDC dc(this);
	CPen pen(m_nLineStyle,m_nLineWidth,m_clr);
	dc.SelectObject(pen);
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);
	if(m_bDraw==TRUE&&m_nDrawType==5)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOrigin=point;
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CGraphicsleeView::OnMultcolor()
{
	// TODO: �ڴ���������������
	CClientDC dcc(this);
	CRect rc;
	this->GetWindowRect(rc);
	int y=rc.Height()/4;
	CPen pen,*oldpen;
	oldpen=dcc.SelectObject(&pen);

	dcc.MoveTo(0,y);
	dcc.LineTo(0,y);
	for(int i=1;i<255;i++)
	{
		pen.DeleteObject();
		pen.CreatePen(PS_SOLID,2,RGB(255,i,0));
		dcc.SelectObject(&pen);
		dcc.LineTo(i,y);
	}
}

void CGraphicsleeView::OnMcolorl()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	CBrush br,*oldbr;
	oldbr=dc.SelectObject(&br);
	for(int m=255;m>0;m--)
	{
		int r=(200*m)/255;
		br.DeleteObject();
		br.CreateSolidBrush(RGB(255,m,0));
		dc.FillRect(CRect(0,0,r,r),&br);
	}

}

void CGraphicsleeView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);//�����豸������
	dc.SetBkMode(TRANSPARENT);
	CFont font;
	font.CreatePointFont(300,"�����п�",NULL);
	CFont *pOldFont=dc.SelectObject(&font);
	TEXTMETRIC tm;//�����ı���Ϣ�ṹ�����
	dc.GetTextMetrics(&tm);//�������������е��ı���Ϣ
	if(0x0d==nChar)
	{
		m_strLine.Empty();
		m_ptOrigin.y+=tm.tmHeight;

	}
	else if(0x08==nChar)
	{
		COLORREF clr=dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin.x,m_ptOrigin.y,m_strLine);
		m_strLine=m_strLine.Left(m_strLine.GetLength()-1);
		dc.SetTextColor(clr);
	}
	else
	{
		m_strLine=m_strLine+(char)nChar;	
	}
    dc.TextOut(m_ptOrigin.x,m_ptOrigin.y,m_strLine);
	dc.SelectObject(pOldFont);
	CSize sz=dc.GetTextExtent(m_strLine);
    CPoint pt;
	pt.x=(m_ptOrigin.x+sz.cx)*2;
    pt.y=m_ptOrigin.y;
	SetCaretPos(pt);
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

int CGraphicsleeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CClientDC dc(this);//�����豸������
	TEXTMETRIC tm;//�����ı���Ϣ�ṹ�����
	dc.GetTextMetrics(&tm);//�������������е��ı���Ϣ
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);//���������
	ShowCaret();//��ʾ�����


	return 0;
}

void CGraphicsleeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(m_nRed<=205)
		m_nRed+=50;
	else if(m_nRed==255)
		m_nRed=0;
	else 
		m_nRed=255;
	if(m_nGreen<=205)
		m_nGreen+=50;
	else if(m_nGreen==255)
		m_nGreen=0;
	else 
		m_nGreen=255;
	if(m_nBlue<=205)
		m_nBlue+=50;
	else if(m_nBlue==255)
		m_nBlue=0;
	else 
		m_nBlue=255;
    Invalidate();
	
	CView::OnTimer(nIDEvent);
}


void CGraphicsleeView::OnEmptyfont()
{
	// TODO: �ڴ���������������
	//��������
	CClientDC pDC(this);//�����豸������
	CFont mFont;//����һ���������
	VERIFY(mFont.CreateFont(150,50,0,0,FW_HEAVY,TRUE,FALSE,0,ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"����"));

	CPen pen(PS_SOLID,2,RGB(0,255,0));//����һ������
	pDC.SelectObject(&pen);//ѡ�л���
	pDC.BeginPath();//��ʼһ��·��
	CFont *pOldFont=pDC.SelectObject(&mFont);//ѡ�д���������
	pDC.SetBkMode(TRANSPARENT);//���û����ı���ģʽΪ͸��
	pDC.TextOut(30,30,"�ı�������");
	pDC.EndPath();
	pDC.StrokePath();//�õ�ǰ�Ļ��ʻ���·��
	mFont.DeleteObject();//�ͷ������������
	pDC.SelectObject(pOldFont);//�ָ�֮ǰ���������
	//
}

void CGraphicsleeView::OnSparinfont()
{
	// TODO: �ڴ���������������
	//�����ת
	CClientDC pDC(this);//�����豸������
	CFont m_Font;//����һ���������
	pDC.SetBkMode(TRANSPARENT);
	CRect m_rect;
	GetClientRect(m_rect);
	pDC.FillRect(m_rect,NULL);
	pDC.SetViewportOrg(m_rect.Width()/2,m_rect.Height()/2);
	for(int i=0;i<360;i+=18)
	{
		m_Font.CreateFont(-14,-10,i*10,0,600,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,                                  DEFAULT_QUALITY,FF_ROMAN,"����");
		pDC.SelectObject(&m_Font);
		pDC.SetTextColor(RGB(255-i,i*250,i+50));
		pDC.TextOut(0,0,"�����ѧԺ��ý����");
		m_Font.DeleteObject();
	}
}

void CGraphicsleeView::OnGrandualfont()
{
	// TODO: �ڴ���������������
	CClientDC pDC(this);//�����豸������
	pDC.SetBkMode(TRANSPARENT);
	CFont font;
	font.CreateFont(150,50,0,0,FW_HEAVY,TRUE,FALSE,0,ANSI_CHARSET,OUT_CHARACTER_PRECIS,
	                CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"����");
	CFont* pOldFont=pDC.SelectObject(&font);
	for(int i=0;i<255;i++)
	{
        pDC.SetTextColor(RGB(255,i,0));
	    pDC.TextOut(100,100,"������ɫ����");
		
	}	
	pDC.SelectObject(pOldFont);
	
}




void CGraphicsleeView::OnFetchcolor()
{
	// TODO: �ڴ���������������
	CFetchColorDlg dlg;
	dlg.DoModal();
}


void CGraphicsleeView::OnReversecolor()
{
	// TODO: �ڴ���������������
	CReverseColorDlg dlg;
	dlg.DoModal();
}


void CGraphicsleeView::OnFetchobj()
{
	// TODO: �ڴ���������������
	CFetchObj dlg;
	dlg.DoModal();

}

BOOL CGraphicsleeView::GetBmp(LPCTSTR lpszSourceName,CBitmap &bitmap)
{	
	HBITMAP hbmp=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),lpszSourceName,
		IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	if(hbmp==NULL)
		return FALSE;

	bitmap.Detach();			//����λͼ����
	bitmap.Attach(hbmp);
	
	bitmap.GetBitmap(&BMap);//�������λͼ��bitmap��������
	return TRUE;

	/*LoadImage�����﷨˵��
	  HANDLE LoadImage(HINSTANCE hinst,LPCTSTR lpszName,UINT uType,int cx Desired,int cyDesired,UINT fuLoad);
	����˵����
	  hinst :��ʾ����ͼ���ʵ�����������ΪNULL
	  lpszName:��ʾͼ�����Դ���ƣ�����Ӵ����м��أ��ò�����ʾͼ������ƣ���������·��
	  uType:��ʾ���ص�ͼ�����ͣ�ΪIMAGE_BITMAP,��ʾ����λͼ��ΪIMAGE_CURSOR,��ʾ�������ָ�룬ΪIMAGE_ICON����ʾ����ͼ��
	  cxDesired:��ʾͼ������Ŀ�ȣ�������ص���λͼ����ò�������Ϊ0
	  cyDesired:��ʾͼ������ĸ߶ȣ�������ص���λͼ����ò�������Ϊ0
	  fuLoad:��ʾ�������ͣ����ΪLR_LOADFROMFILE,��ʾ�Ӵ����ļ��м���λͼ
	����ֵ���������ؼ��ص�ͼ����Դ���
	*/

}


void CGraphicsleeView::OnLook()
{
	// TODO: �ڴ���������������
	
	CString FilePathname;
	CFileDialog dlg(TRUE,_T("bmp"),_T("*.bmp"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("λͼ�ļ�(*.bmp)|*.bmp|"));
	if(dlg.DoModal())
	{
		FilePathname=dlg.GetPathName();
		if(FilePathname!="*.bmp")	//�ж��Ƿ��ڴ��ļ��Ի�����ѡ��ȡ��
		{
			if(!GetBmp(FilePathname,bitmap) )	//
			{
				MessageBox("���ļ�ʧ��!","��ʾ",MB_ICONHAND|MB_OK);
			}
			else
			{
				m_bFileOpen=true;
				m_bmZoom=ZOOMSCR;
				Invalidate();
			}
		}
	}
	/*
	CFileDialog���캯���﷨˵����
	  CFileDialog(BOOL bOpenFileDialog,LPCTSTR lpszDefExt =NULL,LPCTSTR lpszFileName =NULL,
	            DWORD dwFlags =OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,LPCTSTR lpszFilter =NULL,
				CWnd* pParentWnd =NULL);
	����˵����
	  bOpenFileDialog��ΪTRUE����ʾ�ļ��򿪶Ի���ΪFALSE����ʾ�ļ�����Ի���
	  lpszDefExt��ָ���ļ���չ�������û����ļ����༭����û��������չ������ϵͳ���ļ������Զ����lpszDefExtָ������չ��
	  lpszFileName�����ļ����༭����ָ����ʼ���ֵ��ļ�������ΪNULL���򲻳���
	  dwFlags��ָ���Ի���Ľ����־��ΪOFN_HIDEREADONLYʱ����ʾ���ضԻ����еġ�ֻ������ѡ��
	           ΪOFN_OVERWRITEPROMPTʱ����ʾ�ļ�����ʱ������ָ�����ļ����������������ʾ�Ի���
      lpszFilter������ȷ���������ļ��б��е��ļ����͡�����һ�Ի����ַ�����ɣ�ÿ���ַ����е�һ���ַ�����ʾ���������ƣ�
	              �ڶ����ַ�����ʾ�ļ���չ������ָ�������չ�������á������ָ����ַ�������á�||����β
      pParentWnd��ָ���Ի���ĸ�����ָ��
	  LPCTSTR����������ʾһ����ֵ�ַ�ָ�룬�������������һ����ֵ�ַ�������
	*/


	/*
	MFC��6��ͨ�öԻ����� ��CColorDialog����ɫ�Ի��������û�ѡ��򴴽���ɫ
	                      CFiledialog���ļ��Ի��������û��򿪻򱣴�һ���ļ�
						  CFindRepalceDialog:�����滻�Ի��������û�ָ�������ָ���ַ���
						  CPageSetupDialog:ҳ�����öԻ��������û�����ҳ�����
						  CFontDialog:����Ի��������û����г��Ŀ���������ѡ��һ������
						  CPrintDialog:��ӡ�Ի��������û����ô�ӡ���ļ���Ӧ�ĵ�
	��Щͨ�öԻ���ɹ��û��ڳ�����ֱ��ʹ�á������Ƕ���һ����ͬ�ص㣺���Ƕ����û���ȡ��Ϣ������������Ϣ������
	*/
	
}



void CGraphicsleeView::OnMin()
{
	// TODO: �ڴ���������������
	m_bmZoom=ZOOMIN;
	Invalidate();
}


void CGraphicsleeView::OnMax()
{
	// TODO: �ڴ���������������
	m_bmZoom=ZOOMOUT;
	Invalidate();
}


void CGraphicsleeView::OnFull()
{
	// TODO: �ڴ���������������
	m_bmZoom=ZOOMFIT;
	Invalidate();
}


void CGraphicsleeView::OnSprin()
{
	// TODO: �ڴ���������������
}


void CGraphicsleeView::OnSrc()
{
	// TODO: �ڴ���������������
	m_bmZoom=ZOOMSCR;
	Invalidate();
}




void CGraphicsleeView::OnMedply()
{
	// TODO: �ڴ���������������
	CMedPlyDlg dlg;
	dlg.DoModal();
}


void CGraphicsleeView::OnSnap()
{
	// TODO: �ڴ���������������
/*	GdiplusStartup(&m_gdiplusToken,&m_gdiplusStartupInput,NULL);
	{
	    HWND hDesk=GetDesktopWindow();
		RECT RC={0};
		GetWindowRect(hDesk,&rc);

	}
*/
}

