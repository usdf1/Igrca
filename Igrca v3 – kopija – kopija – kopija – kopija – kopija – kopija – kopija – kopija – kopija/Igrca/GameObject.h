#pragma once

#include "IObject.h"
#include "Transform.h"
#include <SDL.h>
#include "Point.h"

struct Properties {
public:
	Properties(std::string textureID, int x, int y, int width, int height,float sc, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
		Scale = sc;
	}

public:
	float X, Y, Scale;
	int Width, Height;
	std::string TextureID;
	SDL_RendererFlip Flip;


};

class GameObject : public IObject {
	
public:
	GameObject(Properties* props) : m_TextureID(props->TextureID), m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip), m_Scale(props->Scale){
		m_Transform = new Transform(props->X, props->Y);

		float px = props->X + props->Width / static_cast<float>(2);
		float py = props->Y + props->Height / static_cast<float>(2);
		m_Origin = new Point(px, py);
	}

	inline Point* GetOrigin() { return m_Origin; }

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;
	std::string m_TextureID;

protected:
	Point* m_Origin;
	Transform* m_Transform;
	int m_Width, m_Height;
	//std::string m_TextureID;
	SDL_RendererFlip m_Flip;
	float m_Scale;

};
