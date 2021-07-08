#pragma once

//disable all warnings
#ifdef _HAS_EXCEPTIONS
#undef _HAS_EXCEPTIONS
#endif

#ifndef _HAS_EXCEPTIONS
#define _HAS_EXCEPTIONS 0
#endif

#include <Windows.h>
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"
#include "GameMath/Color.h"
#include <math.h>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Figures/Ellipse.h"