
// MFC-2013View.h : interface of the CMFC2013View class
//

#pragma once


class CMFC2013View : public CView
{
protected: // create from serialization only
	CMFC2013View();
	DECLARE_DYNCREATE(CMFC2013View)

// Attributes
public:
	CMFC2013Doc* GetDocument() const;

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

// Implementation
public:
	virtual ~CMFC2013View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC-2013View.cpp
inline CMFC2013Doc* CMFC2013View::GetDocument() const
   { return reinterpret_cast<CMFC2013Doc*>(m_pDocument); }
#endif

