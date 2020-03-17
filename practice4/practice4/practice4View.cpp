
// practice4View.cpp : Cpractice4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "practice4.h"
#endif

#include "practice4Doc.h"
#include "practice4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpractice4View

IMPLEMENT_DYNCREATE(Cpractice4View, CView)

BEGIN_MESSAGE_MAP(Cpractice4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cpractice4View 构造/析构

Cpractice4View::Cpractice4View()
{
	// TODO: 在此处添加构造代码

}

Cpractice4View::~Cpractice4View()
{
}

BOOL Cpractice4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cpractice4View 绘制

void Cpractice4View::OnDraw(CDC* pDC)
{
	Cpractice4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int a = pDoc->A;
	int b = pDoc->B;
}


// Cpractice4View 打印

BOOL Cpractice4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cpractice4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cpractice4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cpractice4View 诊断

#ifdef _DEBUG
void Cpractice4View::AssertValid() const
{
	CView::AssertValid();
}

void Cpractice4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cpractice4Doc* Cpractice4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cpractice4Doc)));
	return (Cpractice4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cpractice4View 消息处理程序


//void Cpractice4View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnLButtonDown(nFlags, point);
//}


void Cpractice4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cpractice4Doc* pDoc = GetDocument();
	int a = pDoc->A;
	int b = pDoc->B;

	CString s1=_T("A+B=");
	s1.Format(_T("A+B="));
	CString s2;
	s2.Format(_T("%d"), a + b);
	CString s = s1 + s2;
	CClientDC dc(this);
	dc.TextOutW(300, 300, s);


	CView::OnLButtonDown(nFlags, point);
}
