/*--------------------------------------------------------------------------------------
 Ethanon Engine (C) Copyright 2008-2012 Andre Santee
 http://www.asantee.net/ethanon/

	Permission is hereby granted, free of charge, to any person obtaining a copy of this
	software and associated documentation files (the "Software"), to deal in the
	Software without restriction, including without limitation the rights to use, copy,
	modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the
	following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
	CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
	OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
--------------------------------------------------------------------------------------*/

#ifndef ETH_ELEMENT_DRAWER_H_
#define ETH_ELEMENT_DRAWER_H_

#include "../ETHTypes.h"
#include "../Resource/ETHResourceManager.h"

class ETHElementDrawer
{
public:
	virtual bool Draw(const unsigned long lastFrameElapsedTimeMS) = 0;
	virtual bool IsAlive() const = 0;
};

class ETHTextDrawer : public ETHElementDrawer
{
public:
	ETHTextDrawer(
		const ETHResourceProviderPtr& provider,
		const Vector2& pos,
		const str_type::string& text,
		const str_type::string& font,
		const GS_DWORD color,
		const unsigned long time,
		const float scale);

	ETHTextDrawer(
		const ETHResourceProviderPtr& provider,
		const Vector2& pos,
		const str_type::string& text,
		const str_type::string& font,
		const GS_DWORD color,
		const float scale);

	bool Draw(const unsigned long lastFrameElapsedTimeMS);
	bool IsAlive() const;

private:
	Vector2 v2Pos;
	str_type::string text;
	str_type::string font;
	GS_DWORD color;
	unsigned long timeMS;
	unsigned long elapsedTimeMS;
	float scale;
	ETHResourceProviderPtr provider;
};

class ETHRectangleDrawer : public ETHElementDrawer
{
public:
	ETHRectangleDrawer(
		const ETHResourceProviderPtr& provider,
		const Vector2& pos,
		const Vector2& size,
		const Color& color,
		const float depth = 0.0f);

	ETHRectangleDrawer(
		const ETHResourceProviderPtr& provider,
		const Vector2& pos,
		const Vector2& size,
		const Color& color0,
		const Color& color1,
		const Color& color2,
		const Color& color3,
		const float depth = 0.0f);

	bool Draw(const unsigned long lastFrameElapsedTimeMS);
	bool IsAlive() const;

private:
	Vector2 v2Pos;
	Vector2 v2Size;
	Color color0, color1, color2, color3;
	float depth;
	ETHResourceProviderPtr provider;
};


class ETHLineDrawer : public ETHElementDrawer
{
public:
	ETHLineDrawer(
		const ETHResourceProviderPtr& provider,
		const Vector2& a,
		const Vector2& b, 
		const Color& color0,
		const Color& color1,
		const float width,
		const float depth = 0.0f);

	bool Draw(const unsigned long lastFrameElapsedTimeMS);
	bool IsAlive() const;

private:
	Vector2 a, b;
	Color colorA, colorB;
	float width, depth;
	ETHResourceProviderPtr provider;
};

class ETHSpriteDrawer : public ETHElementDrawer
{
public:
	ETHSpriteDrawer(
		const ETHResourceProviderPtr& provider,
		ETHGraphicResourceManagerPtr graphicResources,
		const str_type::string& currentPath,
		const str_type::string& name,
		const Vector2& pos,
		const Vector2& size,
		const Color& color,
		const float depth,
		const float angle,
		const unsigned int frame);

	bool Draw(const unsigned long lastFrameElapsedTimeMS);
	bool IsAlive() const;

private:
	Vector2 v2Pos;
	Vector2 v2Size;
	Vector2 v2Origin;
	SpritePtr sprite;
	Color color0, color1, color2, color3;
	str_type::string name;
	float depth;
	float angle;
	str_type::string currentPath;
	unsigned int frame;
	ETHResourceProviderPtr provider;
};

#endif