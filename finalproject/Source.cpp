#include <tchar.h>
#include "Start.h"
#include <strsafe.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include "MMSystem.h"


void main() {
	PlaySound(TEXT("AK.wav"), NULL, SND_ASYNC);
	start();
}