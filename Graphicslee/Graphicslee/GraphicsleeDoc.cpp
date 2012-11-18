// GraphicsleeDoc.cpp : CGraphicsleeDoc 类的实现
//

#include "stdafx.h"
#include "Graphicslee.h"

#include "GraphicsleeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsleeDoc

IMPLEMENT_DYNCREATE(CGraphicsleeDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphicsleeDoc, CDocument)
END_MESSAGE_MAP()


// CGraphicsleeDoc 构造/析构

CGraphicsleeDoc::CGraphicsleeDoc()
{
	// TODO: 在此添加一次性构造代码

}

CGraphicsleeDoc::~CGraphicsleeDoc()
{
}

BOOL CGraphicsleeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CGraphicsleeDoc 序列化

void CGraphicsleeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CGraphicsleeDoc 诊断

#ifdef _DEBUG
void CGraphicsleeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphicsleeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGraphicsleeDoc 命令
