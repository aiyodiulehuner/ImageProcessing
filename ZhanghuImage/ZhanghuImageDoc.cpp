
// ZhanghuImageDoc.cpp: CZhanghuImageDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZhanghuImage.h"
#endif

#include "ZhanghuImageDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZhanghuImageDoc

IMPLEMENT_DYNCREATE(CZhanghuImageDoc, CDocument)

BEGIN_MESSAGE_MAP(CZhanghuImageDoc, CDocument)
	ON_COMMAND(ID_OpenImage, &CZhanghuImageDoc::OnOpenimage)
	ON_COMMAND(ID_OpenImage, &CZhanghuImageDoc::OnOpenimage)
END_MESSAGE_MAP()


// CZhanghuImageDoc 构造/析构

CZhanghuImageDoc::CZhanghuImageDoc()
{
	// TODO: 在此添加一次性构造代码
	m_pCurBitmap = NULL;
	m_pSecondBitmap = NULL;
}

CZhanghuImageDoc::~CZhanghuImageDoc()
{
	if (NULL != m_pCurBitmap) {
		delete m_pCurBitmap;
		m_pCurBitmap = NULL;
	}

	if (NULL != m_pSecondBitmap) {
		delete m_pSecondBitmap;
		m_pSecondBitmap = NULL;
	}
}

BOOL CZhanghuImageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CZhanghuImageDoc 序列化

void CZhanghuImageDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CZhanghuImageDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CZhanghuImageDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CZhanghuImageDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CZhanghuImageDoc 诊断

#ifdef _DEBUG
void CZhanghuImageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZhanghuImageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CZhanghuImageDoc 命令




void CZhanghuImageDoc::OnOpenimage()
{
	// TODO: 在此添加命令处理程序代码
	// 设置过滤器       
	TCHAR szFilter[] = _T("图像(*.bmp)|*.bmp|所有文件(*.*)|*.*||");
	// 构造打开文件对话框    
	CFileDialog fileDlg(TRUE, _T(""), NULL, 0, szFilter);
	CString strFilePath;          // 显示打开文件对话框      
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里
		strFilePath = fileDlg.GetPathName();
		//SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
		m_pCurBitmap = Bitmap::FromFile(strFilePath);
		int w = m_pCurBitmap->GetWidth();
		int h = m_pCurBitmap->GetHeight();
		this->UpdateAllViews(NULL);
	}
}
