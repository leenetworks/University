// GraphicsleeDoc.h : CGraphicsleeDoc ��Ľӿ�
//


#pragma once


class CGraphicsleeDoc : public CDocument
{
protected: // �������л�����
	CGraphicsleeDoc();
	DECLARE_DYNCREATE(CGraphicsleeDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CGraphicsleeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


