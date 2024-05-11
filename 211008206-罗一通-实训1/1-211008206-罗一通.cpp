// MFCView.cpp: CMFCView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC.h"
#endif

#include "MFCDoc.h"
#include "MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CView)

BEGIN_MESSAGE_MAP(CMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCView 构造/析构

CMFCView::CMFCView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCView::~CMFCView()
{
}

BOOL CMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCView 绘图




// CMFCView 打印

BOOL CMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCView 诊断

#ifdef _DEBUG
void CMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDoc* CMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDoc)));
	return (CMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCView 消息处理程序

CPoint point1, point2;
void CMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//point1 = point;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{

	

	
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*
	P1 =point;
	CDC* pDC = GetDC();
	CPen Newpen, *poldPen;
	Newpen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	poldPen = pDC->SelectObject(&Newpen);
	
	//pDC->MoveTo(P0);
	//pDC->LineTo(P1);
	CBrush newbrush, * poldbrush;
	newbrush.CreateSolidBrush(RGB(0, 0, 0));
	poldbrush=pDC->SelectObject(&newbrush);
	pDC->Rectangle(CRect(P0, P1));		
		
	
		
		
	//S1.SetRect(P0, P1);

	int size = 10;
	int x = 10;*/
	/*
	for (int i = 0; i < x; i++) {
		Newpen.CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		p01dPen = pDC->SelectObject(&Newpen);
		P0.SetPoint(0,i * size);
		P1.SetPoint(19*size,i * size);

		pDC->MoveTo(P0);
		pDC->LineTo(P1);
		pDC->Rectangle(CRect(P0, P1));
	}
	*/
	
	
	
	/*
	CDC* pDC = GetDC();
	CPen Newpen, * poldPen;
	Newpen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	poldPen = pDC->SelectObject(&Newpen);
	CBrush newbrush, * poldbrush;
	for (int n = 0; n < 19*19; n++) {
			int size = 10;
			point1.SetPoint(n % 19 * size, n/19 * size);
			point2.SetPoint(n % 19 * size+size, n / 19 * size+size);
			
			
			
			if (n%2 == 0) {
				newbrush.CreateSolidBrush(RGB(0, 0, 0));
				poldbrush = pDC->SelectObject(&newbrush);

			}
			else if(n%2==1) {
				
				newbrush.CreateSolidBrush(RGB(255, 255, 255));
				poldbrush = pDC->SelectObject(&newbrush);

				
			}
			pDC->Rectangle(CRect(point1, point2));
			ReleaseDC(pDC);
			Newpen.DeleteObject();
			newbrush.DeleteObject();
		
	}

	
	
	//pDC->MoveTo(P0);
	//pDC->LineTo(P1);


	*/
	CView::OnLButtonDown(nFlags, point);
}
// CChessBoardView.h  

class CChessBoardView : public CView
{
	// ... 其他成员函数和变量 ...  

protected:
	//{{AFX_MSG(CChessBoardView)  
	afx_msg void OnDraw(CDC* pDC);
	//}}AFX_MSG  
	DECLARE_MESSAGE_MAP()
};

// CChessBoardView.cpp  



// ...  



// CChessBoardView 消息处理程序  

void CMFCView::OnDraw(CDC* pDC)
{
	CMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码  

	// 定义方格大小  
	int squareSize = 50;
	int boardWidth = squareSize * 10;
	int boardHeight = squareSize * 10;

	// 绘制棋盘背景（可选）  
	CBrush bkBrush(RGB(0, 0, 0)); // 黑色背景  
	CBrush* pOldBrush = pDC->SelectObject(&bkBrush);
	pDC->Rectangle(0, 0, boardWidth, boardHeight);
	pDC->SelectObject(pOldBrush);

	// 绘制棋盘方格  
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// 计算方格左上角坐标  
			int x = j * squareSize;
			int y = i * squareSize;

			// 根据方格位置决定颜色（黑白交替）  
			if ((i + j) % 2 == 0)
			{
				// 绘制浅色方格  
				CBrush lightBrush(RGB(255, 255, 255)); // 白色  
				pOldBrush = pDC->SelectObject(&lightBrush);
				pDC->Rectangle(x, y, x + squareSize, y + squareSize);
				pDC->SelectObject(pOldBrush);
			}
			else
			{
				// 绘制深色方格  
				CBrush darkBrush(RGB(0, 0, 0)); // 深色  
				pOldBrush = pDC->SelectObject(&darkBrush);
				pDC->Rectangle(x, y, x + squareSize, y + squareSize);
				pDC->SelectObject(pOldBrush);
			}
		}
	}

	// 如果有棋子，可以在这里添加绘制棋子的代码  

	// 不需要调用 CView::OnDraw() 进行默认绘制  
}

// ...
