// leeDoc.cpp : implementation of the CLeeDoc class
//

#include "stdafx.h"
#include "lee.h"

#include "leeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeeDoc

IMPLEMENT_DYNCREATE(CLeeDoc, CDocument)

BEGIN_MESSAGE_MAP(CLeeDoc, CDocument)
	//{{AFX_MSG_MAP(CLeeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeeDoc construction/destruction

CLeeDoc::CLeeDoc()
{
	// TODO: add one-time construction code here

}

CLeeDoc::~CLeeDoc()
{
}

BOOL CLeeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLeeDoc serialization

void CLeeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLeeDoc diagnostics

#ifdef _DEBUG
void CLeeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLeeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeeDoc commands
