#pragma once
#include "Color.h"
class RenderInterface
{
public:
	virtual void DrawLineBox(const Vector2f& Position,const Vector2f& Size, const Color& color)=0;
	virtual void DrawLineCircle(const Vector2f& Position, float Radius, const Color& color)=0;
	virtual void DrawLine(const Vector2f& Point1, const Vector2f& P2, const Color& color) = 0;
	virtual void DrawFilledBox(const Vector2f& Position, const Vector2f& Size, const Color& color)=0;
	virtual void DrawFilledCircle(const Vector2f& Position, float Radius, const Color& color)=0;
	virtual void RenderText(const Vector2f& Position, const Color& color, char* format, ...) = 0;
	virtual HRESULT InitWindow(const wchar_t* WindowName, const HINSTANCE hInstance, const Vector2f& Size) = 0;
	virtual HRESULT Init()=0;
	virtual void PreFrame() = 0;
	virtual void Present() = 0;

	enum class RectPoint
	{
		TopLeft,
		TopRight,
		BottomLeft,
		BottomRight
	};

	Vector2f GetRectPoint(const Vector2f& Pos, const Vector2f& Size, const RectPoint PointIndex);
	virtual ~RenderInterface()=default;
};

Vector2f RenderInterface::GetRectPoint(const Vector2f& Pos, const Vector2f& Size, const RectPoint PointIndex)
{
	/*
	0-----1
	|     |
	|     |
	2-----3
	*/
	if (PointIndex == RectPoint::TopLeft)
	{
		return Pos;
	}else if (PointIndex == RectPoint::TopRight) {
		return Vector2f(Pos.x + Size.x, Pos.y);
	}else if (PointIndex == RectPoint::BottomLeft) {
		return Vector2f(Pos.x, Pos.y + Size.y);
	}else if (PointIndex == RectPoint::BottomRight) {
		return Pos + Size;
	}
}