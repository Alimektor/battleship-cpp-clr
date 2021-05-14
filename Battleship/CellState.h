#pragma once

enum class CellState : char
{
	Empty = '~',
	Hidden = '-',
	Hit = 'x',
	Ship = 'o',
	Missed = '.'
};