#pragma once
#include "afxwin.h"


// CPosDialog ��ȭ �����Դϴ�.

class CPosDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPosDialog)

public:
	CPosDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPosDialog();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	double m_hPos;
	double m_wPos;
};
