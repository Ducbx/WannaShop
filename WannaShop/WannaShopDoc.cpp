
// WannaShopDoc.cpp : CWannaShopDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CWannaShopDoc ����/�Ҹ�

CWannaShopDoc::CWannaShopDoc()
	: OutputImage(NULL)
	, m_Re_width(0)
	, m_Re_height(0)
	, m_Re_size(0)
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CWannaShopDoc::~CWannaShopDoc()
{
}

BOOL CWannaShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}





// CWannaShopDoc serialization

void CWannaShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CWannaShopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CWannaShopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CWannaShopDoc ����

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


// CWannaShopDoc ���


BOOL CWannaShopDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	
	CFile File;
	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);

	if (File.GetLength() == 256 * 256) {
		m_height = 256;
		m_width = 256;
	} else if (File.GetLength() == 512 * 512) {
		m_height = 512;
		m_width = 512;
	} else if (File.GetLength() == 640 * 480) {
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CFile File;

	File.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite);
	File.Write(m_outputImage, m_reSize);
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

		for ( i = 0; i < m_height; i++)
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
		
		for ( i = 0; i < m_size; i++)
		{
			for (j = 0; j < value; j++) {
				if (m_inputImage[i] >= (LEVEL/value)*j &&
					m_inputImage[i] < (LEVEL/value)*(j+1))
				{
					TEMP[i] = (double)(HIGH / value)*j; // Do Quantization
				}
			}
		}

		for ( i = 0; i < m_size; i++)
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

		for ( i = 0; i < m_size; i++)
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
