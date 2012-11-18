// leeView.h : interface of the CLeeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEEVIEW_H__4647D596_5D3E_4BF6_9051_67F51E824545__INCLUDED_)
#define AFX_LEEVIEW_H__4647D596_5D3E_4BF6_9051_67F51E824545__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLeeView : public CView
{
protected: // create from serialization only
	CLeeView();
	DECLARE_DYNCREATE(CLeeView)

// Attributes
public:
	CLeeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLeeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLeeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in leeView.cpp
inline CLeeDoc* CLeeView::GetDocument()
   { return (CLeeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEEVIEW_H__4647D596_5D3E_4BF6_9051_67F51E824545__INCLUDED_)
