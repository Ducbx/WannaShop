﻿
// WannaShopDoc.cpp : CWannaShopDoc Å¬·¡½ºÀÇ ±¸Çö
//

#include "stdafx.h"
// SHARED_HANDLERS´Â ¹Ì¸® º¸±â, Ãà¼ÒÆÇ ±×¸² ¹× °Ë»ö ÇÊÅÍ Ã³¸®±â¸¦ ±¸ÇöÇÏ´Â ATL ÇÁ·ÎÁ§Æ®¿¡¼­ Á¤ÀÇÇÒ ¼ö ÀÖÀ¸¸ç
// ÇØ´ç ÇÁ·ÎÁ§Æ®¿Í ¹®¼­ ÄÚµå¸¦ °øÀ¯ÇÏµµ·Ï ÇØ ÁÝ´Ï´Ù.
#ifndef SHARED_HANDLERS
#include "WannaShop.h"
#endif

#include "WannaShopDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWannaShopDoc

IMPLEMENT_DYNCREATE(CWannaShopDoc, CDocument)

BEGIN_MESSAGE_MAP(CWannaShopDoc, CDocument)
END_MESSAGE_MAP()


// CWannaShopDoc »ý¼º/¼Ò¸ê

CWannaShopDoc::CWannaShopDoc()
	: OutputImage(NULL)
	, m_Re_width(0)
	, m_Re_height(0)
	, m_Re_size(0)
	, m_tempImage(NULL)
{
	// TODO: ¿©±â¿¡ ÀÏÈ¸¼º »ý¼º ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.

}

CWannaShopDoc::~CWannaShopDoc()
{
}

BOOL CWannaShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ¿©±â¿¡ ÀçÃÊ±âÈ­ ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	// SDI ¹®¼­´Â ÀÌ ¹®¼­¸¦ ´Ù½Ã »ç¿ëÇÕ´Ï´Ù.

	return TRUE;
}





// CWannaShopDoc serialization

void CWannaShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ¿©±â¿¡ ÀúÀå ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	}
	else
	{
		// TODO: ¿©±â¿¡ ·Îµù ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	}
}

#ifdef SHARED_HANDLERS

// Ãà¼ÒÆÇ ±×¸²À» Áö¿øÇÕ´Ï´Ù.
void CWannaShopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ¹®¼­ÀÇ µ¥ÀÌÅÍ¸¦ ±×¸®·Á¸é ÀÌ ÄÚµå¸¦ ¼öÁ¤ÇÏ½Ê½Ã¿À.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// °Ë»ö Ã³¸®±â¸¦ Áö¿øÇÕ´Ï´Ù.
void CWannaShopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ¹®¼­ÀÇ µ¥ÀÌÅÍ¿¡¼­ °Ë»ö ÄÜÅÙÃ÷¸¦ ¼³Á¤ÇÕ´Ï´Ù.
	// ÄÜÅÙÃ÷ ºÎºÐÀº ";"·Î ±¸ºÐµÇ¾î¾ß ÇÕ´Ï´Ù.

	// ¿¹: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWannaShopDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWannaShopDoc Áø´Ü

#ifdef _DEBUG
void CWannaShopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWannaShopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWannaShopDoc ¸í·É


BOOL CWannaShopDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ¿©±â¿¡ Æ¯¼öÈ­µÈ ÀÛ¼º ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.

	CFile File;
	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);

	if (File.GetLength() == 256 * 256) {
		m_height = 256;
		m_width = 256;
	}
	else if (File.GetLength() == 512 * 512) {
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640 * 480) {
		m_height = 640;
		m_width = 480;
	}
	else {
		//AfxMessageBox("Not support");
		return 0;
	}

	m_size = m_height * m_width;
	m_inputImage = new unsigned char[m_size];

	for (int i = 0; i < m_size; i++) {
		m_inputImage[i] = 255;
	}
	File.Read(m_inputImage, m_size);
	File.Close();


	return TRUE;
}


BOOL CWannaShopDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ¿©±â¿¡ Æ¯¼öÈ­µÈ ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº» Å¬·¡½º¸¦ È£ÃâÇÕ´Ï´Ù.
	CFile File;

	File.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite);
	File.Write(m_outputImage, m_Re_size);
	File.Close();

	return true;
}

void CWannaShopDoc::OnDownSampling() {
	int i, j;
	CSamplingDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_Re_height = m_height / dlg.m_SamplingRate;
		m_Re_width = m_width / dlg.m_SamplingRate;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];
		for (i = 0; i < m_Re_height; i++)
		{
			for (j = 0; j < m_Re_width; j++) {
				m_outputImage[i*m_Re_width + j]
					= m_inputImage[(i*dlg.m_SamplingRate*m_width) + dlg.m_SamplingRate*j];
			}
		}
	}
}




void CWannaShopDoc::OnUpSampling()
{
	int i, j;
	CSamplingDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_Re_height = m_height * dlg.m_SamplingRate;
		m_Re_width = m_width * dlg.m_SamplingRate;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];

		for (i = 0; i < m_Re_size; i++)
		{
			m_outputImage[i] = 255;
		}

		for (i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_outputImage[i*dlg.m_SamplingRate*m_Re_width +
					dlg.m_SamplingRate*j] = m_inputImage[(i*m_width) + j];
			}
		}
	}
}


void CWannaShopDoc::OnQuantization()
{
	CQuantizationDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		int i, j, value, LEVEL;
		double HIGH, *TEMP;

		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];
		TEMP = new double[m_size];

		LEVEL = 256; //Quantization level of input image
		HIGH = 256.;

		value = (int)pow(2, dlg.m_QuantBit);

		for (i = 0; i < m_size; i++)
		{
			for (j = 0; j < value; j++) {
				if (m_inputImage[i] >= (LEVEL / value)*j &&
					m_inputImage[i] < (LEVEL / value)*(j + 1))
				{
					TEMP[i] = (double)(HIGH / value)*j; // Do Quantization
				}
			}
		}

		for (i = 0; i < m_size; i++)
		{
			m_outputImage[i] = (unsigned char)TEMP[i];
		}
	}
}


void CWannaShopDoc::OnMenuSumConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] + dlg.m_Constant >= 255)
			{
				m_outputImage[i] = 255;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] + dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuSubConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] - dlg.m_Constant < 0)
			{
				m_outputImage[i] = 0;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] - dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuMulConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] * dlg.m_Constant > 255)
			{
				m_outputImage[i] = 255;
			}
			else if (m_inputImage[i] * dlg.m_Constant < 0)
			{
				m_outputImage[i] = 0;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] * dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuDivConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] / dlg.m_Constant > 255)
			{
				m_outputImage[i] = 255;
			}
			else if (m_inputImage[i] / dlg.m_Constant < 0)
			{
				m_outputImage[i] = 0;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] / dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuNegaConstant()
{
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_size; i++)
	{
		m_outputImage[i] = 255 - m_inputImage[i];
	}
}


void CWannaShopDoc::OnMenuGammaCorrection()
{
	CConstantDlg dlg;

	int i;
	double temp;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		unsigned char* LUT = new unsigned char[256];

		for (i = 0; i < 256; i++)
		{
			temp = pow(i, 1 / dlg.m_Constant);
			LUT[i] = temp > 255 ? 255 : temp;
		}

		for (i = 0; i < m_size; i++)
		{
			m_outputImage[i] = LUT[m_inputImage[i]];
		}
	}
}

void CWannaShopDoc::OnMenuBinarization()
{
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] >= dlg.m_Constant)
			{
				m_outputImage[i] = 255;
			}
			else {
				m_outputImage[i] = 0;
			}
		}
	}
}


void CWannaShopDoc::OnMenuHistogram()
{
	int i, j;
	int MAX;
	int Histo[256];

	// Set histogram size
	m_Re_height = 256;
	m_Re_width = 256;
	m_Re_size = m_Re_height*m_Re_width;

	// init
	for (i = 0; i < 256; i++)
	{
		Histo[i] = 0;
	}

	for (i = 0; i < m_size; i++)
	{
		Histo[m_inputImage[i]]++;
	}

	// Generalazation
	MAX = Histo[0];
	for (i = 0; i < 256; i++)
	{
		if (Histo[i] > MAX) {
			MAX = Histo[i];
		}
	}
	for (i = 0; i < 256; i++)
	{
		Histo[i] = (int)(Histo[i] * 255 / MAX);
	}

	m_outputImage = new unsigned char[m_Re_size + (258 * 20)];
	for (i = 0; i < m_Re_size; i++)
	{
		m_outputImage[i] = 255;
	}
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < Histo[i]; j++) {
			m_outputImage[m_Re_width*(m_Re_height - j - 1) + i] = 0;
		}
	}
	for (i = m_Re_height; i < m_Re_height + 5; i++)
	{
		for (j = 0; j < 256; j++) {
			m_outputImage[m_Re_height*i + j] = 255;
		}
	}
	for (i = m_Re_height + 5; i < m_Re_height + 20; i++)
	{
		for (j = 0; j < 256; j++) {
			m_outputImage[m_Re_height*i + j] = j;
		}
	}

	m_Re_height = m_Re_height + 20;
	m_Re_size = m_Re_width * m_Re_height;
}


void CWannaShopDoc::OnMenuHistoStretch()
{
	int i;
	unsigned char LOW, HIGH, MAX, MIN;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	MIN = m_inputImage[0];
	MAX = m_inputImage[0];

	for (i = 0; i < m_size; i++)
	{
		if (m_inputImage[i] < MIN) {
			MIN = m_inputImage[i];
		}
	}
	for (i = 0; i < m_size; i++)
	{
		if (m_inputImage[i] > MAX) {
			MAX = m_inputImage[i];
		}
	}
	m_outputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_size; i++)
	{
		m_outputImage[i] = (unsigned char)((m_inputImage[i] - MIN)*HIGH / (MAX - MIN));
	}
}


void CWannaShopDoc::OnMenuHistoEqual()
{
	int i, value;
	unsigned char LOW, HIGH, Temp;
	double SUM = 0.0;
	double* m_HIST = new double[256];
	double* m_Sum_Of_HIST = new double[256];

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0; HIGH = 255;
	// 초기화 
	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;

	// 빈도 수 조사 
	for (i = 0; i < m_size; i++) {
		value = (int)m_inputImage[i];
		m_HIST[value]++;
	}

	// 누적 히스토그램 생성 
	for (i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
	}

	m_outputImage = new unsigned char[m_Re_size];

	// 입력 영상을 평활화된 영상으로 출력 
	for (i = 0; i < m_size; i++) {
		Temp = m_inputImage[i];
		m_outputImage[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
	}
}


void CWannaShopDoc::OnMenuEmbossing()
{
	int i, j;
	double EmboMask[3][3] = { {-1,0,0},{0,0,0},{0,0,1} };
	//Choose mask
	//double EmboMask[3][3] = { {0,0,0},{0,1,0},{0,0,0} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height*m_Re_width;
	m_outputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_inputImage, EmboMask);
	//회선 처리
	printf("%ld", m_tempImage[1][2]);
	printf("%ld", m_tempImage[1][3]);
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255)
			{
				m_tempImage[i][j] = 255;
			}
			else if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}

	//m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
	// 정규화 함수를 사용할 때

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++) {
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


double** CWannaShopDoc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
{
	int i, j, n, m;
	double **tempInputImage, **tempOutputImage, S = 0.0;
	tempInputImage = Image2DMem(m_height + 2, m_width + 2);
	tempOutputImage = Image2DMem(m_height, m_width);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)Target[i * m_width + j];
		}
	}
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			for (n = 0; n < 3; n++) {
				for (m = 0; m < 3; m++) {
					S += Mask[n][m] * tempInputImage[i + n][j + m];
				}
			}  tempOutputImage[i][j] = S;
			S = 0.0;
		}
	}

	return tempOutputImage; // 결과 값 반환
}


double** CWannaShopDoc::OnScale(double **Target, int height, int width)
{
	int i, j; double min, max;
	min = max = Target[0][0];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] <= min) min = Target[i][j];
		}
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] >= max) max = Target[i][j];
		}
	}
	max = max - min;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			Target[i][j] = (Target[i][j] - min) * (255. / max);
		}
	}
	return Target;
}

double** CWannaShopDoc::Image2DMem(int height, int width)
{
	double** temp;
	int i, j;
	temp = new double *[height];
	for (i = 0; i < height; i++) {
		temp[i] = new double[width];
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			temp[i][j] = 0.0;
		}
	}

	return temp;
}


void CWannaShopDoc::OnMenuBlurr()
{
	int i, j;
	double BlurrMask[3][3] = { {1. / 9., 1. / 9., 1. / 9.},{ 1. / 9., 1. / 9., 1. / 9. },{ 1. / 9., 1. / 9., 1. / 9. } };

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_inputImage, BlurrMask);

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			if (m_tempImage[i][j] > 255) {
				m_tempImage[i][j] = 255;
			}
			if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CWannaShopDoc::OnMenuGaussianFilter()
{
	int i, j;
	double GaussianMask[3][3] = { {1. / 16., 1. / 8., 1. / 16.},{ 1. / 8., 1. / 4., 1. / 8. },{ 1. / 16., 1. / 8., 1. / 16. } };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height*m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_inputImage, GaussianMask);

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			if (m_tempImage[i][j] > 255) {
				m_tempImage[i][j] = 255;
			}
			if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CWannaShopDoc::OnMenuSharpening()
{
	int i, j;
	double SharpeningMask[3][3] = { {-1.,-1.,-1.}, {-1.,9.,-1.}, {-1.,-1. - 1.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height*m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_inputImage, SharpeningMask);

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			if (m_tempImage[i][j] > 255) {
				m_tempImage[i][j] = 255;
			}
			if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CWannaShopDoc::OnMenuMedianFilter()
{
	
}
