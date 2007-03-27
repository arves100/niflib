/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _QUATERNIONXYZW_H_
#define _QUATERNIONXYZW_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A quaternion as it appears in the havok objects.
 */
struct QuaternionXYZW {
	/*! Default Constructor */
	NIFLIB_API QuaternionXYZW();
	/*! Copy Constructor */
	NIFLIB_API QuaternionXYZW( const QuaternionXYZW & src );
	/*! Copy Operator */
	NIFLIB_API QuaternionXYZW & operator=( const QuaternionXYZW & src );
	/*! Default Destructor */
	NIFLIB_API ~QuaternionXYZW();
	/*!
	 * The x-coordinate.
	 */
	float x;
	/*!
	 * The y-coordinate.
	 */
	float y;
	/*!
	 * The z-coordinate.
	 */
	float z;
	/*!
	 * The w-coordinate.
	 */
	float w;
};

}
#endif
