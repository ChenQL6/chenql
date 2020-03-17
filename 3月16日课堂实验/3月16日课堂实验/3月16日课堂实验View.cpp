
// 3月16日课堂实验View.cpp : CMy3月16日课堂实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3月16日课堂实验.h"
#endif

#include "3月16日课堂实验Doc.h"
#include "3月16日课堂实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3月16日课堂实验View

IMPLEMENT_DYNCREATE(CMy3月16日课堂实验View, CView)

BEGIN_MESSAGE_MAP(CMy3月16日课堂实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy3月16日课堂实验View 构造/析构

CMy3月16日课堂实验View::CMy3月16日课堂实验View()
{
	// TODO: 在此处添加构造代码

}

CMy3月16日课堂实验View::~CMy3月16日课堂实验View()
{
}

BOOL CMy3月16日课堂实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3月16日课堂实验View 绘制

void CMy3月16日课堂实验View::OnDraw(CDC* pDC)
{
	CMy3月16日课堂实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy3月16日课堂实验View 打印

BOOL CMy3月16日课堂实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3月16日课堂实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy3月16日课堂实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy3月16日课堂实验View 诊断

#ifdef _DEBUG
void CMy3月16日课堂实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3月16日课堂实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3月16日课堂实验Doc* CMy3月16日课堂实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3月16日课堂实验Doc)));
	return (CMy3月16日课堂实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3月16日课堂实验View 消息处理程序


void CMy3月16日课堂实验View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy3月16日课堂实验Doc*pDoc = GetDocument();
		pDoc->m_tagRec.left = point.x;
		pDoc->m_tagRec.top = point.y;

	CView::OnLButtonDown(nFlags, point);
}



void CMy3月16日课堂实验View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy3月16日课堂实验Doc*pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x;
	pDoc->m_tagRec.bottom = point.y;
	InvalidateRect(NULL, TRUE);

	CView::OnLButtonUp(nFlags, point);
}


void CMy3月16日课堂实验View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("X=%d,Y=%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(10, 10, s);
	CView::OnMouseMove(nFlags, point);
}
