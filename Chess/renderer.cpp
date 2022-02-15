#include "includes.h"
#include "images.h"


LPDIRECT3D9			d3d;
LPDIRECT3DDEVICE9	d3ddev;
colors				Colors;

ID3DXFont* headerFont;
ID3DXFont* playerFont;
ID3DXFont* pieceFont;

TextureItems whiteKing;
TextureItems blackKing;
TextureItems whiteQueen;
TextureItems blackQueen;
TextureItems whiteKnight;
TextureItems blackKnight;
TextureItems whiteBishop;
TextureItems blackBishop;
TextureItems whiteRook;
TextureItems blackRook;
TextureItems blackPawn;
TextureItems whitePawn;

ID3DXLine* LineL;
D3DCOLOR tileColor = D3DCOLOR_ARGB(255, 10, 10, 10);

BOOL Renderer::initD3D(HWND hwnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = gameWidth;
	d3dpp.BackBufferHeight = gameHeight;

	HRESULT devCreated = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);

	if (devCreated != S_OK)
		return FALSE;

	D3DXCreateLine(d3ddev, &LineL);

	D3DXCreateTextureFromFileInMemoryEx(d3ddev, &bPawnImage, sizeof(bPawnImage), 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL,  &blackPawn.imagetex);
	D3DXCreateSprite(d3ddev, &blackPawn.sprite);

	D3DXCreateTextureFromFileInMemoryEx(d3ddev, &wPawnImage, sizeof(wPawnImage), 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &whitePawn.imagetex);
	D3DXCreateSprite(d3ddev, &whitePawn.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\wking.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &whiteKing.imagetex);
	D3DXCreateSprite(d3ddev, &whiteKing.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\bking.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &blackKing.imagetex);
	D3DXCreateSprite(d3ddev, &blackKing.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\wqueen.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &whiteQueen.imagetex);
	D3DXCreateSprite(d3ddev, &whiteQueen.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\bqueen.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &blackQueen.imagetex);
	D3DXCreateSprite(d3ddev, &blackQueen.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\wknight.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &whiteKnight.imagetex);
	D3DXCreateSprite(d3ddev, &whiteKnight.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\bknight.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &blackKnight.imagetex);
	D3DXCreateSprite(d3ddev, &blackKnight.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\wbishop.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &whiteBishop.imagetex);
	D3DXCreateSprite(d3ddev, &whiteBishop.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\bbishop.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &blackBishop.imagetex);
	D3DXCreateSprite(d3ddev, &blackBishop.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\wrook.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &whiteRook.imagetex);
	D3DXCreateSprite(d3ddev, &whiteRook.sprite);

	D3DXCreateTextureFromFileEx(d3ddev, L"images\\brook.png", 30, 50, -1, D3DUSAGE_RENDERTARGET, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &blackRook.imagetex);
	D3DXCreateSprite(d3ddev, &blackRook .sprite);

	return TRUE;
}

void Renderer::renderFrame()
{
	d3ddev->Clear(0, 0, D3DCLEAR_TARGET, Colors.backgroundColor, 0, 0);
	d3ddev->BeginScene();

	Piece* currPiece;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
				tileColor = D3DCOLOR_ARGB(255, 196, 161, 98);
			Renderer::drawFilledRect(i * 70, j * 70 + 25, 70, 70, tileColor);
			tileColor = D3DCOLOR_ARGB(255, 10, 10, 10);

			currPiece = GameBoard[i][j];

			if (!currPiece)
				continue;

			switch (currPiece->getPiece())
			{
				case 'K':
				{
					if (currPiece->getColor() == 1)
						Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &blackKing);
					else Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &whiteKing);
					break;
				}
				case 'Q':
				{
					if (currPiece->getColor() == 1)
						Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &blackQueen);
					else Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &whiteQueen);
					break;
				}
				case 'N':
				{
					if (currPiece->getColor() == 1)
						Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &blackKnight);
					else Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &whiteKnight);
					break;
				}
				case 'B':
				{
					if (currPiece->getColor() == 1)
						Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &blackBishop);
					else Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &whiteBishop);
					break;
				}
				case 'R':
				{
					if (currPiece->getColor() == 1)
						Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &blackRook);
					else Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &whiteRook);
					break;
				}
				case 'P':
				{
					if (currPiece->getColor() == 1)
						Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &blackPawn);
					else Renderer::DrawImage(i * 70 + 20, j * 70 + 35, &whitePawn);
					break;
				}
			}
		}
	}

	Renderer::drawMenuBar();

	d3ddev->EndScene();
	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void Renderer::cleanD3D()
{
	d3ddev->Release();
	d3d->Release();
}

void Renderer::drawFilledRect(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	d3ddev->Clear(1, &rect, D3DCLEAR_TARGET, color, 1.0f, 0);
}

void Renderer::drawX(int x, int y, int size, D3DCOLOR color)
{

}

void Renderer::DrawTexture(int x, int y, LPDIRECT3DTEXTURE9 dTexture, LPD3DXSPRITE sprite)
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos = D3DXVECTOR3(x - .5, y - .5, 0.0f);
	sprite->Draw(dTexture, NULL, NULL, &pos, 0xFFFFFFFF);

	sprite->End();
}

void Renderer::DrawImage(int x, int y, TextureItems* textureItems)
{
	if (!d3ddev || !textureItems)
		return;

	if (textureItems->imagetex == nullptr || textureItems->sprite == nullptr)
		return;

	Renderer::DrawTexture(x, y, textureItems->imagetex, textureItems->sprite);
}

void Renderer::drawMenuBar()
{
	static POINT Mouse;
	GetCursorPos(&Mouse);

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		if (Mouse.x >= gameX && Mouse.x <= gameX + 560 && Mouse.y >= gameY && Mouse.y <= gameY + 25)
		{
			gameX = Mouse.x - 280;
			gameY = Mouse.y - 12;
		}
	}

	Renderer::drawFilledRect(0, 0, 560, 25, D3DCOLOR_ARGB(255, 88, 126, 196));

	Mouse.x -= gameX;
	Mouse.y -= gameY;
	Renderer::drawFilledRect(Mouse.x, Mouse.y, 10, 10, D3DCOLOR_ARGB(255, 255, 0, 0));
}