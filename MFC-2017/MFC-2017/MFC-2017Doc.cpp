
// MFC-2017Doc.cpp : implementation of the CMFC2017Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-2017.h"
#endif

#include "MFC-2017Doc.h"

#include <propkey.h>

#include "../../../lsMisc/OpenCommon.h"
using namespace Ambiesoft;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC2017Doc

IMPLEMENT_DYNCREATE(CMFC2017Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC2017Doc, CDocument)
	ON_COMMAND(ID_HELP_TEST, &CMFC2017Doc::OnHelpTest)
END_MESSAGE_MAP()


// CMFC2017Doc construction/destruction

CMFC2017Doc::CMFC2017Doc() noexcept
{
	// TODO: add one-time construction code here

}

CMFC2017Doc::~CMFC2017Doc()
{
}

BOOL CMFC2017Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFC2017Doc serialization

void CMFC2017Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFC2017Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFC2017Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFC2017Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC2017Doc diagnostics

#ifdef _DEBUG
void CMFC2017Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC2017Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC2017Doc commands


void CMFC2017Doc::OnHelpTest()
{
	OpenFolder(nullptr, L"C:\\T");
}
