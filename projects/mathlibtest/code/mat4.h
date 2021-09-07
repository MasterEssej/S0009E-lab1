#pragma once
#include <iostream>
#include <array>
#include "vec3.h"
#include "vec4.h"

class mat4
{
public:
	std::array<vec4, 4> m;

#pragma region constructors
	mat4()
		:m({ vec4{1, 0, 0, 0}, vec4{0, 1, 0, 0}, vec4{0, 0, 1, 0}, vec4{0, 0, 0, 1}}){}

	mat4(vec4 const& r0, vec4 const& r1, vec4 const& r2, vec4 const& r3)
		:m({ r0, r1, r2, r3 }){}

	mat4(mat4 const& mn)
		:m({mn.m[0], mn.m[1], mn.m[2], mn.m[3]})
	{}
#pragma endregion

#pragma region operators
	mat4 operator=(mat4 const& rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			m[i].x = rhs.m[i].x;
			m[i].y = rhs.m[i].y;
			m[i].z = rhs.m[i].z;
			m[i].w = rhs.m[i].w;
		}
		return *this;
	}
	mat4 operator*(mat4 const& rhs)const
	{
		mat4 tempm;
		for (int i = 0; i < 4; i++)
		{
			vec4 tpose;
			for (int j = 0; j < 4; j++)
			{
				vec4 tempv = rhs.m[j];
				tpose.setElement(j, tempv[i]);
			}
			for (int k = 0; k < 4; k++)
			{
				tempm[k].setElement(i, dot(m[k], tpose));
			}
		}
		return tempm;
	}
	vec4 operator*(vec4 const& rhs)const {
		vec4 temp;
		temp.x = m[0].x * rhs.x + m[1].x * rhs.y + m[2].x * rhs.z + m[3].x * rhs.w;
		temp.y = m[0].y * rhs.x + m[1].y * rhs.y + m[2].y * rhs.z + m[3].y * rhs.w;
		temp.z = m[0].z * rhs.x + m[1].z * rhs.y + m[2].z * rhs.z + m[3].z * rhs.w;
		temp.w = m[0].w * rhs.x + m[1].w * rhs.y + m[2].w * rhs.z + m[3].w * rhs.w;
		return temp;
	}
	bool operator==(mat4 const& rhs)
	{
		if (m[0] == rhs.m[0] && m[1] == rhs.m[1] && m[2] == rhs.m[2] && m[3] == rhs.m[3])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(mat4 const& rhs)
	{
		if (m[0] != rhs.m[0] || m[1] != rhs.m[1] || m[2] != rhs.m[2] || m[3] != rhs.m[3])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	vec4& operator[](unsigned int const i)
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
		}
		else
		{
			return m[i];
		}
	}
	const vec4& operator[](unsigned int const i)const
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
		}
		else
		{
			return m[i];
		}
	}
#pragma endregion

	
	int print()
	{
		for (int i = 0; i < 4; i++)
		{
			m[i].print();
		}
		return 0;
	}

};

float determinant(mat4 const& tm)
{

	float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
	a = tm.m[0].x;
	b = tm.m[0].y;
	c = tm.m[0].z;
	d = tm.m[0].w;

	e = tm.m[1].x;
	f = tm.m[1].y;
	g = tm.m[1].z;
	h = tm.m[1].w;

	i = tm.m[2].x;
	j = tm.m[2].y;
	k = tm.m[2].z;
	l = tm.m[2].w;

	m = tm.m[3].x;
	n = tm.m[3].y;
	o = tm.m[3].z;
	p = tm.m[3].w;

	float det =
		(a *
			(f * (k * p - l * o)
				- g * (j * p - l * n)
				+ h * (j * o - k * n))

			- b *
			(e * (k * p - l * o)
				- g * (i * p - l * m)
				+ h * (i * o - k * m))

			+ c *
			(e * (j * p - l * n)
				- f * (i * p - l * m)
				+ h * (i * n - j * m))

			- d *
			(e * (j * o - k * n)
				- f * (i * o - k * m)
				+ g * (i * n - j * m))

			);

	return det;

}
mat4 transpose(mat4 const& tm)
{
	mat4 temp;
	vec4 tpose;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			tpose.setElement(k, tm.m[k].getElement(i));
		}
		temp[i] = tpose;
	}
	return temp;
}
mat4 inverse(mat4 const& tm)
{

	mat4 c(tm.m[0], tm.m[1], tm.m[2], tm.m[3]);//(m[0], m[1], m[2], m[3]);
	float deter = determinant(c);
	if (deter == 0)
	{
		mat4 temp;
		return temp;
	}
	else
	{

		float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
		a = tm.m[0].x;
		b = tm.m[0].y;
		c = tm.m[0].z;
		d = tm.m[0].w;

		e = tm.m[1].x;
		f = tm.m[1].y;
		g = tm.m[1].z;
		h = tm.m[1].w;

		i = tm.m[2].x;
		j = tm.m[2].y;
		k = tm.m[2].z;
		l = tm.m[2].w;

		m = tm.m[3].x;
		n = tm.m[3].y;
		o = tm.m[3].z;
		p = tm.m[3].w;

		mat4 temp;

		temp[0].x = f * (k * p - l * o) //a
			- g * (j * p - l * n)
			+ h * (j * o - k * n);
		temp[0].y = e * (k * p - l * o) //b 
			- g * (i * p - l * m)
			+ h * (i * o - k * m);
		temp[0].z = e * (j * p - l * n) //c 
			- f * (i * p - l * m)
			+ h * (i * n - j * m);
		temp[0].w = e * (j * o - k * n) //d 
			- f * (i * o - k * m)
			+ g * (i * n - j * m);
		temp[1].x = b * (k * p - l * o) //e 
			- c * (j * p - l * n)
			+ d * (j * o - k * n);
		temp[1].y = a * (k * p - l * o) //f 
			- c * (i * p - l * m)
			+ d * (i * o - k * m);
		temp[1].z = a * (j * p - l * n) //g 
			- b * (i * p - l * m)
			+ d * (i * n - j * m);
		temp[1].w = a * (j * o - k * n) //h 
			- b * (i * o - k * m)
			+ c * (i * n - j * m);
		temp[2].x = b * (g * p - h * o) //i 
			- c * (f * p - h * n)
			+ d * (f * o - g * n);
		temp[2].y = a * (g * p - h * o) //j 
			- c * (e * p - h * m)
			+ d * (e * o - g * m);
		temp[2].z = a * (f * p - h * n) //k
			- b * (e * p - h * m)
			+ d * (e * n - f * m);
		temp[2].w = a * (f * o - g * n) //L
			- b * (e * o - g * m)
			+ c * (e * n - f * m);
		temp[3].x = b * (g * l - h * k) //m
			- c * (f * l - h * j)
			+ d * (f * k - g * j);
		temp[3].y = a * (g * l - h * k) //n
			- c * (e * l - h * i)
			+ d * (e * k - g * i);
		temp[3].z = a * (f * l - h * j) //o
			- b * (e * l - h * i)
			+ d * (e * j - f * i);
		temp[3].w = a * (f * k - g * j) //p 
			- b * (e * k - g * i)
			+ c * (e * j - f * i);

		temp[0].y *= -1;
		temp[0].w *= -1;
		temp[1].x *= -1;
		temp[1].z *= -1;
		temp[2].y *= -1;
		temp[2].w *= -1;
		temp[3].x *= -1;
		temp[3].z *= -1;

		//adjugate and then multiply the adjugate by (1/determinant) using original matrix
		temp = transpose(temp);
		for (int i = 0; i < 4; i++) {
			temp[i].x = (1 / deter) * temp[i].x;
			temp[i].y = (1 / deter) * temp[i].y;
			temp[i].z = (1 / deter) * temp[i].z;
			temp[i].w = (1 / deter) * temp[i].w;
		}
		return temp;
	}

}
mat4 rotationx(float const rad)
{
	mat4 xrot;
	xrot.m[0].x = 1;
	xrot.m[1].y = cos(rad);
	xrot.m[1].z = sin(rad);
	xrot.m[2].y = -sin(rad);
	xrot.m[2].z = cos(rad);
	xrot.m[3].w = 1;
	return xrot;
}
mat4 rotationy(float const rad)
{
	mat4 yrot;
	yrot.m[0].x = cos(rad);
	yrot.m[0].z = -sin(rad);
	yrot.m[1].y = 1;
	yrot.m[2].x = sin(rad);
	yrot.m[2].z = cos(rad);
	yrot.m[3].w = 1;
	return yrot;
}
mat4 rotationz(float const rad)
{
	mat4 zrot;
	zrot.m[0].x = cos(rad);
	zrot.m[0].y = sin(rad);
	zrot.m[1].x = -sin(rad);
	zrot.m[1].y = cos(rad);
	zrot.m[2].z = 1;
	zrot.m[3].w = 1;
	return zrot;
}

mat4 rotationaxis(vec3 const& v, float const rad)
{
	vec3 normalizeAxis = normalize(v);

	float normAxisX = normalizeAxis[0];
	float normAxisY = normalizeAxis[1];
	float normAxisZ = normalizeAxis[2];

	vec4 column1((powf(normAxisX, 2) + ((powf(normAxisY, 2) + powf(normAxisZ, 2)) * cos(rad))),
		(normAxisX * normAxisY * (1 - cos(rad)) + normAxisZ * sin(rad)),
		(normAxisX * normAxisZ * (1 - cos(rad)) - normAxisY * sin(rad)), 0);

	vec4 column2((normAxisX * normAxisY * (1 - cos(rad)) - normAxisZ * sin(rad)),
		(powf(normAxisY, 2) + ((powf(normAxisX, 2) + powf(normAxisZ, 2)) * cos(rad))),
		(normAxisY * normAxisZ * (1 - cos(rad)) + normAxisX * sin(rad)), 0);

	vec4 column3((normAxisX * normAxisZ * (1 - cos(rad)) + normAxisY * sin(rad)),
		((normAxisY * normAxisZ) * (1 - cos(rad)) - normAxisX * sin(rad)),
		(powf(normAxisZ, 2) + ((powf(normAxisX, 2) + powf(normAxisY, 2)) * cos(rad))), 0);

	vec4 column4(
		((v.x * (powf(normAxisY, 2) + powf(normAxisZ, 2)) - normAxisX * (v.y * normAxisY + v.z * normAxisZ))
			* (1 - cos(rad) + (v.y * normAxisZ - v.z * normAxisY) * sin(rad))),

		((v.y * (powf(normAxisX, 2) + powf(normAxisZ, 2)) - normAxisY * (v.x * normAxisX + v.z * normAxisZ))
			* (1 - cos(rad) + (v.z * normAxisX - v.x * normAxisZ) * sin(rad))),

		((v.z * (powf(normAxisX, 2) + powf(normAxisY, 2)) - normAxisZ * (v.x * normAxisX + v.y * normAxisY))
			* (1 - cos(rad) + (v.x * normAxisY - v.y * normAxisX) * sin(rad))), 1);

	mat4 rotMatrix{ column1, column2, column3, column4 };
	return rotMatrix;
}