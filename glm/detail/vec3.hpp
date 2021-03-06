#pragma once
#include "vec2.hpp"

namespace glm
{
	template <typename T>
	class vec3_T
	{
	public:
		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T u, v, w; };
		};

		vec3_T() {}
		vec3_T(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
		vec3_T(const vec3_T& v) : x(v.x), y(v.y), z(v.z) {}
		explicit vec3_T(T _a) : vec3_T(_a, _a, _a) {}
		template <typename T> explicit vec3_T(const vec3_T<T>& p) : x(T(p.x)), y(T(p.y)), z(T(p.z)) {}
		template <typename T> explicit vec3_T(const vec2_T<T>& p, T _z) : x(T(p.x)), y(T(p.y)), z(T(_z)) {}
		template <typename P> explicit vec3_T(const P& p) : x((T)p.x), y((T)p.y), z((T)p.z) {}

		size_t length() const { return 3; }

		vec3_T<T> operator - () const { vec3_T r; r.x = -this->x; r.y = -this->y; r.z = -this->z; return r; }

		vec3_T<T> operator + (const vec3_T<T>& p)	const { vec3_T<T> r; r.x = this->x + p.x; r.y = this->y + p.y; r.z = this->z + p.z;		return r; }
		vec3_T<T> operator - (const vec3_T<T>& p)	const { vec3_T<T> r; r.x = this->x - p.x; r.y = this->y - p.y; r.z = this->z - p.z;		return r; }
		vec3_T<T> operator * (const vec3_T<T>& p)	const { vec3_T<T> r; r.x = this->x * p.x; r.y = this->y * p.y; r.z = this->z * p.z;		return r; }
		vec3_T<T> operator / (const vec3_T<T>& p)	const { vec3_T<T> r; r.x = this->x / p.x; r.y = this->y / p.y; r.z = this->z / p.z;		return r; }
		vec3_T<T> operator + (const T     v)		const { vec3_T<T> r; r.x = this->x + v;   r.y = this->y + v;   r.z = this->z + v;	    return r; }
		vec3_T<T> operator - (const T     v)		const { vec3_T<T> r; r.x = this->x - v;   r.y = this->y - v;   r.z = this->z - v;	    return r; }
		vec3_T<T> operator * (const T     v)		const { vec3_T<T> r; r.x = this->x * v;   r.y = this->y * v;   r.z = this->z * v;	    return r; }
		vec3_T<T> operator / (const T     v)		const { vec3_T<T> r; r.x = this->x / v;   r.y = this->y / v;   r.z = this->z / v;	    return r; }

		template <typename U>
		vec3_T<T> operator + (const vec3_T<U>& p) const
		{
			return vec3_T<T>(
				this->x + static_cast<T>(p.x),
				this->y + static_cast<T>(p.y),
				this->z + static_cast<T>(p.z));
		}

		template <typename U>
		vec3_T<T> operator - (const vec3_T<U>& p) const
		{
			return vec3_T<T>(
				this->x - static_cast<T>(p.x),
				this->y - static_cast<T>(p.y),
				this->z - static_cast<T>(p.z));
		}

		template <typename U>
		vec3_T<T> operator * (const vec3_T<U>& p) const
		{
			return vec3_T<T>(
				this->x * static_cast<T>(p.x),
				this->y * static_cast<T>(p.y),
				this->z * static_cast<T>(p.z));
		}

		template <typename U>
		vec3_T<T> operator / (const vec3_T<U>& p) const
		{
			return vec3_T<T>(
				this->x / static_cast<T>(p.x),
				this->y / static_cast<T>(p.y),
				this->z / static_cast<T>(p.z));
		}

		T& operator [] (size_t i)
		{
			assert(i >= 0 && i < this->length());
			switch (i)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			default:
				return x;
			}
		}

		T const& operator [] (size_t i) const
		{
			assert(i >= 0 && i < this->length());
			switch (i)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			default:
				return x;
			}
		}

		vec3_T<T>& operator = (vec3_T<T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator = (vec3_T<U> const& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator += (U scalar)
		{
			this->x += static_cast<T>(scalar);
			this->y += static_cast<T>(scalar);
			this->z += static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator += (vec3_T<U> const& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator -= (U scalar)
		{
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			this->z -= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator -= (vec3_T<U> const& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator *= (U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			this->z *= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator *= (vec3_T<U> const& v)
		{
			this->x *= static_cast<T>(v.x);
			this->y *= static_cast<T>(v.y);
			this->z *= static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator /= (U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			this->z /= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3_T<T>& operator /= (vec3_T<U> const& v)
		{
			this->x /= static_cast<T>(v.x);
			this->y /= static_cast<T>(v.y);
			this->z /= static_cast<T>(v.z);
			return *this;
		}

		bool operator == (vec3_T<T> const& v) const
		{
			return this->x == v.x && this->y == v.y && this->z == v.z;
		}

		bool operator != (vec3_T<T> const& v) const
		{
			return !(*this == v);
		}
	};

	typedef vec3_T<float>			vec3f;
	typedef vec3_T<double>			vec3d;
	typedef vec3_T<int>				vec3i;
	typedef vec3_T<unsigned int>	vec3u;
	typedef vec3_T<float>			vec3;
}
