#include <stdio.h>
#include "GraphicEngine.h"
#pragma comment(lib, "Msimg32.lib") 

// msimg32.lib : TransparentBlt(), AlphaBlend()

//// 비트맵파일을 비트맵핸들로 변환하여 리턴한다
HBITMAP __geBmpFile2BmpHandle(char* pstrFilename)
{
	FILE  *fp;
	DWORD dwSize;
	BITMAPFILEHEADER BitmapFileHeader;
	BITMAPINFO *pBitmapInfo;
	HBITMAP hBit;
	void* pBitmap;

	//// 파일을 연다
	fp = fopen(pstrFilename, "rb");

	//// BITMAPFILEHEADER 	
	fread(&BitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	//// BITMAPINFO의 크기를 구하고 할당, 읽는다
	dwSize = BitmapFileHeader.bfOffBits - sizeof(BITMAPFILEHEADER);	// 40 bytes
																	//dwSize = sizeof(BITMAPINFO);									// 44 bytes
	pBitmapInfo = (BITMAPINFO*)malloc(dwSize);
	fread(pBitmapInfo, dwSize, 1, fp);

	//// DIB 섹션을 만들고 버퍼 메모리를 할당한다.
	hBit = CreateDIBSection(NULL,				// HDC, DIB_PAL_COLORS인 경우만 사용
		pBitmapInfo,		// BITMAPINFO 포인터
		DIB_RGB_COLORS,	// 색상 사용 플래그
		&pBitmap,			// 메모리 어드래스
		NULL,				// 파일 매핑 개체 핸들
		0);				// 파일 매핑 개체의 비트 오프셋

						//// 이미지 데이터를 읽어들인다.
	int nImageSize = BitmapFileHeader.bfSize - BitmapFileHeader.bfOffBits;
	fread(pBitmap, nImageSize, 1, fp);

	////
	free(pBitmapInfo);

	////
	fclose(fp);

	return hBit;
}

//// BITMAPINFO 스트럭쳐 초기화 ( 기본적으로 24bit 모드 지원 )
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

//// 이진표면을 비트맵핸들로 변환한다 
HBITMAP __geBinSurface2BmpHandle(BIN_SURFACEINFO* pbsInfo)
{
	HBITMAP hBit;
	BITMAPINFO BitmapInfo;

	__geSetBitmapinfoBin(pbsInfo, &BitmapInfo, FALSE);

	void* pSurface;

	//// DIB 섹션을 만들고 버퍼 메모리를 할당한다.
	hBit = CreateDIBSection(NULL,					// HDC, DIB_PAL_COLORS인 경우만 사용
		&BitmapInfo,			// BITMAPINFO 포인터
		DIB_RGB_COLORS,		// 색상 사용 플래그
		&pSurface,			// 메모리 어드래스
		NULL,					// 파일 매핑 개체 핸들
		0);					// 파일 매핑 개체의 비트 오프셋	

	memcpy(pSurface, pbsInfo->pSurface, BitmapInfo.bmiHeader.biSizeImage);
	return hBit;
}

//// BITMAPINFO 스트럭쳐 초기화 ( 기본적으로 24bit 모드 지원 )
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

//// 이진표면을 비트맵핸들로 변환한다 
HBITMAP __geSurface2BmpHandle(SURFACEINFO* psInfo, BYTE* pSrcSurface)
{
	HBITMAP hBit = 0;
	BITMAPINFO BitmapInfo;

	__geSetBitmapinfo(psInfo, &BitmapInfo, TRUE);

	void* pSurface;

	//// DIB 섹션을 만들고 버퍼 메모리를 할당한다.
	hBit = CreateDIBSection(NULL,					// HDC, DIB_PAL_COLORS인 경우만 사용
		&BitmapInfo,			// BITMAPINFO 포인터
		DIB_RGB_COLORS,		// 색상 사용 플래그
		&pSurface,			// 메모리 어드래스
		NULL,					// 파일 매핑 개체 핸들
		0);					// 파일 매핑 개체의 비트 오프셋	

	memcpy(pSurface, pSrcSurface, BitmapInfo.bmiHeader.biSizeImage);
	return hBit;
}

//// 비트맵파일을 이진표면으로 변환한다
BIN_SURFACEINFO* __geBmpFile2BinSurface(char* pstrFilename)
{
	FILE			 *fp;
	DWORD			 dwSize;
	BITMAPFILEHEADER BitmapFileHeader;
	BITMAPINFO		 *pBitmapInfo;

	//// 파일을 연다
	fp = fopen(pstrFilename, "rb");
	fread(&BitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	//// BITMAPINFO의 크기를 구하고 할당, 읽는다
	dwSize = BitmapFileHeader.bfOffBits - sizeof(BITMAPFILEHEADER);	    // 40 bytes
																		//dwSize = sizeof(BITMAPINFO);										// 44 bytes
	pBitmapInfo = (BITMAPINFO*)malloc(dwSize);
	fread(pBitmapInfo, dwSize, 1, fp);

	//// 이미지 데이터를 읽어들인다.	
	int nImageSize = BitmapFileHeader.bfSize - BitmapFileHeader.bfOffBits;
	BIN_SURFACEINFO* pbsfBitmap = __geCreateSprBinSurface();;
	pbsfBitmap->pSurface = (BYTE*)malloc(nImageSize);

	//// 거꾸로 읽어들인다 ( 정방향 이미지로 바꾼다 )
	//fread(pbsfBitmap->pSurface, nImageSize, 1, fp);	// 그냥 읽는 경우
	int nBmpWidth = pBitmapInfo->bmiHeader.biWidth;
	int nBmpHeight = pBitmapInfo->bmiHeader.biHeight;
	int nPixelSize = pBitmapInfo->bmiHeader.biBitCount / 8;		// 픽셀 바이트 크기
	int nBmpWidthByte = nBmpWidth * nPixelSize;					// 비트맵 가로 바이트 수
	int nHorizonOffset = nBmpHeight * nBmpWidthByte;			// 수평 최초 오프셋
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


//// hdc와 호환되는 후면표면DC 생성
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

//// 표면 생성 및 로드
//// 각종 오브젝트 또는 비트맵 DC 생성 및 비트맵 로드
void __geLoadSurface(HDC hdc, SURFACEINFO* psInfo)
{
	BITMAP  bit;

	psInfo->dcSurface = CreateCompatibleDC(hdc);
	psInfo->hOldBmp = (HBITMAP)SelectObject(psInfo->dcSurface, psInfo->hBmp);

	GetObject(psInfo->hBmp, sizeof(BITMAP), &bit);
	psInfo->nWidth = bit.bmWidth;
	psInfo->nHeight = bit.bmHeight;
}

//// 생성된 표면 해제
void __geReleaseSurface(SURFACEINFO* psInfo)
{
	SelectObject(psInfo->dcSurface, psInfo->hOldBmp);
	DeleteDC(psInfo->dcSurface);
	DeleteObject(psInfo->hBmp);
}

//// 생성된 표면 해제
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

//// 이미지 출력
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

//// 이미지 블렌드 
BOOL __gePutImageBlend(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int nAlpha)
{
	BLENDFUNCTION bf;

	//// BLENDFUNCTION 초기화
	bf.BlendOp = AC_SRC_OVER;	//
	bf.BlendFlags = 0;				//			
	bf.AlphaFormat = 0;				//
	bf.SourceConstantAlpha = nAlpha; // 0 - 255

									 //// 알파 블렌드
	return 	AlphaBlend(dcDst,
		x, y, psInfo->nWidth, psInfo->nHeight,
		psInfo->dcSurface,
		0, 0, psInfo->nWidth, psInfo->nHeight,
		bf);
}

//// 스프라이트


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

//// hdc에 표면을 복사 (후면표면 --전송--> 화면DC)
BOOL __geCompleteBlt(HDC hdc, SURFACEINFO* psInfo)
{
	BitBlt(hdc, 0, 0, psInfo->nWidth, psInfo->nHeight, psInfo->dcSurface, 0, 0, SRCCOPY);
	return TRUE;
}

//// SURFACEINFO 이미지 초기화
void __geSetImgSurface(SURFACEINFO* psfInfo)
{
	memset(psfInfo, 0, sizeof(SURFACEINFO));
}

//// SURFACEINFO 스프라이트 초기화
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

//// BIN_SURFACEINFO 스프라이트 초기화
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

//// 위치의 포인터를 얻는다
BYTE* __geGetBitsPtr(BIN_SURFACEINFO* pbsInfo, int x, int y)
{
	return pbsInfo->pSurface + y * pbsInfo->nWidth * 3 + x * 3;
}

////
RECT __geGetCuttingRect(HWND hWnd, RECT rcDrag, BIN_SURFACEINFO* pbsInfo)
{
	////
	COLORREF   colorPixel;

	//// 추출영역 제한 ( 비정상적 드래그 방지 )
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
		// nMinX (왼쪽 끝 면)
		for (ix = rcDrag.left; ix < rcDrag.right; ix++)
		{
			colorPixel = __geGetPixel(pbsInfo, ix, iy);
			if (colorPixel != pbsInfo->crColorKey && ix < nMinX)
			{
				nMinX = ix;
				break;
			}
		}
		// nMaxX (오른쪽 끝 면)
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
		// nMinY (위쪽 끝 면) 
		for (iy = rcDrag.top; iy < rcDrag.bottom; iy++)
		{
			colorPixel = __geGetPixel(pbsInfo, ix, iy);
			if (colorPixel != pbsInfo->crColorKey && iy < nMinY)
			{
				nMinY = iy;
				break;
			}
		}
		// nMaxY (아래쪽 끝 면)
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

	//// 좌표보정
	RECT rcFrame = { nMinX, nMinY, nMaxX + 1, nMaxY + 1 };

	return rcFrame;
}

//// 4의 배수가 되는 최소 표면을 만든다
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

	nWidthRevision = ((nWidthRevision + 3) & ~3);		// 4의 배수
	nSurfaceSize = nWidthRevision * nHeight * 3;
	pSurface = (BYTE*)malloc(nSurfaceSize);

	//// 메모리 컬러키 초기화
	for (int i = 0; i < nSurfaceSize; i += 3) ::memcpy(pSurface + i, btColorKey, 3);

	//// 4의 배수 보정에 의한 가로폭 상이
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