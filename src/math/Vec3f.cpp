/*---------------------------------------------------------------------



----------------------------------------------------------------------*/
#include "Vec3f.h"


#include "Math.h"



namespace math
{
	//
	//
	//
	Vec3f::Vec3f()
	{
        x=0.0f; y=0.0f; z=0.0f;
    }

    //
	//
	//
	Vec3f::Vec3f( const float &x, const float &y, const float &z )
    {
        this->x=x; this->y=y; this->z=z;
    }

	//
	//
	//
	Vec3f::~Vec3f( )
	{
	}

	//
	//
	//
	void Vec3f::set( const float &x, const float &y, const float &z )
	{
		this->x=x; this->y=y; this->z=z;
	}

	//
	// returns the cartesian length of the vector
	//
	float Vec3f::length( void )const
	{
		float t = x*x + y*y + z*z;
#ifdef WINDOWS
		__asm
		{
			fld t;
			fsqrt;
			fstp t;
		}
		return t;
#endif
#ifdef LINUX
		//asm( "fld t\n\t"
		//	 "fsqrt\n\t"
		//	 "fstp t\n\t" );
		return sqrtf( t );
#endif
	}

	//
	//
	//
	float Vec3f::getLength( void ) const
	{
		float t = x*x + y*y + z*z;
#ifdef WINDOWS
		__asm
		{
			fld t;
			fsqrt;
			fstp t;
		}
		return t;
#endif
#ifdef LINUX
		//asm( "fld t\n\t"
		//	 "fsqrt\n\t"
		//	 "fstp t\n\t" );
		return sqrtf( t );
#endif
	}

	float Vec3f::getSquaredLength( void ) const
	{
		return x*x + y*y + z*z;
	}

	//
	//
	//
	void Vec3f::setLength( const float &length )
	{
		normalize();

		x*=length;
		y*=length;
		z*=length;
	}

	//
	//
	//
	void Vec3f::normalize( void )
	{
		float length = getLength();

		if( length != 0.0f )
		{
			x /= length;
			y /= length;
			z /= length;	
		}
	}

	//
	//
	//
	void Vec3f::negate( void )
	{
		x=-x; y=-y; z=-z;
	}

	//
	// reflects the vector at the given normal
	//
	void Vec3f::reflect( const Vec3f &normal )
	{
		normalize();

		Vec3f	temp( x, y, z );
		float	value;
		
		value = dotProduct( normal, *this );
		value *= 2.0f;

		x = normal.x * value;
		y = normal.y * value;
		z = normal.z * value;

		x -= temp.x;
		y -= temp.y;
		z -= temp.z;
	}

	//
	//
	//
	bool Vec3f::operator==( const Vec3f &rhs )
	{
		if( (fabs(x - rhs.x) < 0.00001f) && (fabs(y - rhs.y) < 0.00001f) && (fabs(z - rhs.z) < 0.00001f) )
			return true;
		else
			return false;
	}

	//
	//
	//
	bool Vec3f::operator!=( const Vec3f &rhs )
	{
		return !((*this)==rhs);
	}
	
	//
	//
	//
	bool Vec3f::operator+=( const Vec3f &rhs )
	{
		x+=rhs.x;
		y+=rhs.y;
		z+=rhs.z;

		return true;
	}

	//
	//
	//
	bool Vec3f::operator-=( const Vec3f &rhs )
	{
		x-=rhs.x;
		y-=rhs.y;
		z-=rhs.z;

		return true;
	}

	//
	//
	//
	bool Vec3f::operator+=( const float &rhs )
	{
		x+=rhs;
		y+=rhs;
		z+=rhs;

		return true;
	}

	//
	//
	//
	bool Vec3f::operator-=( const float &rhs )
	{
		x-=rhs;
		y-=rhs;
		z-=rhs;

		return true; 
	}

	//
	//
	//
	bool Vec3f::operator*=( const float &rhs )
	{
		x*=rhs;
		y*=rhs;
		z*=rhs;

		return true;
	}

	//
	//
	//
	bool Vec3f::operator/=( const float &rhs )
	{
		x/=rhs;
		y/=rhs;
		z/=rhs;

		return true; 
	}

	//
	//
	//
	const float& Vec3f::operator[]( int i ) const
	{
		return v[i];
	}

	//
	//
	//
	float& Vec3f::operator[]( int i )
	{
		return v[i];
	}
}

