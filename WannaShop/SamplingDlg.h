#pragma once
#include "afxwin.h"


// CSamplingDlg ��ȭ �����Դϴ�.

class CSamplingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSamplingDlg)

public:
	CSamplingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSamplingDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_SamplingRate;
	CStatic m_Static1;
};
