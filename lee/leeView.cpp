// leeView.cpp : implementation of the CLeeView class
//

#include "stdafx.h"
#include "lee.h"

#include "leeDoc.h"
#include "leeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeeView

IMPLEMENT_DYNCREATE(CLeeView, CView)

BEGIN_MESSAGE_MAP(CLeeView, CView)
	//{{AFX_MSG_MAP(CLeeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeeView construction/destruction

CLeeView::CLeeView()
{
	// TODO: add construction code here

}

CLeeView::~CLeeView()
{
}

BOOL CLeeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeeView drawing

void CLeeView::OnDraw(CDC* pDC)
{  //输出点、线、面
/*	int x=111,y=123,color=125;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			pDC->SetPixel(x-i,y-j,color-j);
*/
	//输出圆形
/*	int r=105,color=125;
	int x=0,y=r,d=1-r;
	while(x<y)
	{ 
		if(d<0)
		{  d+=2*x+3;
		   x++;
		}
		else{
		d+=2*(x-y)+5;
		x++;
		y--;
		}
		pDC->SetPixel(y,x,color);
		pDC->SetPixel(x,y,color);
	}
*/
	//输出椭圆
/*	int a=150,b=80;int color=105;
	int x=0,y=b;float d;
	d=b*b-a*a*b+0.25*a*a;
	while(b*b*x<a*a*y)
	{pDC->SetPixel(x,y,color);pDC->SetPixel(x,-y,color);
	 pDC->SetPixel(-x,y,color);pDC->SetPixel(-x,-y,color);
	 if(d<=0){d=d+b*b*(2*x+3);x++;}
	 else {d=d+b*b*(2*x+3)+2*a*a*(1-y);
	    x++;y--;}
	}
	d=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
	while(y>0)
	{   pDC->SetPixel(x,y,color);pDC->SetPixel(x,-y,color);
	    pDC->SetPixel(-x,y,color);pDC->SetPixel(-x,-y,color);
		if(d>0){
		d=d+a*a*(3-2*y);y--;}
		else{
		d=d+2*b*b*(x+1)+a*a*(3-2*y);
		x++;y--;}
	}
*/
//	投影变换  以z轴为主视方向
	int point[8][4]={{0,0,0,1},{0,0,10,1},{10,0,10,1},{10,0,0,1},{10,10,0,1},{0,10,0,1},{0,10,10,1},{10,10,10,1}};//以10为边长的正方体的八个顶点集
	int　tx[4][4]={{1,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,1}};      


	CLeeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLeeView printing

BOOL CLeeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLeeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLeeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLeeView diagnostics

#ifdef _DEBUG
void CLeeView::AssertValid() const
{
	CView::AssertValid();
}

void CLeeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLeeDoc* CLeeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLeeDoc)));
	return (CLeeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeeView message handlers
