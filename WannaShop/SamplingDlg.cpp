// SamplingDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "SamplingDlg.h"
#include "afxdialogex.h"


// CSamplingDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSamplingDlg, CDialogEx)

CSamplingDlg::CSamplingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_SamplingRate(0)
{

}

CSamplingDlg::~CSamplingDlg()
{
}

void CSamplingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SamplingRate);
	DDV_MinMaxInt(pDX, m_SamplingRate, 1, 32);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	m_Static1.SetWindowTextW(L"����");
}


BEGIN_MESSAGE_MAP(CSamplingDlg, CDialogEx)
END_MESSAGE_MAP()


// CSamplingDlg �޽��� ó�����Դϴ�.
