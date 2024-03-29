// MyDrawView.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "MyDrawDoc.h"
#include "MyDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyDrawView

IMPLEMENT_DYNCREATE(CMyDrawView, CView)

BEGIN_MESSAGE_MAP(CMyDrawView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FIGURE_LINE, &CMyDrawView::OnFigureLine)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FIGURE_RECTANGLE, &CMyDrawView::OnFigureRectangle)
	ON_COMMAND(ID_FIGURE_OVAL, &CMyDrawView::OnFigureOval)
	ON_COMMAND(ID_FIGURE_DELETE, &CMyDrawView::OnFigureDelete)
	ON_COMMAND(ID_ADD_LINE, &CMyDrawView::OnAddLine)
	ON_COMMAND(ID_COLOR_BLACK, &CMyDrawView::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CMyDrawView::OnColorRed)
	ON_COMMAND(ID_COLOR_BLUE, &CMyDrawView::OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, &CMyDrawView::OnColorGreen)
	ON_COMMAND(ID_FIGURE_GROUP, &CMyDrawView::OnFigureGroup)
	ON_COMMAND(ID_EDIT_COPY, &CMyDrawView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CMyDrawView::OnEditPaste)
	ON_COMMAND(ID_GROUP_CREATE, &CMyDrawView::OnGroupCreate)
	ON_COMMAND(ID_GROUP_DEGROUP, &CMyDrawView::OnGroupDegroup)
	ON_COMMAND(ID_GROUP_DELETEGROUP, &CMyDrawView::OnGroupDeletegroup)
	ON_COMMAND(ID_FIGURE_BRINGBACK, &CMyDrawView::OnFigureBringback)
	ON_COMMAND(ID_FIGURE_BRINGFORTH, &CMyDrawView::OnFigureBringforth)
END_MESSAGE_MAP()

// CMyDrawView construction/destruction

CMyDrawView::CMyDrawView()
{
	// TODO: add construction code here

}

CMyDrawView::~CMyDrawView()
{
}

BOOL CMyDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyDrawView drawing

void CMyDrawView::OnDraw(CDC* pDC)
{
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDoc->drawing.draw(pDC);
}


// CMyDrawView printing

BOOL CMyDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

// CMyDrawView diagnostics

#ifdef _DEBUG
void CMyDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMyDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDrawDoc* CMyDrawView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDrawDoc)));
	return (CMyDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyDrawView message handlers

void CMyDrawView::OnFigureLine()
{
	// TODO: Add your command handler code here
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setEditMode(Drawing::NewLineMode);
}

afx_msg void CMyDrawView::OnMouseMove(UINT nFlags,CPoint point)
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.OnMouse(this, nFlags, point);
}

afx_msg void CMyDrawView::OnLButtonUp(UINT nFlags,CPoint point)
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.OnMouse(this, nFlags, point);
}

afx_msg void CMyDrawView::OnLButtonDown(UINT nFlags,CPoint point)
{
	CMyDrawDoc* pDoc = GetDocument();

	pDoc->drawing.OnMouse(this, nFlags, point);
}


void CMyDrawView::OnFigureRectangle()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setEditMode(Drawing::NewRectangleMode);
}


void CMyDrawView::OnFigureOval()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setEditMode(Drawing::NewOvalMode);
}


void CMyDrawView::OnFigureDelete()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.deleteSelectdControlPoints(this);
}


void CMyDrawView::OnAddLine()
{
	// TODO: Add your command handler code here
}


void CMyDrawView::OnColorBlack()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setColor(this, RGB(0, 0, 0));
}


void CMyDrawView::OnColorRed()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setColor(this, RGB(255, 0, 0));
}


void CMyDrawView::OnColorBlue()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setColor(this, RGB(0, 0, 255));
}


void CMyDrawView::OnColorGreen()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.setColor(this, RGB(0, 255, 0));
}


void CMyDrawView::OnFigureGroup()
{
	CMyDrawDoc* pDoc = GetDocument();
	//pDoc->drawing.
}


void CMyDrawView::OnEditCopy()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.CopyToClipBoard(this);
}


void CMyDrawView::OnEditPaste()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.PasteFromClipBoard(this);
}


void CMyDrawView::OnGroupCreate()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.createGroup(this);
}


void CMyDrawView::OnGroupDegroup()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.unGroup(this);
}


void CMyDrawView::OnGroupDeletegroup()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.deleteGroup(this);
}


void CMyDrawView::OnFigureBringback()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.moveForward(this);
}


void CMyDrawView::OnFigureBringforth()
{
	CMyDrawDoc* pDoc = GetDocument();
	pDoc->drawing.moveBackward(this);
}
