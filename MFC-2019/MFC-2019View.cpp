
// MFC-2019View.cpp : implementation of the CMFC2019View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-2019.h"
#endif

#include "MFC-2019Doc.h"
#include "MFC-2019View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2019View

IMPLEMENT_DYNCREATE(CMFC2019View, CView)

BEGIN_MESSAGE_MAP(CMFC2019View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC2019View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC2019View construction/destruction

CMFC2019View::CMFC2019View() noexcept
{
	// TODO: add construction code here

}

CMFC2019View::~CMFC2019View()
{
}

BOOL CMFC2019View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFC2019View drawing

void CMFC2019View::OnDraw(CDC* /*pDC*/)
{
	CMFC2019Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFC2019View printing


void CMFC2019View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC2019View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC2019View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC2019View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFC2019View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC2019View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC2019View diagnostics

#ifdef _DEBUG
void CMFC2019View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2019View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2019Doc* CMFC2019View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2019Doc)));
	return (CMFC2019Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2019View message handlers
