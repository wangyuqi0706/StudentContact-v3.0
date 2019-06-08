#if !defined(AFX_DATADLG_H__D795F8C1_684C_40D2_9536_237F2A5F61BB__INCLUDED_)
#define AFX_DATADLG_H__D795F8C1_684C_40D2_9536_237F2A5F61BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog

class CDataDlg : public CDialog
{
// Construction
public:
	CDataDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL m_bModify;
// Dialog Data
	//{{AFX_DATA(CDataDlg)
	enum { IDD = IDD_ADD_DLG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_address;
	CString m_phone;
	CString m_mail;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATADLG_H__D795F8C1_684C_40D2_9536_237F2A5F61BB__INCLUDED_)
