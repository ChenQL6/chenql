
// 3��16�տ���ʵ��View.cpp : CMy3��16�տ���ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3��16�տ���ʵ��.h"
#endif

#include "3��16�տ���ʵ��Doc.h"
#include "3��16�տ���ʵ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3��16�տ���ʵ��View

IMPLEMENT_DYNCREATE(CMy3��16�տ���ʵ��View, CView)

BEGIN_MESSAGE_MAP(CMy3��16�տ���ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy3��16�տ���ʵ��View ����/����

CMy3��16�տ���ʵ��View::CMy3��16�տ���ʵ��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy3��16�տ���ʵ��View::~CMy3��16�տ���ʵ��View()
{
}

BOOL CMy3��16�տ���ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3��16�տ���ʵ��View ����

void CMy3��16�տ���ʵ��View::OnDraw(CDC* pDC)
{
	CMy3��16�տ���ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy3��16�տ���ʵ��View ��ӡ

BOOL CMy3��16�տ���ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3��16�տ���ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3��16�տ���ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy3��16�տ���ʵ��View ���

#ifdef _DEBUG
void CMy3��16�տ���ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3��16�տ���ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3��16�տ���ʵ��Doc* CMy3��16�տ���ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3��16�տ���ʵ��Doc)));
	return (CMy3��16�տ���ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3��16�տ���ʵ��View ��Ϣ�������


void CMy3��16�տ���ʵ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy3��16�տ���ʵ��Doc*pDoc = GetDocument();
		pDoc->m_tagRec.left = point.x;
		pDoc->m_tagRec.top = point.y;

	CView::OnLButtonDown(nFlags, point);
}



void CMy3��16�տ���ʵ��View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy3��16�տ���ʵ��Doc*pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x;
	pDoc->m_tagRec.bottom = point.y;
	InvalidateRect(NULL, TRUE);

	CView::OnLButtonUp(nFlags, point);
}


void CMy3��16�տ���ʵ��View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	s.Format(_T("X=%d,Y=%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(10, 10, s);
	CView::OnMouseMove(nFlags, point);
}
