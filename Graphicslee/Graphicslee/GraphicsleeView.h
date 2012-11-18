// GraphicsleeView.h : CGraphicsleeView ��Ľӿ�
//


#pragma once
#define ZOOMFIT 0
#define ZOOMSCR 1
#define ZOOMOUT 2
#define ZOOMIN  3

class CGraphicsleeView : public CView
{
protected: // �������л�����
	CGraphicsleeView();
	DECLARE_DYNCREATE(CGraphicsleeView)

// ����
public:
	CGraphicsleeDoc* GetDocument() const;
				
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	CBitmap bitmap;
	BITMAP BMap;
	int m_bmZoom;
	BOOL m_bFileOpen;
	BOOL GetBmp(LPCTSTR lpszSourceName,CBitmap &bitmap);
	virtual ~CGraphicsleeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
	UINT m_nDrawType;
	CPoint m_ptOrigin;
    UINT m_nLineWidth;
	int m_nLineStyle;
	COLORREF m_clr;
	CFont m_font;
	CString m_strFontName;
    CString m_strLine;
	int m_nRed,m_nGreen,m_nBlue;
	BOOL m_bDraw;//Ϳѻ����
	BOOL m_bColor;//����ɫ����
	int ilook;//λͼ�������
	CBitmap m_hBmp;
	GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDot();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	//afx_msg void OnEllipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSetting();
	afx_msg void OnColor();
	afx_msg void OnFont();
	afx_msg void OnGradual();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMultcolor();
	afx_msg void OnMcolorl();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTransparent();
	afx_msg void OnEmptyfont();
	afx_msg void OnSparinfont();
	afx_msg void OnGrandualfont();
	afx_msg void OnFetchcolor();
	afx_msg void OnReversecolor();
	afx_msg void OnFetchobj();
	afx_msg void OnLook();
	afx_msg void OnMin();
	afx_msg void OnMax();
	afx_msg void OnFull();
	afx_msg void OnSprin();
	afx_msg void OnSrc();
	afx_msg void OnMedply();
	afx_msg void OnSnap();
	afx_msg void OnEllipse();
};

#ifndef _DEBUG  // GraphicsleeView.cpp �еĵ��԰汾
inline CGraphicsleeDoc* CGraphicsleeView::GetDocument() const
   { return reinterpret_cast<CGraphicsleeDoc*>(m_pDocument); }
#endif

