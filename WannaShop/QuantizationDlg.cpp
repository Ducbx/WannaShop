// QuantizationDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "QuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialogEx)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_QuantBit(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantBit);
	DDV_MinMaxInt(pDX, m_QuantBit, 1, 32);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	m_Static1.SetWindowTextW(L"�ܰ�");
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CQuantizationDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CQuantizationDlg �޽��� ó�����Դϴ�.


void CQuantizationDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
