
// practice2View.h : Cpractice2View 类的接口
//

#pragma once


class Cpractice2View : public CView
{
protected: // 仅从序列化创建
	Cpractice2View();
	DECLARE_DYNCREATE(Cpractice2View)

// 特性
public:
	Cpractice2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cpractice2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // practice2View.cpp 中的调试版本
inline Cpractice2Doc* Cpractice2View::GetDocument() const
   { return reinterpret_cast<Cpractice2Doc*>(m_pDocument); }
#endif

