
// 3��16�տ���ʵ��.h : 3��16�տ���ʵ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy3��16�տ���ʵ��App:
// �йش����ʵ�֣������ 3��16�տ���ʵ��.cpp
//

class CMy3��16�տ���ʵ��App : public CWinApp
{
public:
	CMy3��16�տ���ʵ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy3��16�տ���ʵ��App theApp;
