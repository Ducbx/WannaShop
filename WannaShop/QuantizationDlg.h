#pragma once
#include "afxwin.h"


// CQuantizationDlg ��ȭ �����Դϴ�.

class CQuantizationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQuantizationDlg)

public:
	CQuantizationDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CQuantizationDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_QuantBit;
	afx_msg void OnEnChangeEdit1();
	CStatic m_Static1;
};
