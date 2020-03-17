
// practice2View.cpp : Cpractice2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "practice2.h"
#endif

#include "practice2Doc.h"
#include "practice2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpractice2View

IMPLEMENT_DYNCREATE(Cpractice2View, CView)

BEGIN_MESSAGE_MAP(Cpractice2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cpractice2View 构造/析构

Cpractice2View::Cpractice2View()
{
	// TODO: 在此处添加构造代码

}

Cpractice2View::~Cpractice2View()
{
}

BOOL Cpractice2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cpractice2View 绘制

void Cpractice2View::OnDraw(CDC* /*pDC*/)
{
	Cpractice2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cpractice2View 打印

BOOL Cpractice2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cpractice2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cpractice2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cpractice2View 诊断

#ifdef _DEBUG
void Cpractice2View::AssertValid() const
{
	CView::AssertValid();
}

void Cpractice2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cpractice2Doc* Cpractice2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cpractice2Doc)));
	return (Cpractice2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cpractice2View 消息处理程序


void Cpractice2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//（2）随机画椭圆
	int a = rand() % 50 + 5;  //短轴
	int b=  rand() % 60 + 8;  //长轴
	CClientDC dc(this);
	CRect cr(point.x - a, point.y - b, point.x + a, point.y + b);
	dc.Ellipse(cr);

	CView::OnLButtonDown(nFlags, point);
}
