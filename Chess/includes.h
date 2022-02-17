#include <iostream>
#include <Windows.h>
#include <thread>
#include <d3dx9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "renderer.h"
#include "game.hpp"
#include "pieces.hpp"
#include "player.hpp"
#include "ai.h"


extern LPDIRECT3D9			d3d;
extern LPDIRECT3DDEVICE9	d3ddev;
extern colors Colors;

extern Piece* GameBoard[8][8];

extern HWND gameHwnd;
extern bool applicationRunning;
extern int gameX, gameY, gameWidth, gameHeight;
