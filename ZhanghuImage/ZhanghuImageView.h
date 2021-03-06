
// ZhanghuImageView.h: CZhanghuImageView 类的接口
//

#pragma once

#include "resource.h"

class CZhanghuImageView : public CView
{
protected: // 仅从序列化创建
	CZhanghuImageView();
	DECLARE_DYNCREATE(CZhanghuImageView)

// 特性
public:
	CZhanghuImageDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);


// 实现
public:
	virtual ~CZhanghuImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
public:
	afx_msg void OnHistequal();
	afx_msg void OnSmoothing();
	afx_msg void OnSharping();
	afx_msg void OnFft();
	afx_msg void OnFunlengt();
	afx_msg void OnEncode();
};

#ifndef _DEBUG  // ZhanghuImageView.cpp 中的调试版本
inline CZhanghuImageDoc* CZhanghuImageView::GetDocument() const
   { return reinterpret_cast<CZhanghuImageDoc*>(m_pDocument); }
#endif

