#include<afxwin.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#define IDC_PUZZLE 100
#define abs(x) ((x)>0)? (x) : (-1)*(x)
class CPuzzleApp : public CWinApp{
public :
	 virtual BOOL InitInstance();
};
CPuzzleApp ButtonApp;
int nine,cnt=0;//9�� ID�� Ƚ��
CRect *r=new CRect [10];
class CPuzzleWindow: public CFrameWnd{
	CButton* button[9];
	CString *snum;
	CString *answer;
public:	
	CPuzzleWindow();
	afx_msg void HB0();
	afx_msg void HB1();
	afx_msg void HB2();
	afx_msg void HB3();
	afx_msg void HB4();
	afx_msg void HB5();
	afx_msg void HB6();
	afx_msg void HB7();
	afx_msg void HB8();
	afx_msg void HandleButton();
	DECLARE_MESSAGE_MAP()
	void swap(int idc); //�ٲٱ�
	int naver(int, int);//�̿� Ȯ��
	void complete(); // �� Ȯ��
	void Success();
};
void CPuzzleWindow::HB0(){
if(naver(0, nine-100)){
		swap(0),cnt++;
		complete();
}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB1(){
	if(naver(1, nine-100)){
		swap(1),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB2(){
	if(naver(2, nine-100)){
		swap(2),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB3(){
	if(naver(3, nine-100)){
		swap(3),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB4(){
	if(naver(4, nine-100)){
		swap(4),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB5(){
	if(naver(5, nine-100)){
		swap(5),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB6(){
	if(naver(6, nine-100)){
		swap(6),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB7(){
	if(naver(7, nine-100)){
		swap(7),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
void CPuzzleWindow::HB8(){
	if(naver(8, nine-100)){
		swap(8),cnt++;
		complete();
	}
	else
		MessageBeep(-1);
}
BEGIN_MESSAGE_MAP(CPuzzleWindow, CFrameWnd)
	ON_BN_CLICKED(IDC_PUZZLE  ,HB0)
	ON_BN_CLICKED(IDC_PUZZLE+1,HB1)
	ON_BN_CLICKED(IDC_PUZZLE+2,HB2)
	ON_BN_CLICKED(IDC_PUZZLE+3,HB3)
	ON_BN_CLICKED(IDC_PUZZLE+4,HB4)
	ON_BN_CLICKED(IDC_PUZZLE+5,HB5)
	ON_BN_CLICKED(IDC_PUZZLE+6,HB6)
	ON_BN_CLICKED(IDC_PUZZLE+7,HB7)
	ON_BN_CLICKED(IDC_PUZZLE+8,HB8)
END_MESSAGE_MAP()

BOOL CPuzzleApp::InitInstance(){
	m_pMainWnd= new CPuzzleWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CPuzzleWindow::CPuzzleWindow(){
	Create(NULL,_T ("CButton Tests"),WS_OVERLAPPEDWINDOW,CRect(0,0,320,350));
	srand(time(0));
	int num[9],i,j;
	for(i=0;i<9;){
		num[i]=rand()%9+1;
		for(j=0;j<i;j++){
			if(num[i]==num[j])
				break;
		}
		if(j==i) i++;
	}
	snum = new CString[9];	
	for(i=0;i<9;i++)
		snum[i].Format(_T("%d"),num[i]);
	int n=0;
	for(i=5;i<=250;i+=100){
		for(j=5;j<=250;j+=100){
			if(n!=9){
			r[n++].SetRect(j,i,j+100,i+100);}
			else 
				break;
		}
	}
	srand(time(0));
	char t = '9'; 
	for(i=0; i<9;i++){
		button[i]=new CButton();
		if(t!=snum[i])
			button[i]->Create(snum[i],WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON ,r[i],this,IDC_PUZZLE+i);
		else {
			button[i]->Create(snum[i],WS_CHILD | !WS_VISIBLE | BS_PUSHBUTTON ,r[i],this,IDC_PUZZLE+i); 
			nine=IDC_PUZZLE+i;
		}
	}
	//����� �����
	answer = new CString[9];	
	for(i=0;i<9;i++){
		answer[i].Format(_T("%d"),i);
		}
	}
void CPuzzleWindow::swap(int a){
	CRect t=r[a];
	r[a]=r[nine-100];
	r[nine-100]=t;
	button[a]->MoveWindow(r[a].left,r[a].top,100,100);
	button[nine-100]->MoveWindow(r[nine-100].left,r[nine-100].top,100,100);
	//button[a]->MoveWindow(r[a]);
	//button[nine-100]->MoveWindow(r[nine-100]);
} 
int CPuzzleWindow::naver(int idc, int n=nine-100){//�̿� üũ 9�� ����ִ� ĭ�� (x,y,x+100,y+100)
	if((r[idc].left==r[n].left-100) && (r[idc].top==r[n].top))//�� : x-100,y,x,y+100
		return 1;
	else if ((r[idc].top==r[n].top) && (r[n].left+100==r[idc].left))//�� : x+100,y,x+200,y+100
		return 1;
	else if ((r[idc].left==r[n].left) && (r[idc].top==r[n].top-100))//�� : x, y-100, x+100,y
		return 1;
	else if ((r[idc].left==r[n].left) && (r[idc].top==r[n].top+100))//�� : x,y+100,x+100,y+200
		return 1;
	else 
		return 0;
}
void CPuzzleWindow::complete(){
	int i,s,a;
	for(i=0;i<9;i++){
		 s= _ttoi(snum[i]);
		 a=_ttoi(answer[i]);
		if(!(s==a))
			break;
	}
	if(i==9){//�����޼��� ���{
		Success();
	}
}
void CPuzzleWindow::Success(){
	Create(NULL,_T ("CButton Tests"),WS_OVERLAPPEDWINDOW,CRect(100,200,200,400));
	CString count;
	count.Format( _T("%d"),cnt);
	CStatic* cs=new CStatic;
	cs->Create(_T("Congratulation! You solved the puzzle with ")+count+_T("times!"),WS_CHILD| WS_VISIBLE | SS_CENTER,CRect(130,100,200,400),this);
}