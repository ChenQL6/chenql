
// 3��16�տ���ʵ��Doc.cpp : CMy3��16�տ���ʵ��Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3��16�տ���ʵ��.h"
#endif

#include "3��16�տ���ʵ��Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy3��16�տ���ʵ��Doc

IMPLEMENT_DYNCREATE(CMy3��16�տ���ʵ��Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy3��16�տ���ʵ��Doc, CDocument)
END_MESSAGE_MAP()


// CMy3��16�տ���ʵ��Doc ����/����

CMy3��16�տ���ʵ��Doc::CMy3��16�տ���ʵ��Doc()
{
	// TODO: �ڴ����һ���Թ������
	m_tagRec.left = 30;   m_tagRec.top = 30;
	m_tagRec.right = 350; m_tagRec.bottom = 300;
}

CMy3��16�տ���ʵ��Doc::~CMy3��16�տ���ʵ��Doc()
{
}

BOOL CMy3��16�տ���ʵ��Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy3��16�տ���ʵ��Doc ���л�

void CMy3��16�տ���ʵ��Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy3��16�տ���ʵ��Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CMy3��16�տ���ʵ��Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy3��16�տ���ʵ��Doc::SetSearchContent(const CString& value)
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

// CMy3��16�տ���ʵ��Doc ���

#ifdef _DEBUG
void CMy3��16�տ���ʵ��Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy3��16�տ���ʵ��Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy3��16�տ���ʵ��Doc ����
