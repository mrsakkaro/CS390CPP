// MyDrawView.h : interface of the CMyDrawView class
//


#pragma once


class CMyDrawView : public CView
{
protected: // create from serialization only
	CMyDrawView();
	DECLARE_DYNCREATE(CMyDrawView)

// Attributes
public:
	CMyDrawDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnMouseMove(UINT nFlags,CPoint point);
	virtual void OnLButtonUp(UINT nFlags,CPoint point);
	virtual void OnLButtonDown(UINT nFlags,CPoint point);

// Implementation
public:
	virtual ~CMyDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFigureLine();
	afx_msg void OnFigureRectangle();
	afx_msg void OnFigureOval();
	afx_msg void OnFigureDelete();
	afx_msg void OnAddLine();
	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnFigureGroup();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnGroupCreate();
	afx_msg void OnGroupDegroup();
	afx_msg void OnGroupDeletegroup();
	afx_msg void OnFigureBringback();
	afx_msg void OnFigureBringforth();
};

#ifndef _DEBUG  // debug version in MyDrawView.cpp
inline CMyDrawDoc* CMyDrawView::GetDocument() const
   { return reinterpret_cast<CMyDrawDoc*>(m_pDocument); }
#endif

