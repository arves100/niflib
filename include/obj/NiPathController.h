/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIPATHCONTROLLER_H_
#define _NIPATHCONTROLLER_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPosData;
class NiFloatData;
class NiPathController;
typedef Ref<NiPathController> NiPathControllerRef;

/*!
 * DEPRECATED (10.2), REMOVED (20.5). Replaced by NiTransformController and
 * NiPathInterpolator.
 *         Time controller for a path.
 */
class NiPathController : public NiTimeController {
public:
	/*! Constructor */
	NIFLIB_API NiPathController();
	
	/*! Destructor */
	NIFLIB_API virtual ~NiPathController();
	
	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;
	
	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();
	
	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	
	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	NIFLIB_API PathFlags GetPathFlags() const;
	NIFLIB_API void SetPathFlags(PathFlags value);

	NIFLIB_API float GetBankDir() const;
	NIFLIB_API void SetBankDir(float value);

	NIFLIB_API float GetMaxBankAngle() const;
	NIFLIB_API void SetMaxBankAngle(float value);

	NIFLIB_API float GetSmoothing() const;
	NIFLIB_API void SetSmoothing(float value);

	NIFLIB_API float GetFollowAxis() const;
	NIFLIB_API void SetFollowAxis(float value);

	NIFLIB_API Ref<NiPosData > GetPathData() const;
	NIFLIB_API void SetPathData(const Ref<NiPosData >& value);

	NIFLIB_API Ref<NiFloatData > GetPercentData() const;
	NIFLIB_API void SetPercentData(const Ref<NiFloatData >& value);


	//--END CUSTOM CODE--//
protected:
	PathFlags pathFlags;
	/*! -1 = Negative, 1 = Positive */
	int bankDir;
	/*! Max angle in radians. */
	float maxBankAngle;
	float smoothing;
	/*! 0, 1, or 2 representing X, Y, or Z. */
	short followAxis;
	Ref<NiPosData > pathData;
	Ref<NiFloatData > percentData;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

}
#endif
