// DataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sd3.h"
#include "DataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog


CDataDlg::CDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataDlg::IDD, pParent)
	, m_name(_T(""))
	, m_address(_T(""))
	, m_phone(_T(""))
	, m_mail(_T(""))
{
	m_bModify = FALSE;
}


void CDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataDlg)
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_NAM, m_name);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_PHONE, m_phone);
	DDX_Text(pDX, IDC_MAIL, m_mail);
}


BEGIN_MESSAGE_MAP(CDataDlg, CDialog)
	//{{AFX_MSG_MAP(CDataDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataDlg message handlers

BOOL CDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(m_bModify)
	{
		SetWindowText("Êý¾ÝÐÞ¸Ä");
		GetDlgItem(IDC_NAM) ->EnableWindow(FALSE);
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


