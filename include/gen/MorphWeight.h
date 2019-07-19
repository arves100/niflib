/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _MORPHWEIGHT_H_
#define _MORPHWEIGHT_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiInterpolator;

struct MorphWeight {
	/*! Default Constructor */
	NIFLIB_API MorphWeight();
	/*! Default Destructor */
	NIFLIB_API ~MorphWeight();
	/*! Copy Constructor */
	NIFLIB_API MorphWeight( const MorphWeight & src );
	/*! Copy Operator */
	NIFLIB_API MorphWeight & operator=( const MorphWeight & src );
	Ref<NiInterpolator > interpolator;
	float weight;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
