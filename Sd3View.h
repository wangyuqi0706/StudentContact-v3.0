// Sd3View.h : interface of the CSd3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SD3VIEW_H__DD52F8CE_91F8_4906_95C8_18CA306E1968__INCLUDED_)
#define AFX_SD3VIEW_H__DD52F8CE_91F8_4906_95C8_18CA306E1968__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSd3Doc;
class CSd3View : public CListView
{
protected: // create from serialization only
	CSd3View();
	DECLARE_DYNCREATE(CSd3View)

// Attributes
public:
	CSd3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSd3View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DeleteContents();
	void Serialize(CArchive& ar);
	CImageList m_iList;
	CListCtrl& m_list;
	virtual ~CSd3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSd3View)
	afx_msg void OnEditAdd();
	afx_msg void OnEditDel();
	afx_msg void OnEditMod();
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditFind();
};

#ifndef _DEBUG  // debug version in Sd3View.cpp
inline CSd3Doc* CSd3View::GetDocument()
   { return (CSd3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SD3VIEW_H__DD52F8CE_91F8_4906_95C8_18CA306E1968__INCLUDED_)
