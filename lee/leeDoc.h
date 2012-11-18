// leeDoc.h : interface of the CLeeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEEDOC_H__D2172159_7608_4492_A51D_FE46CF5120B3__INCLUDED_)
#define AFX_LEEDOC_H__D2172159_7608_4492_A51D_FE46CF5120B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLeeDoc : public CDocument
{
protected: // create from serialization only
	CLeeDoc();
	DECLARE_DYNCREATE(CLeeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLeeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLeeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEEDOC_H__D2172159_7608_4492_A51D_FE46CF5120B3__INCLUDED_)
