// CFindDlg.cpp: 实现文件
//
#pragma once
#include"stdafx.h"
#include "Sd3.h"
#include "CFindDlg.h"
#include "afxdialogex.h"


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
	
END_MESSAGE_MAP()


// CFindDlg 消息处理程序

