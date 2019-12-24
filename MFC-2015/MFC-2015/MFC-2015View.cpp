
// MFC-2015View.cpp : implementation of the CMFC2015View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-2015.h"
#endif

#include "MFC-2015Doc.h"
#include "MFC-2015View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2015View

IMPLEMENT_DYNCREATE(CMFC2015View, CView)

BEGIN_MESSAGE_MAP(CMFC2015View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC2015View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC2015View construction/destruction

CMFC2015View::CMFC2015View()
{
	// TODO: add construction code here

}

CMFC2015View::~CMFC2015View()
{
}

BOOL CMFC2015View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFC2015View drawing

void CMFC2015View::OnDraw(CDC* /*pDC*/)
{
	CMFC2015Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFC2015View printing


void CMFC2015View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC2015View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC2015View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC2015View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFC2015View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC2015View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC2015View diagnostics

#ifdef _DEBUG
void CMFC2015View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2015View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2015Doc* CMFC2015View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2015Doc)));
	return (CMFC2015Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2015View message handlers
