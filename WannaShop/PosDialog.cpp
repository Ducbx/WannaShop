// PosDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "PosDialog.h"
#include "afxdialogex.h"


// CPosDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPosDialog, CDialogEx)

CPosDialog::CPosDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_hPos(0)
	, m_wPos(0)
{
	
}

CPosDialog::~CPosDialog()
{
}

void CPosDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_hPos, m_hPos);
	DDX_Text(pDX, IDC_wPos, m_wPos);
}


BEGIN_MESSAGE_MAP(CPosDialog, CDialogEx)
END_MESSAGE_MAP()


// CPosDialog �޽��� ó�����Դϴ�.
