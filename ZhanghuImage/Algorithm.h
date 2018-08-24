#pragma once
#include"math.h"  
#include <complex>
#define PI 3.1415926535897932384626  
using namespace std;
class Algorithm
{
public:
	Algorithm(Bitmap* pCurBitmap);
	~Algorithm(void);

	Bitmap* m_pCurBitmap;
	BYTE*  m_pGrayData;
	int    m_Width;
	int    m_Height;


	bool ImageSmoothingSharping(double* pTemp, int sz, Bitmap*& pBitmap);
	bool HistEqual(Bitmap*& pBitmap);

	bool FFT2D(Bitmap*& pBitmap);

	bool RunlengthCode(CString filename);

	bool RunlengthRecode(CString filename, Bitmap*& pBitmap);

private:
	bool GrayData2Bitmap(BYTE* pGrayData, Bitmap*& pBitmap);

	bool Hist(double*& hist);

	bool RGBData2Bitmap(BYTE* pRGBData, Bitmap*& pBitmap);

	complex<double> * DataFitFormat(unsigned char *data, int lWidth, int lHeight);//������ת��Ϊ�ʺ�FFT��������ݣ����鳤��Ϊ2���������ݣ�,�������ݲ������.��lHeight=1ʱ��ʾΪ��һά���鴦��.dataΪ�Զ�ά���ݵ�һά��ʾ���ǰ��մ����ң����ϵ��¡� 
	void InitTDAndFD(complex<double> *&TD, complex<double> *&FD, unsigned char *data, int lWidth, int lHeight, int &w, int &h);//��ʼ��TD��FD(FFT����)
	void FFT_1D(complex<double> *&TD, complex<double>*&FD, int Len);//һάFFT���㣬lenΪһά�������ʵ���ȡ���TD��FD����ĳ��ȶ��Ǿ��� InitTDAndFD�õ����ʺ�FFT��������鳤��Ϊ2���������ݵ����� ��
	void FFT_2D(complex<double>*&TD, complex<double> *&FD, int lWidth, int lHeight);//��һάFFT�������άFFT��lWidth��lHeight�ֱ�ΪҪ�������ݵĿ�͸ߡ�TD����ĳ���Ϊ2������

};

