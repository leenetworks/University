// GraphicsleeView.cpp : CGraphicsleeView 类的实现
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
	// 标准打印命令
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

// CGraphicsleeView 构造/析构

CGraphicsleeView::CGraphicsleeView()
{
	// TODO: 在此处添加构造代码
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGraphicsleeView 绘制

void CGraphicsleeView::OnDraw(CDC* pDC)
{
	CGraphicsleeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	CRect r;
	GetClientRect(&r);
	long scrW,scrH,desW=0.0,desH=0.0;
	
	scrW=BMap.bmWidth;	//从位图信息得到位图大小
	scrH=BMap.bmHeight;

	switch (m_bmZoom)		//确定目标位图大小
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
	//SetScrollSizes(MM_TEXT, sizeTotal);//重新设置滚动窗口下限
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);		//创建与pDC兼容的设备上下文
	dcMem.SelectObject(&bitmap);		//将位图对象选入设备上下文
//	::SetBrushOrgEx(*pDC,0,0,NULL);
	pDC->SetStretchBltMode(HALFTONE);	//设置位图
	//从源设备上下文拷贝位图到目标设备上下文
	pDC->StretchBlt(0,0,desW,desH,&dcMem,0,0,scrW,scrH,SRCCOPY);
	
}


// CGraphicsleeView 打印

BOOL CGraphicsleeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGraphicsleeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGraphicsleeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CGraphicsleeView 诊断

#ifdef _DEBUG
void CGraphicsleeView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicsleeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicsleeDoc* CGraphicsleeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsleeDoc)));
	return (CGraphicsleeDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsleeView 消息处理程序

void CGraphicsleeView::OnDot()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=1;
}

void CGraphicsleeView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=2;
}

void CGraphicsleeView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=3;
}

void CGraphicsleeView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=4;
}

void CGraphicsleeView::OnGradual()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=5;
}


void CGraphicsleeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
        m_ptOrigin=point;
		m_bDraw=TRUE;
		SetCaretPos(point);
		m_strLine.Empty();
		m_ptOrigin=point;
}

void CGraphicsleeView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);//创建设备描述表
	dc.SetBkMode(TRANSPARENT);
	CFont font;
	font.CreatePointFont(300,"华文行楷",NULL);
	CFont *pOldFont=dc.SelectObject(&font);
	TEXTMETRIC tm;//定义文本信息结构体变量
	dc.GetTextMetrics(&tm);//获得设别描述表中的文本信息
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

	// TODO:  在此添加您专用的创建代码
	CClientDC dc(this);//创建设备描述表
	TEXTMETRIC tm;//定义文本信息结构体变量
	dc.GetTextMetrics(&tm);//获得设别描述表中的文本信息
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);//创建插入符
	ShowCaret();//显示插入符


	return 0;
}

void CGraphicsleeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加命令处理程序代码
	//空心文字
	CClientDC pDC(this);//创建设备描述表
	CFont mFont;//定义一个字体对象
	VERIFY(mFont.CreateFont(150,50,0,0,FW_HEAVY,TRUE,FALSE,0,ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"宋体"));

	CPen pen(PS_SOLID,2,RGB(0,255,0));//定义一个画笔
	pDC.SelectObject(&pen);//选中画笔
	pDC.BeginPath();//开始一个路径
	CFont *pOldFont=pDC.SelectObject(&mFont);//选中创建的字体
	pDC.SetBkMode(TRANSPARENT);//设置画布的背景模式为透明
	pDC.TextOut(30,30,"文本处理编程");
	pDC.EndPath();
	pDC.StrokePath();//用当前的画笔绘制路径
	mFont.DeleteObject();//释放上述字体对象
	pDC.SelectObject(pOldFont);//恢复之前的字体对象
	//
}

void CGraphicsleeView::OnSparinfont()
{
	// TODO: 在此添加命令处理程序代码
	//多彩旋转
	CClientDC pDC(this);//创建设备描述表
	CFont m_Font;//定义一个字体对象
	pDC.SetBkMode(TRANSPARENT);
	CRect m_rect;
	GetClientRect(m_rect);
	pDC.FillRect(m_rect,NULL);
	pDC.SetViewportOrg(m_rect.Width()/2,m_rect.Height()/2);
	for(int i=0;i<360;i+=18)
	{
		m_Font.CreateFont(-14,-10,i*10,0,600,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,                                  DEFAULT_QUALITY,FF_ROMAN,"宋体");
		pDC.SelectObject(&m_Font);
		pDC.SetTextColor(RGB(255-i,i*250,i+50));
		pDC.TextOut(0,0,"计算机学院多媒体编程");
		m_Font.DeleteObject();
	}
}

void CGraphicsleeView::OnGrandualfont()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC pDC(this);//创建设备描述表
	pDC.SetBkMode(TRANSPARENT);
	CFont font;
	font.CreateFont(150,50,0,0,FW_HEAVY,TRUE,FALSE,0,ANSI_CHARSET,OUT_CHARACTER_PRECIS,
	                CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"宋体");
	CFont* pOldFont=pDC.SelectObject(&font);
	for(int i=0;i<255;i++)
	{
        pDC.SetTextColor(RGB(255,i,0));
	    pDC.TextOut(100,100,"文字颜色渐变");
		
	}	
	pDC.SelectObject(pOldFont);
	
}




void CGraphicsleeView::OnFetchcolor()
{
	// TODO: 在此添加命令处理程序代码
	CFetchColorDlg dlg;
	dlg.DoModal();
}


void CGraphicsleeView::OnReversecolor()
{
	// TODO: 在此添加命令处理程序代码
	CReverseColorDlg dlg;
	dlg.DoModal();
}


void CGraphicsleeView::OnFetchobj()
{
	// TODO: 在此添加命令处理程序代码
	CFetchObj dlg;
	dlg.DoModal();

}

BOOL CGraphicsleeView::GetBmp(LPCTSTR lpszSourceName,CBitmap &bitmap)
{	
	HBITMAP hbmp=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),lpszSourceName,
		IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	if(hbmp==NULL)
		return FALSE;

	bitmap.Detach();			//分离位图对象
	bitmap.Attach(hbmp);
	
	bitmap.GetBitmap(&BMap);//将载入的位图与bitmap关联起来
	return TRUE;

	/*LoadImage函数语法说明
	  HANDLE LoadImage(HINSTANCE hinst,LPCTSTR lpszName,UINT uType,int cx Desired,int cyDesired,UINT fuLoad);
	参数说明：
	  hinst :表示包含图像的实例句柄，可以为NULL
	  lpszName:表示图像的资源名称，如果从磁盘中加载，该参数表示图像的名称，包含完整路径
	  uType:表示加载的图像类型：为IMAGE_BITMAP,表示加载位图，为IMAGE_CURSOR,表示加载鼠标指针，为IMAGE_ICON，表示加载图标
	  cxDesired:表示图标或鼠标的宽度，如果加载的是位图，则该参数必须为0
	  cyDesired:表示图标或鼠标的高度，如果加载的是位图，则该参数必须为0
	  fuLoad:表示加载类型，如果为LR_LOADFROMFILE,表示从磁盘文件中加载位图
	返回值：函数返回加载的图像资源句柄
	*/

}


void CGraphicsleeView::OnLook()
{
	// TODO: 在此添加命令处理程序代码
	
	CString FilePathname;
	CFileDialog dlg(TRUE,_T("bmp"),_T("*.bmp"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("位图文件(*.bmp)|*.bmp|"));
	if(dlg.DoModal())
	{
		FilePathname=dlg.GetPathName();
		if(FilePathname!="*.bmp")	//判断是否在打开文件对话框中选择取消
		{
			if(!GetBmp(FilePathname,bitmap) )	//
			{
				MessageBox("打开文件失败!","提示",MB_ICONHAND|MB_OK);
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
	CFileDialog构造函数语法说明：
	  CFileDialog(BOOL bOpenFileDialog,LPCTSTR lpszDefExt =NULL,LPCTSTR lpszFileName =NULL,
	            DWORD dwFlags =OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,LPCTSTR lpszFilter =NULL,
				CWnd* pParentWnd =NULL);
	参数说明：
	  bOpenFileDialog：为TRUE，表示文件打开对话框；为FALSE，表示文件保存对话框
	  lpszDefExt：指定文件扩展名，若用户在文件名编辑框中没有输入扩展名，则系统在文件名后自动添加lpszDefExt指定的扩展名
	  lpszFileName：在文件名编辑框中指定开始出现的文件名，若为NULL，则不出现
	  dwFlags：指定对话框的界面标志，为OFN_HIDEREADONLY时，表示隐藏对话框中的“只读”复选框；
	           为OFN_OVERWRITEPROMPT时，表示文件保存时，若有指定的文件有重名，则出现提示对话框
      lpszFilter：用来确定出现在文件列表中的文件类型。它由一对或多对字符串组成，每对字符串中的一个字符串表示过滤器名称，
	              第二个字符串表示文件扩展名，若指定多个扩展名，则用“；”分隔，字符串最后用“||”结尾
      pParentWnd：指定对话框的父窗口指针
	  LPCTSTR类型用来表示一个常值字符指针，这里可以理解成是一个常值字符串类型
	*/


	/*
	MFC的6种通用对话框类 ：CColorDialog：颜色对话框，允许用户选择或创建颜色
	                      CFiledialog：文件对话框，允许用户打开或保存一个文件
						  CFindRepalceDialog:查找替换对话框，允许用户指定或查找指定字符串
						  CPageSetupDialog:页面设置对话框，允许用户设置页面参数
						  CFontDialog:字体对话框，允许用户从列出的可用字体中选择一种字体
						  CPrintDialog:打印对话框，允许用户设置打印机的及答应文档
	这些通用对话框可供用户在程序中直接使用。但他们都有一个共同特点：他们都从用户获取信息，但并不对信息做处理。
	*/
	
}



void CGraphicsleeView::OnMin()
{
	// TODO: 在此添加命令处理程序代码
	m_bmZoom=ZOOMIN;
	Invalidate();
}


void CGraphicsleeView::OnMax()
{
	// TODO: 在此添加命令处理程序代码
	m_bmZoom=ZOOMOUT;
	Invalidate();
}


void CGraphicsleeView::OnFull()
{
	// TODO: 在此添加命令处理程序代码
	m_bmZoom=ZOOMFIT;
	Invalidate();
}


void CGraphicsleeView::OnSprin()
{
	// TODO: 在此添加命令处理程序代码
}


void CGraphicsleeView::OnSrc()
{
	// TODO: 在此添加命令处理程序代码
	m_bmZoom=ZOOMSCR;
	Invalidate();
}




void CGraphicsleeView::OnMedply()
{
	// TODO: 在此添加命令处理程序代码
	CMedPlyDlg dlg;
	dlg.DoModal();
}


void CGraphicsleeView::OnSnap()
{
	// TODO: 在此添加命令处理程序代码
/*	GdiplusStartup(&m_gdiplusToken,&m_gdiplusStartupInput,NULL);
	{
	    HWND hDesk=GetDesktopWindow();
		RECT RC={0};
		GetWindowRect(hDesk,&rc);

	}
*/
}

