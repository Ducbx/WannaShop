
// WannaShop.h : WannaShop ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWannaShopApp:
// �� Ŭ������ ������ ���ؼ��� WannaShop.cpp�� �����Ͻʽÿ�.
//

class CWannaShopApp : public CWinApp
{
public:
	CWannaShopApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWannaShopApp theApp;
