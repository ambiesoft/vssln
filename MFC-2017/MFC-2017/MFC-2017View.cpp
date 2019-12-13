
// MFC-2017View.cpp : implementation of the CMFC2017View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-2017.h"
#endif

#include "MFC-2017Doc.h"
#include "MFC-2017View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2017View

IMPLEMENT_DYNCREATE(CMFC2017View, CView)

BEGIN_MESSAGE_MAP(CMFC2017View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC2017View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC2017View construction/destruction

CMFC2017View::CMFC2017View() noexcept
{
	// TODO: add construction code here

}

CMFC2017View::~CMFC2017View()
{
}

BOOL CMFC2017View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFC2017View drawing

void CMFC2017View::OnDraw(CDC* /*pDC*/)
{
	CMFC2017Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFC2017View printing


void CMFC2017View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC2017View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC2017View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC2017View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFC2017View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC2017View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC2017View diagnostics

#ifdef _DEBUG
void CMFC2017View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2017View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2017Doc* CMFC2017View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2017Doc)));
	return (CMFC2017Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2017View message handlers
