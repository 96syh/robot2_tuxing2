
// shixun22View.cpp: Cshixun22View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "shixun22.h"
#endif

#include "shixun22Doc.h"
#include "shixun22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cshixun22View

IMPLEMENT_DYNCREATE(Cshixun22View, CView)

BEGIN_MESSAGE_MAP(Cshixun22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cshixun22View 构造/析构

Cshixun22View::Cshixun22View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cshixun22View::~Cshixun22View()
{
}

BOOL Cshixun22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cshixun22View 绘图

void Cshixun22View::OnDraw(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);

	int cellWidth = rect.Width() / 10;
	int cellHeight = rect.Height() / 10;

	COLORREF color1 = RGB(255, 255, 255); // 白色
	COLORREF color2 = RGB(0, 0, 0); // 黑色

	COLORREF currentColor = color1;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			CBrush brush(currentColor);
			pDC->SelectObject(&brush);

			pDC->Rectangle(i * cellWidth, j * cellHeight, (i + 1) * cellWidth, (j + 1) * cellHeight);

			currentColor = (currentColor == color1) ? color2 : color1;
		}

		currentColor = (currentColor == color1) ? color2 : color1; // 每行结束后颜色交替
	}
}

// Cshixun22View 打印

BOOL Cshixun22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cshixun22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cshixun22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cshixun22View 诊断

#ifdef _DEBUG
void Cshixun22View::AssertValid() const
{
	CView::AssertValid();
}

void Cshixun22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cshixun22Doc* Cshixun22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cshixun22Doc)));
	return (Cshixun22Doc*)m_pDocument;
}
#endif //_DEBUG


// Cshixun22View 消息处理程序


void Cshixun22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


void Cshixun22View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}
