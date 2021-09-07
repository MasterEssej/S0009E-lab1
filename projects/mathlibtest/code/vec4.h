#pragma once
#include <iostream>

class vec4
{
public:
	float x;
	float y;
	float z;
	float w;

#pragma region constructor
	vec4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	vec4(float const xn, float const yn, float const zn, float const wn)
	{
		x = xn;
		y = yn;
		z = zn;
		w = wn;
	}

	vec4(vec4 const& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}
#pragma endregion

#pragma region operators
	vec4 operator=(vec4 const& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return *this;
	}
	vec4 operator-()
	{
		vec4 temp(-x, -y, -z, -w);
		return temp;
	}
	vec4 operator+(vec4 const& rhs)
	{
		vec4 temp((x + rhs.x), (y + rhs.y), (z + rhs.z), (w + rhs.w));
		return temp;
	}
	void operator+=(vec4 const& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
	}
	vec4 operator-(vec4 const& rhs)
	{
		vec4 temp((x - rhs.x), (y - rhs.y), (z - rhs.z), (w - rhs.w));
		return temp;
	}
	void operator-=(vec4 const& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
	}
	void operator*=(float const scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
	}
	vec4 operator*(float const scalar)
	{
		vec4 temp(x * scalar, y * scalar, z * scalar, w * scalar);
		return temp;
	}
	bool operator==(vec4 const& rhs)
	{
		if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(vec4 const& rhs)
	{
		if (x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	float operator[](unsigned int const i)
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
		}
		else if (i == 0)
		{
			return x;
		}
		else if (i == 1)
		{
			return y;
		}
		else if (i == 2)
		{
			return z;
		}
		else if (i == 3)
		{
			return w;
		}
		return -1;
	}
	const float operator[](unsigned int const i)const
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
		}
		else if (i == 0)
		{
			return x;
		}
		else if (i == 1)
		{
			return y;
		}
		else if (i == 2)
		{
			return z;
		}
		else if (i == 3)
		{
			return w;
		}
		return -1;
	}
#pragma endregion
	
	float setElement(int const i, float const v)
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
			return -1;
		}
		else if (i == 0)
		{
			x = v;
		}
		else if (i == 1)
		{
			y = v;
		}
		else if (i == 2)
		{
			z = v;
		}
		else if (i == 3)
		{
			w = v;
		}
		return 0;
	}
	float getElement(int const i)const
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
			return -1;
		}
		else if (i == 0)
		{
			return x;
		}
		else if (i == 1)
		{
			return y;
		}
		else if (i == 2)
		{
			return z;
		}
		else if (i == 3)
		{
			return w;
		}
		return 0;
	}
	int print()const
	{
		std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
		return 0;
	}

};

float dot(vec4 const& a, vec4 const& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w*b.w;
}
float length(vec4 const& v)
{
	return sqrt(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2) + powf(v.w, 2));
}
vec4 normalize(vec4 const& v)
{
	vec4 temp(v.x / length(v), v.y / length(v), v.z / length(v), v.w/length(v));
	return temp;
}