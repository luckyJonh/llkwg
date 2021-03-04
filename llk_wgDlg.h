
// llk_wgDlg.h: 头文件
//

#pragma once


// CllkwgDlg 对话框
class CllkwgDlg : public CDialogEx
{
// 构造
public:
	int game_x;
	int game_y;

	CllkwgDlg(CWnd* pParent = nullptr);	// 标准构造函数

	void OnBnClickedOk(); // 启动游戏按钮点击事件接口

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LLK_WG_DIALOG };
#endif
protected:

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
