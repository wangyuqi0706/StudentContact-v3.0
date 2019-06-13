#pragma once


// CFindDlg 对话框

class CFindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFindDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CString m_name;
//	afx_msg void OnLvnItemchangedFind(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
};
