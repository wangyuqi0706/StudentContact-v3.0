// CFindDlg.cpp: 实现文件
//
#pragma once
#include"stdafx.h"
#include "Sd3.h"
#include "CFindDlg.h"
#include "afxdialogex.h"
#include"MainFrm.h"
#include"Sd3View.h"


// CFindDlg 对话框

IMPLEMENT_DYNAMIC(CFindDlg, CDialogEx)

CFindDlg::CFindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIND_DLG, pParent)
	, m_name(_T(""))
{

}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FIND, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialogEx)
	
	ON_BN_CLICKED(IDOK, &CFindDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CFindDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CFindDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CFindDlg 消息处理程序



BOOL CFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, "姓名", 0, 200);
	m_list.InsertColumn(1, "地址", 0, 200);
	m_list.InsertColumn(2, "电话", 0, 200);
	m_list.InsertColumn(3, "邮编", 0, 200);
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CFindDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	
}


void CFindDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
	UpdateData();
	CString str = m_name;
	CMainFrame* pMain = (CMainFrame*)AfxGetApp()-> m_pMainWnd;
	CSd3View* pView = (CSd3View*)pMain-> GetActiveView();
	if (str.IsEmpty())
		MessageBox("请输入要查询的姓名");
	else
	{
		int n = pView->m_list.GetItemCount();
		bool isFound = 0;
		for (int i = 0; i <n; i++)
		{
			int j = 0;
			if (str.Compare(pView->m_list.GetItemText(i, 0))==0)
			{
				isFound = 1;
				m_list.InsertItem(j, pView->m_list.GetItemText(i, 0));
				m_list.SetItemText(j, 1, pView->m_list.GetItemText(i, 1));
				m_list.SetItemText(j, 2, pView->m_list.GetItemText(i, 2));
				m_list.SetItemText(j, 3, pView->m_list.GetItemText(i, 3));
				++j;
			}
			
		}
		if (isFound == 0)
			MessageBox("没有找到该同学");
		UpdateData();
	}
}


void CFindDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
