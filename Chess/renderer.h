#include <Windows.h>
#include <d3d9.h>


typedef struct colors
{
	D3DCOLOR backgroundColor = D3DCOLOR_ARGB(255, 190, 190, 190);
}colors;

struct TextureItems
{
	LPDIRECT3DTEXTURE9 imagetex = nullptr;
	LPD3DXSPRITE sprite = nullptr;
};


namespace Renderer
{
	BOOL initD3D(HWND hwnd);
	void renderFrame();
	void cleanD3D();

	void drawFilledRect(int x, int y, int w, int h, D3DCOLOR color);
	void drawX(int x, int y, int size, D3DCOLOR color);
	void drawVersionText(LPCSTR text);
	void DrawTexture(int x, int y, LPDIRECT3DTEXTURE9 dTexture, LPD3DXSPRITE sprite);
	void DrawImage(int x, int y, TextureItems* textureItems);

	void drawMenuBar();

}