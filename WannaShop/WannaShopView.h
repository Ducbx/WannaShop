
// WannaShopView.h : CWannaShopView 클래스의 인터페이스
//

#pragma once


class CWannaShopView : public CView
{
protected: // serialization에서만 만들어집니다.
	CWannaShopView();
	DECLARE_DYNCREATE(CWannaShopView)

// 특성입니다.
public:
	CWannaShopDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CWannaShopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
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
	afx_msg void OnHistogram();
	afx_msg void OnHistoStretch();
	afx_msg void OnHistoEqual();
	afx_msg void OnEmbossing();
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
	afx_msg void OnSharpening();
	afx_msg void OnMedianFilter();
	afx_msg void OnKuwaharaFilter();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMedianSub();
	afx_msg void OnMeanSub();
	afx_msg void OnTranslation();
	afx_msg void OnMirrorHor();
	afx_msg void OnRgbtoHsi();
	afx_msg void OnHsitoRgb();
	afx_msg void OnLightCompensation();
	afx_msg void OnColorImageSegmentation();
	afx_msg void OnHistoEqualColor();
	afx_msg void OnKuwaharaColor();
	afx_msg void OnRotation();
};

#ifndef _DEBUG  // WannaShopView.cpp의 디버그 버전
inline CWannaShopDoc* CWannaShopView::GetDocument() const
   { return reinterpret_cast<CWannaShopDoc*>(m_pDocument); }
#endif

