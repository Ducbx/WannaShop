
// WannaShopView.cpp : CWannaShopView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "WannaShop.h"
#endif

#include "MainFrm.h"
#include "WannaShopDoc.h"
#include "WannaShopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWannaShopView

IMPLEMENT_DYNCREATE(CWannaShopView, CView)

BEGIN_MESSAGE_MAP(CWannaShopView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Menu_Down_Sampling, &CWannaShopView::OnMenuDownSampling)
	ON_COMMAND(ID_Menu_Up_Sampling, &CWannaShopView::OnMenuUpSampling)
	ON_COMMAND(ID_Menu_Quantization, &CWannaShopView::OnMenuQuantization)
	ON_COMMAND(ID_Sum_Constant, &CWannaShopView::OnSumConstant)
	ON_COMMAND(ID_Sub_Constant, &CWannaShopView::OnSubConstant)
	ON_COMMAND(ID_Mul_Constant, &CWannaShopView::OnMulConstant)
	ON_COMMAND(ID_Div_Constant, &CWannaShopView::OnDivConstant)
	ON_COMMAND(ID_Nega_Transform, &CWannaShopView::OnNegaTransform)
	ON_COMMAND(ID_Gamma_Correction, &CWannaShopView::OnGammaCorrection)
	ON_COMMAND(ID_Binarization, &CWannaShopView::OnBinarization)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWannaShopView ����/�Ҹ�

CWannaShopView::CWannaShopView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWannaShopView::~CWannaShopView()
{
}

BOOL CWannaShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWannaShopView �׸���

void CWannaShopView::OnDraw(CDC* pDC)
{
	CWannaShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int i, j;
	unsigned char R, G, B;
	for (i = 0; i < pDoc->m_height; i++)
	{
		for (j = 0; j < pDoc->m_width; j++) {
			R = G = B = pDoc->m_inputImage[i*pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	for (i = 0; i < pDoc->m_Re_height; i++)
	{
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = G = B = pDoc->m_outputImage[i*pDoc->m_Re_width + j];
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWannaShopView �μ�

BOOL CWannaShopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CWannaShopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CWannaShopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CWannaShopView ����

#ifdef _DEBUG
void CWannaShopView::AssertValid() const
{
	CView::AssertValid();
}

void CWannaShopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWannaShopDoc* CWannaShopView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWannaShopDoc)));
	return (CWannaShopDoc*)m_pDocument;
}
#endif //_DEBUG




// CWannaShopView �޽��� ó����


void CWannaShopView::OnMenuDownSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling();

	Invalidate(TRUE);
}


void CWannaShopView::OnMenuUpSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling();

	Invalidate(TRUE);
}


void CWannaShopView::OnMenuQuantization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization();

	Invalidate(TRUE);
}


void CWannaShopView::OnSumConstant()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSumConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnSubConstant()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSubConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnMulConstant()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuMulConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnDivConstant()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuDivConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnNegaTransform()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuNegaConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnGammaCorrection()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuGammaCorrection();

	Invalidate(TRUE);
}


void CWannaShopView::OnBinarization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuBinarization();

	Invalidate(TRUE);
}

void CWannaShopView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CWannaShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (point.x > 5 && point.x < pDoc->m_width
	&& point.y > 5 && point.y < pDoc->m_height)
	{
		CString str;
		int x=point.x, y=point.y;
		unsigned char pixelValue;
		pixelValue = pDoc->m_inputImage[x*y];

		str.Format(L"X ��ǥ : %d Y��ǥ : %d �ȼ� : %d", x, y, pixelValue);

		((CMainFrame*)AfxGetMainWnd())->GetStatusBar()->SetPaneText(0, str);
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CWannaShopView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CWannaShopDoc* pDoc = GetDocument();
	int avg, sum = 0, min=255, max=0;
	int width, height;
	int size;
	int i, j;
	CString contentsStr;

	width = pDoc->m_width;
	height = pDoc->m_height;
	size = width*height;

	for (i = 0; i < size; i++)
	{
		int currentPixel = pDoc->m_inputImage[i];
		sum += currentPixel; /* sum for avg */

		if (currentPixel <= min) /* Check min */
		{
			min = currentPixel;
		}
		if (currentPixel >= max) /* Check max */
		{
			max = currentPixel;
		}
	}

	avg = sum / size;
	contentsStr.Format(L"�ּҰ��� %d�Դϴ�.\n�ִ밪�� %d�Դϴ�.\n��հ��� %d�Դϴ�.", min, max, avg);
	MessageBox(contentsStr, L"�� �˸�", MB_ICONINFORMATION);

	CView::OnLButtonDown(nFlags, point);
}
