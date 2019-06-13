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
	
	//ON_BN_CLICKED(IDOK, &CFindDlg::OnBnClickedOk)
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


void CFindDlg::OnBnClickedButton1()
{
	m_list.DeleteAllItems();//先将列表清空
	UpdateData();//将对话框中内容更新到对应的变量m_name中
	CString str = m_name;
	CMainFrame* pMain = (CMainFrame*)AfxGetApp()-> m_pMainWnd;
	CSd3View* pView = (CSd3View*)pMain-> GetActiveView();//获取到视图类的指针
	if (str.IsEmpty())
		MessageBox("请输入要查询的姓名");//判断用户是否输入了一个字符串，并弹出提示
	else
	{
		int n = pView->m_list.GetItemCount();//获取列表行数
		bool isFound = false;//判断是否找到的布尔变量
		for (int i = 0; i <n; i++)//遍历原列表中所有信息
		{
			int j = 0;
			if (str.Compare(pView->m_list.GetItemText(i, 0))==0)//依次比较姓名
			{
				isFound = true;
				m_list.InsertItem(j, pView->m_list.GetItemText(i, 0));
				m_list.SetItemText(j, 1, pView->m_list.GetItemText(i, 1));
				m_list.SetItemText(j, 2, pView->m_list.GetItemText(i, 2));
				m_list.SetItemText(j, 3, pView->m_list.GetItemText(i, 3));
				++j;//将姓名匹配的联系人信息全部显示在新列表中
			}
			
		}
		if (isFound == false)
			MessageBox("没有找到该同学");//若没有找到则弹出提示
		UpdateData();//将信息显示在界面中
	}
}


void CFindDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
