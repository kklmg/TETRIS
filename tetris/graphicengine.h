#ifndef __GRAPHICENGINE_H__
#define __GRAPHICENGINE_H__

#include <windows.h>


typedef struct SURFACEINFOtag
{
	int			nWidth;
	int			nHeight;
	int			nCentralX;		// 중심좌표 X
	int			nCentralY;		// 중심좌표 Y
	COLORREF	crColorKey;		// 컬러키
	DWORD		dwDelayTime;	// 지연시간 (ms)

	HDC			dcSurface;		// 비트맵이 적재되있는 표면 DC
	HBITMAP		hBmp;			// 비트맵 핸들
	HBITMAP		hOldBmp;		// 이전 비트맵 핸들 ( dc 해제시 참조 )
} SURFACEINFO;

typedef struct BIN_SURFACEINFOtag
{
	int			nWidth;
	int			nHeight;
	int			nCentralX;		// 중심좌표 X
	int			nCentralY;		// 중심좌표 Y
	COLORREF	crColorKey;		// 컬러키
	DWORD		dwDelayTime;	// 지연시간 (ms)

	BYTE*		pSurface;		// 표면의 주소
} BIN_SURFACEINFO;

HBITMAP				__geBmpFile2BmpHandle(char* ptstrFilename);
BIN_SURFACEINFO*	__geBmpFile2BinSurface(char* ptstrFilename);
//void				__geSetBitmapinfoBIn(BIN_SURFACEINFO* pbsInfo, BOOL bMirror);
HBITMAP				__geBinSurface2BmpHandle(BIN_SURFACEINFO* pbsInfo);
//void				__geSetBitmapinfo(SURFACEINFO* psInfo, BOOL bMirror);				// SURFACEINFO
HBITMAP				__geSurface2BmpHandle(SURFACEINFO* psInfo, BYTE* pSurface);			//

BOOL	__geCreateBackBuffer(HDC hdc, int nWidth, int nHeight, int nBPP, SURFACEINFO* psInfo);
void	__geLoadSurface(HDC hdc, SURFACEINFO* psInfo);
void	__geReleaseSurface(SURFACEINFO* psInfo);
void	__geReleaseBinSurface(BIN_SURFACEINFO* pbsInfo);

BOOL	__gePutImage(HDC dcDst, int x, int y, SURFACEINFO* psInfo);
BOOL    __gePutImage_m(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int maxFrame, int disFrame);
int		__gePutImageBin(HDC dcDst, int x, int y, BIN_SURFACEINFO* pbsInfo);
BOOL	__gePutImageBlend(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int nAlpha);
BOOL	__gePutSprite(HDC dcDst, int x, int y, SURFACEINFO* psInfo);
BOOL    __gePutSprite_m(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int maxFrame, int disFrame);
BOOL	__geCompleteBlt(HDC hdc, SURFACEINFO* psInfo);

COLORREF __geGetPixel(BIN_SURFACEINFO* pbsInfo, int ix, int iy);
BYTE*    __geGetBitsPtr(BIN_SURFACEINFO* pbsInfo, int x, int y);

void	__geSetImgSurface(SURFACEINFO* psfInfo);
void	__geSetSprSurface(SURFACEINFO* psfInfo, COLORREF crColorKey);
//void	__geSetImgBinSurface(BIN_SURFACEINFO* psfInfo);
void	__geSetSprBinSurface(BIN_SURFACEINFO* pbsfInfo, int nWidth, int nHeight, COLORREF crColorKey);

SURFACEINFO*	 __geCreateSprSurface();
BIN_SURFACEINFO* __geCreateSprBinSurface();

void __geCreateCompactSurface(BIN_SURFACEINFO* pbsInfo, RECT rcCompact, BIN_SURFACEINFO* pbsInfoCompact);
RECT __geGetCuttingRect(HWND hWnd, RECT rcDrag, BIN_SURFACEINFO* pbsInfo);

#endif