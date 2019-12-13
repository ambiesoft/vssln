
// MFC-2013View.cpp : implementation of the CMFC2013View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-2013.h"
#endif

#include "MFC-2013Doc.h"
#include "MFC-2013View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2013View

IMPLEMENT_DYNCREATE(CMFC2013View, CView)

BEGIN_MESSAGE_MAP(CMFC2013View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC2013View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC2013View construction/destruction

CMFC2013View::CMFC2013View()
{
	// TODO: add construction code here

}

CMFC2013View::~CMFC2013View()
{
}

BOOL CMFC2013View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFC2013View drawing

void CMFC2013View::OnDraw(CDC* /*pDC*/)
{
	CMFC2013Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFC2013View printing


void CMFC2013View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC2013View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC2013View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC2013View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFC2013View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC2013View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC2013View diagnostics

#ifdef _DEBUG
void CMFC2013View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2013View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2013Doc* CMFC2013View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2013Doc)));
	return (CMFC2013Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2013View message handlers
