
// 3��16�տ���ʵ��View.h : CMy3��16�տ���ʵ��View ��Ľӿ�
//

#pragma once


class CMy3��16�տ���ʵ��View : public CView
{
protected: // �������л�����
	CMy3��16�տ���ʵ��View();
	DECLARE_DYNCREATE(CMy3��16�տ���ʵ��View)

// ����
public:
	CMy3��16�տ���ʵ��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy3��16�տ���ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3��16�տ���ʵ��View.cpp �еĵ��԰汾
inline CMy3��16�տ���ʵ��Doc* CMy3��16�տ���ʵ��View::GetDocument() const
   { return reinterpret_cast<CMy3��16�տ���ʵ��Doc*>(m_pDocument); }
#endif

