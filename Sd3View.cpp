// Sd3View.cpp : implementation of the CSd3View class
//

#include "stdafx.h"
#include "Sd3.h"
#include "DataDlg.h"
#include "Sd3Doc.h"
#include "Sd3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSd3View

IMPLEMENT_DYNCREATE(CSd3View, CListView)

BEGIN_MESSAGE_MAP(CSd3View, CListView)
	//{{AFX_MSG_MAP(CSd3View)
	ON_COMMAND(ID_EDIT_ADD, OnEditAdd)
	ON_COMMAND(ID_EDIT_DEL, OnEditDel)
	ON_COMMAND(ID_EDIT_MOD, OnEditMod)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_FIND, &CSd3View::OnEditFind)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSd3View construction/destruction

CSd3View::CSd3View() :m_list(GetListCtrl())
{
	// TODO: add construction code here

}

CSd3View::~CSd3View()
{
}

BOOL CSd3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSd3View drawing

void CSd3View::OnDraw(CDC* pDC)
{
	CSd3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CSd3View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	static int j = 0;
	if (j++)
		return;
}

/////////////////////////////////////////////////////////////////////////////
// CSd3View printing

BOOL CSd3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSd3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSd3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSd3View diagnostics

#ifdef _DEBUG
void CSd3View::AssertValid() const
{
	CListView::AssertValid();
}

void CSd3View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CSd3Doc* CSd3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSd3Doc)));
	return (CSd3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSd3View message handlers

void CSd3View::OnEditAdd()
{
	CDataDlg dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	int i = m_list.GetItemCount();
	m_list.InsertItem(i, dlg.m_name);
	m_list.SetItemText(i, 1, dlg.m_address);
	m_list.SetItemText(i, 2, dlg.m_phone);
	m_list.SetItemText(i, 3, dlg.m_mail);
	CDocument* pDoc = GetDocument();
	pDoc->SetModifiedFlag();
}

void CSd3View::OnEditDel()
{
	if (!m_list.GetSelectedCount())
	{
		AfxMessageBox("请选中一条数据再删除！");
		return;
	}
	int nSel = m_list.GetSelectionMark();
	if (IDYES == AfxMessageBox("确定删除该记录吗？", MB_YESNO))
	{
		m_list.DeleteItem(nSel);
		GetDocument()->SetModifiedFlag();
	}

}

void CSd3View::OnEditMod()
{
	if (!m_list.GetSelectedCount())
	{
		AfxMessageBox("请选中一条数据再修改！");
		return;
	}
	int nSel = m_list.GetSelectionMark();

	CDataDlg dlg;
	dlg.m_name = m_list.GetItemText(nSel, 0);
	dlg.m_address = m_list.GetItemText(nSel, 1);
	dlg.m_phone = m_list.GetItemText(nSel, 2);
	dlg.m_mail = m_list.GetItemText(nSel, 3);
	dlg.m_bModify = TRUE;
	if (IDCANCEL == dlg.DoModal())
		return;
	m_list.SetItemText(nSel, 0, dlg.m_name);
	m_list.SetItemText(nSel, 1, dlg.m_address);
	m_list.SetItemText(nSel, 2, dlg.m_phone);
	m_list.SetItemText(nSel, 3, dlg.m_mail);
	GetDocument()->SetModifiedFlag();
}

void CSd3View::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	OnEditMod();
	*pResult = 0;
}

void CSd3View::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int i = 0, nCount = m_list.GetItemCount();
		ar << nCount;
		while (i < nCount)
		{
			ar << m_list.GetItemText(i, 0);
			ar << m_list.GetItemText(i, 1);
			ar << m_list.GetItemText(i, 2);
			ar << m_list.GetItemText(i, 3);
			++i;
		}
	}
	else
	{
		int i = 0, nCount = 0;
		ar >> nCount;
		CString str;
		while (i < nCount)
		{
			ar >> str;
			m_list.InsertItem(i, str);
			ar >> str;
			m_list.SetItemText(i, 1, str);
			ar >> str;
			m_list.SetItemText(i, 2, str);
			ar >> str;
			m_list.SetItemText(i, 3, str);
			++i;
		}
	}
}

void CSd3View::DeleteContents()
{
	m_list.DeleteAllItems();

}



int CSd3View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_list.SetImageList(&m_iList, LVSIL_SMALL);
	m_list.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, "姓名", 0, 200);
	m_list.InsertColumn(1, "地址", 0, 200);
	m_list.InsertColumn(2, "电话", 0, 200);
	m_list.InsertColumn(3, "邮编", 0, 200);

	return 0;
}


void CSd3View::OnEditFind()
{
	// TODO: 在此添加命令处理程序代码
	CDataDlg dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	CString str = dlg.m_name;

	
}
