// GraphicsleeDoc.cpp : CGraphicsleeDoc ���ʵ��
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


// CGraphicsleeDoc ����/����

CGraphicsleeDoc::CGraphicsleeDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CGraphicsleeDoc::~CGraphicsleeDoc()
{
}

BOOL CGraphicsleeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGraphicsleeDoc ���л�

void CGraphicsleeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CGraphicsleeDoc ���

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


// CGraphicsleeDoc ����
