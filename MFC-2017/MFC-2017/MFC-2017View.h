
// MFC-2017View.h : interface of the CMFC2017View class
//

#pragma once


class CMFC2017View : public CView
{
protected: // create from serialization only
	CMFC2017View() noexcept;
	DECLARE_DYNCREATE(CMFC2017View)

// Attributes
public:
	CMFC2017Doc* GetDocument() const;

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
	virtual ~CMFC2017View();
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

#ifndef _DEBUG  // debug version in MFC-2017View.cpp
inline CMFC2017Doc* CMFC2017View::GetDocument() const
   { return reinterpret_cast<CMFC2017Doc*>(m_pDocument); }
#endif

