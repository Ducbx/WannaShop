// ConstantDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "ConstantDlg.h"
#include "afxdialogex.h"


// CConstantDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CConstantDlg, CDialogEx)

CConstantDlg::CConstantDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_Constant(0)
{

}

CConstantDlg::~CConstantDlg()
{
}

void CConstantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 0, 255);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	m_Static1.SetWindowTextW(L"��� ��");
}


BEGIN_MESSAGE_MAP(CConstantDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CConstantDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CConstantDlg �޽��� ó�����Դϴ�.


void CConstantDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
