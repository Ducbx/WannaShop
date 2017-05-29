
// WannaShopView.h : CWannaShopView Ŭ������ �������̽�
//

#pragma once


class CWannaShopView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWannaShopView();
	DECLARE_DYNCREATE(CWannaShopView)

// Ư���Դϴ�.
public:
	CWannaShopDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CWannaShopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnDownSampling();
	afx_msg void OnMenuDownSampling();
	afx_msg void OnMenuUpSampling();
	afx_msg void OnMenuQuantization();
	afx_msg void OnSumConstant();
	afx_msg void OnSubConstant();
	afx_msg void OnMulConstant();
	afx_msg void OnDivConstant();
	afx_msg void OnNegaTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WannaShopView.cpp�� ����� ����
inline CWannaShopDoc* CWannaShopView::GetDocument() const
   { return reinterpret_cast<CWannaShopDoc*>(m_pDocument); }
#endif

