#include <stdio.h>
#include "GraphicEngine.h"
#pragma comment(lib, "Msimg32.lib") 

// msimg32.lib : TransparentBlt(), AlphaBlend()

//// ��Ʈ�������� ��Ʈ���ڵ�� ��ȯ�Ͽ� �����Ѵ�
HBITMAP __geBmpFile2BmpHandle(char* pstrFilename)
{
	FILE  *fp;
	DWORD dwSize;
	BITMAPFILEHEADER BitmapFileHeader;
	BITMAPINFO *pBitmapInfo;
	HBITMAP hBit;
	void* pBitmap;

	//// ������ ����
	fp = fopen(pstrFilename, "rb");

	//// BITMAPFILEHEADER 	
	fread(&BitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	//// BITMAPINFO�� ũ�⸦ ���ϰ� �Ҵ�, �д´�
	dwSize = BitmapFileHeader.bfOffBits - sizeof(BITMAPFILEHEADER);	// 40 bytes
																	//dwSize = sizeof(BITMAPINFO);									// 44 bytes
	pBitmapInfo = (BITMAPINFO*)malloc(dwSize);
	fread(pBitmapInfo, dwSize, 1, fp);

	//// DIB ������ ����� ���� �޸𸮸� �Ҵ��Ѵ�.
	hBit = CreateDIBSection(NULL,				// HDC, DIB_PAL_COLORS�� ��츸 ���
		pBitmapInfo,		// BITMAPINFO ������
		DIB_RGB_COLORS,	// ���� ��� �÷���
		&pBitmap,			// �޸� ��巡��
		NULL,				// ���� ���� ��ü �ڵ�
		0);				// ���� ���� ��ü�� ��Ʈ ������

						//// �̹��� �����͸� �о���δ�.
	int nImageSize = BitmapFileHeader.bfSize - BitmapFileHeader.bfOffBits;
	fread(pBitmap, nImageSize, 1, fp);

	////
	free(pBitmapInfo);

	////
	fclose(fp);

	return hBit;
}

//// BITMAPINFO ��Ʈ���� �ʱ�ȭ ( �⺻������ 24bit ��� ���� )
void __geSetBitmapinfoBin(BIN_SURFACEINFO* pbsInfo, BITMAPINFO *pBitmapInfo, BOOL bMirror)
{
	pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);
	pBitmapInfo->bmiHeader.biWidth = pbsInfo->nWidth;
	pBitmapInfo->bmiHeader.biHeight = bMirror ? -pbsInfo->nHeight : pbsInfo->nHeight;
	pBitmapInfo->bmiHeader.biPlanes = 1;
	pBitmapInfo->bmiHeader.biBitCount = 24;
	pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	pBitmapInfo->bmiHeader.biSizeImage = pbsInfo->nWidth * pbsInfo->nHeight * 3;
	pBitmapInfo->bmiHeader.biClrUsed = 0;
	pBitmapInfo->bmiHeader.biClrImportant = 0;
}

//// ����ǥ���� ��Ʈ���ڵ�� ��ȯ�Ѵ� 
HBITMAP __geBinSurface2BmpHandle(BIN_SURFACEINFO* pbsInfo)
{
	HBITMAP hBit;
	BITMAPINFO BitmapInfo;

	__geSetBitmapinfoBin(pbsInfo, &BitmapInfo, FALSE);

	void* pSurface;

	//// DIB ������ ����� ���� �޸𸮸� �Ҵ��Ѵ�.
	hBit = CreateDIBSection(NULL,					// HDC, DIB_PAL_COLORS�� ��츸 ���
		&BitmapInfo,			// BITMAPINFO ������
		DIB_RGB_COLORS,		// ���� ��� �÷���
		&pSurface,			// �޸� ��巡��
		NULL,					// ���� ���� ��ü �ڵ�
		0);					// ���� ���� ��ü�� ��Ʈ ������	

	memcpy(pSurface, pbsInfo->pSurface, BitmapInfo.bmiHeader.biSizeImage);
	return hBit;
}

//// BITMAPINFO ��Ʈ���� �ʱ�ȭ ( �⺻������ 24bit ��� ���� )
void __geSetBitmapinfo(SURFACEINFO* psInfo, BITMAPINFO *pBitmapInfo, BOOL bMirror)
{
	pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);
	pBitmapInfo->bmiHeader.biWidth = psInfo->nWidth;
	pBitmapInfo->bmiHeader.biHeight = bMirror ? -psInfo->nHeight : psInfo->nHeight;
	pBitmapInfo->bmiHeader.biPlanes = 1;
	pBitmapInfo->bmiHeader.biBitCount = 24;
	pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	pBitmapInfo->bmiHeader.biSizeImage = psInfo->nWidth * psInfo->nHeight * 3;
	pBitmapInfo->bmiHeader.biClrUsed = 0;
	pBitmapInfo->bmiHeader.biClrImportant = 0;
}

//// ����ǥ���� ��Ʈ���ڵ�� ��ȯ�Ѵ� 
HBITMAP __geSurface2BmpHandle(SURFACEINFO* psInfo, BYTE* pSrcSurface)
{
	HBITMAP hBit = 0;
	BITMAPINFO BitmapInfo;

	__geSetBitmapinfo(psInfo, &BitmapInfo, TRUE);

	void* pSurface;

	//// DIB ������ ����� ���� �޸𸮸� �Ҵ��Ѵ�.
	hBit = CreateDIBSection(NULL,					// HDC, DIB_PAL_COLORS�� ��츸 ���
		&BitmapInfo,			// BITMAPINFO ������
		DIB_RGB_COLORS,		// ���� ��� �÷���
		&pSurface,			// �޸� ��巡��
		NULL,					// ���� ���� ��ü �ڵ�
		0);					// ���� ���� ��ü�� ��Ʈ ������	

	memcpy(pSurface, pSrcSurface, BitmapInfo.bmiHeader.biSizeImage);
	return hBit;
}

//// ��Ʈ�������� ����ǥ������ ��ȯ�Ѵ�
BIN_SURFACEINFO* __geBmpFile2BinSurface(char* pstrFilename)
{
	FILE			 *fp;
	DWORD			 dwSize;
	BITMAPFILEHEADER BitmapFileHeader;
	BITMAPINFO		 *pBitmapInfo;

	//// ������ ����
	fp = fopen(pstrFilename, "rb");
	fread(&BitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	//// BITMAPINFO�� ũ�⸦ ���ϰ� �Ҵ�, �д´�
	dwSize = BitmapFileHeader.bfOffBits - sizeof(BITMAPFILEHEADER);	    // 40 bytes
																		//dwSize = sizeof(BITMAPINFO);										// 44 bytes
	pBitmapInfo = (BITMAPINFO*)malloc(dwSize);
	fread(pBitmapInfo, dwSize, 1, fp);

	//// �̹��� �����͸� �о���δ�.	
	int nImageSize = BitmapFileHeader.bfSize - BitmapFileHeader.bfOffBits;
	BIN_SURFACEINFO* pbsfBitmap = __geCreateSprBinSurface();;
	pbsfBitmap->pSurface = (BYTE*)malloc(nImageSize);

	//// �Ųٷ� �о���δ� ( ������ �̹����� �ٲ۴� )
	//fread(pbsfBitmap->pSurface, nImageSize, 1, fp);	// �׳� �д� ���
	int nBmpWidth = pBitmapInfo->bmiHeader.biWidth;
	int nBmpHeight = pBitmapInfo->bmiHeader.biHeight;
	int nPixelSize = pBitmapInfo->bmiHeader.biBitCount / 8;		// �ȼ� ����Ʈ ũ��
	int nBmpWidthByte = nBmpWidth * nPixelSize;					// ��Ʈ�� ���� ����Ʈ ��
	int nHorizonOffset = nBmpHeight * nBmpWidthByte;			// ���� ���� ������
	for (int iH = 0; iH < nBmpHeight; iH++)
	{
		nHorizonOffset -= nBmpWidthByte;
		fread(pbsfBitmap->pSurface + nHorizonOffset, nBmpWidthByte, 1, fp);
	}
	fclose(fp);

	////
	__geSetSprBinSurface(pbsfBitmap, pBitmapInfo->bmiHeader.biWidth, pBitmapInfo->bmiHeader.biHeight, 0);

	////
	free(pBitmapInfo);

	return pbsfBitmap;
}


//// hdc�� ȣȯ�Ǵ� �ĸ�ǥ��DC ����
BOOL __geCreateBackBuffer(HDC hdc, int nWidth, int nHeight, int nBPP, SURFACEINFO* psInfo)
{
	psInfo->dcSurface = CreateCompatibleDC(hdc);
	psInfo->hBmp = CreateCompatibleBitmap(hdc, nWidth, nHeight);
	psInfo->hOldBmp = (HBITMAP)SelectObject(psInfo->dcSurface, psInfo->hBmp);
	PatBlt(psInfo->dcSurface, 0, 0, nWidth, nHeight, PATCOPY);
	psInfo->nWidth = nWidth;
	psInfo->nHeight = nHeight;

	return TRUE;
}

//// ǥ�� ���� �� �ε�
//// ���� ������Ʈ �Ǵ� ��Ʈ�� DC ���� �� ��Ʈ�� �ε�
void __geLoadSurface(HDC hdc, SURFACEINFO* psInfo)
{
	BITMAP  bit;

	psInfo->dcSurface = CreateCompatibleDC(hdc);
	psInfo->hOldBmp = (HBITMAP)SelectObject(psInfo->dcSurface, psInfo->hBmp);

	GetObject(psInfo->hBmp, sizeof(BITMAP), &bit);
	psInfo->nWidth = bit.bmWidth;
	psInfo->nHeight = bit.bmHeight;
}

//// ������ ǥ�� ����
void __geReleaseSurface(SURFACEINFO* psInfo)
{
	SelectObject(psInfo->dcSurface, psInfo->hOldBmp);
	DeleteDC(psInfo->dcSurface);
	DeleteObject(psInfo->hBmp);
}

//// ������ ǥ�� ����
void __geReleaseBinSurface(BIN_SURFACEINFO* pbsInfo)
{
	if (pbsInfo)
	{
		if (pbsInfo->pSurface)
		{
			free(pbsInfo->pSurface);
			pbsInfo->pSurface = NULL;
		}
		free(pbsInfo);
		pbsInfo = NULL;
	}
}

//
//
//
//
//
//

//// �̹��� ���
BOOL __gePutImage(HDC dcDst, int x, int y, SURFACEINFO* psInfo)
{
	if (psInfo)
		return BitBlt(dcDst, x, y, psInfo->nWidth, psInfo->nHeight, psInfo->dcSurface, 0, 0, SRCCOPY);
	else return FALSE;
}
BOOL __gePutImage_m(HDC dcDst, int x, int y, SURFACEINFO* psInfo,int maxFrame,int disFrame)
{
	if (psInfo)
		return BitBlt(dcDst, x, y, psInfo->nWidth/maxFrame, psInfo->nHeight, psInfo->dcSurface, (psInfo->nWidth / maxFrame)*disFrame, 0, SRCCOPY);
	else return FALSE;
}




int  __gePutImageBin(HDC dcDst, int x, int y, BIN_SURFACEINFO* pbsInfo)
{
	if (pbsInfo)
	{
		BITMAPINFO BitmapInfo;
		__geSetBitmapinfoBin(pbsInfo, &BitmapInfo, TRUE);
		return ::StretchDIBits(dcDst,
			x, y, pbsInfo->nWidth, pbsInfo->nHeight,
			0, 0, pbsInfo->nWidth, pbsInfo->nHeight,
			pbsInfo->pSurface, &BitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}
	else return FALSE;
}

//// �̹��� ���� 
BOOL __gePutImageBlend(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int nAlpha)
{
	BLENDFUNCTION bf;

	//// BLENDFUNCTION �ʱ�ȭ
	bf.BlendOp = AC_SRC_OVER;	//
	bf.BlendFlags = 0;				//			
	bf.AlphaFormat = 0;				//
	bf.SourceConstantAlpha = nAlpha; // 0 - 255

									 //// ���� ����
	return 	AlphaBlend(dcDst,
		x, y, psInfo->nWidth, psInfo->nHeight,
		psInfo->dcSurface,
		0, 0, psInfo->nWidth, psInfo->nHeight,
		bf);
}

//// ��������Ʈ


BOOL __gePutSprite(HDC dcDst, int x, int y, SURFACEINFO* psInfo)
{
	return TransparentBlt(dcDst,
		x, y, psInfo->nWidth, psInfo->nHeight,
		psInfo->dcSurface,
		0, 0, psInfo->nWidth, psInfo->nHeight,
		psInfo->crColorKey);
}

BOOL __gePutSprite_m(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int maxFrame, int disFrame)
{
	return TransparentBlt(dcDst,
		x, y, psInfo->nWidth / maxFrame, psInfo->nHeight,
		psInfo->dcSurface,
		(psInfo->nWidth / maxFrame)*disFrame, 0, psInfo->nWidth / maxFrame, psInfo->nHeight,
		psInfo->crColorKey);
}




//BOOL __gePutStretch(HDC dcDst, int x, int y, SURFACEINFO* psInfo,int block_length)
//{
//	return TransparentBlt(dcDst,
//		x, y, psInfo->nWidth, psInfo->nHeight,
//		psInfo->dcSurface,
//		0, 0, psInfo->nWidth, psInfo->nHeight,
//		psInfo->crColorKey);
//}

//// hdc�� ǥ���� ���� (�ĸ�ǥ�� --����--> ȭ��DC)
BOOL __geCompleteBlt(HDC hdc, SURFACEINFO* psInfo)
{
	BitBlt(hdc, 0, 0, psInfo->nWidth, psInfo->nHeight, psInfo->dcSurface, 0, 0, SRCCOPY);
	return TRUE;
}

//// SURFACEINFO �̹��� �ʱ�ȭ
void __geSetImgSurface(SURFACEINFO* psfInfo)
{
	memset(psfInfo, 0, sizeof(SURFACEINFO));
}

//// SURFACEINFO ��������Ʈ �ʱ�ȭ
void __geSetSprSurface(SURFACEINFO* psfInfo, COLORREF crColorKey)
{
	memset(psfInfo, 0, sizeof(SURFACEINFO));
	psfInfo->crColorKey = crColorKey;
}

BIN_SURFACEINFO* __geCreateSprBinSurface()
{
	return (BIN_SURFACEINFO*)malloc(sizeof(BIN_SURFACEINFO));
}

SURFACEINFO* __geCreateSprSurface()
{
	return (SURFACEINFO*)malloc(sizeof(SURFACEINFO));
}

//// BIN_SURFACEINFO ��������Ʈ �ʱ�ȭ
void __geSetSprBinSurface(BIN_SURFACEINFO* pbsfInfo, int nWidth, int nHeight, COLORREF crColorKey)
{
	pbsfInfo->nWidth = nWidth;
	pbsfInfo->nHeight = nHeight;
	pbsfInfo->crColorKey = crColorKey;

	pbsfInfo->nCentralX = nWidth / 2;
	pbsfInfo->nCentralY = nHeight / 2;
	pbsfInfo->dwDelayTime = 100;
}

COLORREF __geGetPixel(BIN_SURFACEINFO* pbsInfo, int x, int y)
{
	COLORREF colorPixel = 0;

	BYTE* pSurface = pbsInfo->pSurface;
	memcpy(&colorPixel, pSurface + y * pbsInfo->nWidth * 3 + x * 3, 3);

	return colorPixel;
}

//// ��ġ�� �����͸� ��´�
BYTE* __geGetBitsPtr(BIN_SURFACEINFO* pbsInfo, int x, int y)
{
	return pbsInfo->pSurface + y * pbsInfo->nWidth * 3 + x * 3;
}

////
RECT __geGetCuttingRect(HWND hWnd, RECT rcDrag, BIN_SURFACEINFO* pbsInfo)
{
	////
	COLORREF   colorPixel;

	//// ���⿵�� ���� ( �������� �巡�� ���� )
	RECT rcClient;
	GetClientRect(hWnd, &rcClient);
	rcClient.right--;
	rcClient.bottom--;

	IntersectRect(&rcDrag, &rcDrag, &rcClient);

	////
	int nMinX = rcDrag.right;
	int nMinY = rcDrag.bottom;
	int nMaxX = rcDrag.left;
	int nMaxY = rcDrag.top;

	int ix, iy;

	//// X
	for (iy = rcDrag.top; iy < rcDrag.bottom; iy++)
	{
		// nMinX (���� �� ��)
		for (ix = rcDrag.left; ix < rcDrag.right; ix++)
		{
			colorPixel = __geGetPixel(pbsInfo, ix, iy);
			if (colorPixel != pbsInfo->crColorKey && ix < nMinX)
			{
				nMinX = ix;
				break;
			}
		}
		// nMaxX (������ �� ��)
		for (ix = rcDrag.right; ix > rcDrag.left; ix--)
		{
			colorPixel = __geGetPixel(pbsInfo, ix, iy);
			if (colorPixel != pbsInfo->crColorKey && ix > nMaxX)
			{
				nMaxX = ix;
				break;
			}
		}
	}

	//// Y
	for (ix = rcDrag.left; ix < rcDrag.right; ix++)
	{
		// nMinY (���� �� ��) 
		for (iy = rcDrag.top; iy < rcDrag.bottom; iy++)
		{
			colorPixel = __geGetPixel(pbsInfo, ix, iy);
			if (colorPixel != pbsInfo->crColorKey && iy < nMinY)
			{
				nMinY = iy;
				break;
			}
		}
		// nMaxY (�Ʒ��� �� ��)
		for (iy = rcDrag.bottom; iy > rcDrag.top; iy--)
		{
			colorPixel = __geGetPixel(pbsInfo, ix, iy);
			if (colorPixel != pbsInfo->crColorKey && iy > nMaxY)
			{
				nMaxY = iy;
				break;
			}
		}
	}

	//// ��ǥ����
	RECT rcFrame = { nMinX, nMinY, nMaxX + 1, nMaxY + 1 };

	return rcFrame;
}

//// 4�� ����� �Ǵ� �ּ� ǥ���� �����
void __geCreateCompactSurface(BIN_SURFACEINFO* pbsInfo, RECT rcCompact, BIN_SURFACEINFO* pbsInfoCompact)
{
	int		nStep = 0;
	int     nSurfaceSize;
	LPBYTE	pSurface;
	BYTE    btColorKey[3];

	btColorKey[0] = GetRValue(pbsInfo->crColorKey);
	btColorKey[1] = GetGValue(pbsInfo->crColorKey);
	btColorKey[2] = GetBValue(pbsInfo->crColorKey);

	int nWidthCompact = rcCompact.right - rcCompact.left + 1;
	int nWidthRevision = nWidthCompact;
	int nHeight = rcCompact.bottom - rcCompact.top + 1;

	nWidthRevision = ((nWidthRevision + 3) & ~3);		// 4�� ���
	nSurfaceSize = nWidthRevision * nHeight * 3;
	pSurface = (BYTE*)malloc(nSurfaceSize);

	//// �޸� �÷�Ű �ʱ�ȭ
	for (int i = 0; i < nSurfaceSize; i += 3) ::memcpy(pSurface + i, btColorKey, 3);

	//// 4�� ��� ������ ���� ������ ����
	int nSrcCalcWidth = nWidthCompact * 3;
	int nDstCalcWidth = nWidthRevision * 3;

	for (int iy = rcCompact.top; iy < rcCompact.bottom; iy++)
	{
		::memcpy(pSurface + nStep,
			__geGetBitsPtr(pbsInfo, rcCompact.left, iy), nSrcCalcWidth);
		nStep += nDstCalcWidth;
	}

	pbsInfoCompact->pSurface = pSurface;
	pbsInfoCompact->nWidth = nWidthRevision;
	pbsInfoCompact->nHeight = nHeight;
}