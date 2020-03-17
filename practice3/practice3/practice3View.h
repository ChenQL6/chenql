
// practice3View.h : Cpractice3View 类的接口
//

#pragma once


class Cpractice3View : public CView
{
protected: // 仅从序列化创建
	Cpractice3View();
	DECLARE_DYNCREATE(Cpractice3View)

// 特性
public:
	Cpractice3Doc* GetDocument() const;

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
	virtual ~Cpractice3View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // practice3View.cpp 中的调试版本
inline Cpractice3Doc* Cpractice3View::GetDocument() const
   { return reinterpret_cast<Cpractice3Doc*>(m_pDocument); }
#endif

