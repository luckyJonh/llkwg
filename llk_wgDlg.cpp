
// llk_wgDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "llk_wg.h"
#include "llk_wgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CllkwgDlg 对话框



CllkwgDlg::CllkwgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LLK_WG_DIALOG, pParent)
	/*, game_x(_T(""))
	, game_y(_T(""))*/
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CllkwgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, game_x);
	DDX_Text(pDX, IDC_EDIT2, game_y);
}

BEGIN_MESSAGE_MAP(CllkwgDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CllkwgDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CllkwgDlg 消息处理程序

BOOL CllkwgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	SetWindowPos(NULL, 300, 300, 600, 300, SWP_NOMOVE);
	ShowWindow(SW_SHOW);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CllkwgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CllkwgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




// 启动游戏按钮 点击事件
void CllkwgDlg::OnBnClickedOk()
{

	RECT  window_rec;
	// 窗口句柄
	HWND game_h = ::FindWindow(NULL, _T("微信"));
	BOOL isGetRec = ::GetWindowRect(game_h, &window_rec);
	if (isGetRec) {
		::MessageBox(game_h, _T("提示："), _T("找到窗口"), NULL);
		this->game_x = window_rec.left;
		this->game_y = window_rec.top;

		UpdateData(false);
		// 设置坐标
		//::setCursorPos()


	}
	::MessageBox(game_h, _T("提示："), _T("未找到窗口"), NULL);
	

}
