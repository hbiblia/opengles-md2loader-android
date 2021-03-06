#pragma once
#include "GL.h"
#include <string>
using std::string;

class Texture2D
{
public:
	Texture2D();
	virtual ~Texture2D();

	bool loadTexture(const string& fileName, bool generateMipMaps = true);
	void bind(GLuint texUnit = 0);

private:
	Texture2D(const Texture2D& rhs) = default;
	Texture2D& operator = (const Texture2D& rhs) = default;

	GLuint mTexture;
};
