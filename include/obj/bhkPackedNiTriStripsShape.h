/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BHKPACKEDNITRISTRIPSSHAPE_H_
#define _BHKPACKEDNITRISTRIPSSHAPE_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "bhkShapeCollection.h"

// Include structures
#include "../gen/OblivionSubShape.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class hkPackedNiTriStripsData;
class bhkPackedNiTriStripsShape;
typedef Ref<bhkPackedNiTriStripsShape> bhkPackedNiTriStripsShapeRef;

/*! A shape constructed from strips data. */
class bhkPackedNiTriStripsShape : public bhkShapeCollection {
public:
	/*! Constructor */
	NIFLIB_API bhkPackedNiTriStripsShape();
	
	/*! Destructor */
	NIFLIB_API virtual ~bhkPackedNiTriStripsShape();
	
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
	/*!
	 * Retrieves the geometry data object used by this geometry node, if any.  This contains the vertices, normals, etc. and can be shared among several geometry nodes.
	 * \return The geometry data object, or NULL if there is none.
	 */
	NIFLIB_API Ref<hkPackedNiTriStripsData> GetData() const;

	/*!
	 * Sets the geometry data object used by this geometry node.  This contains the vertices, normals, etc. and can be shared among several geometry nodes.
	 * \param[in] n The new geometry data object, or NULL to clear the current one.
	 */
	NIFLIB_API void SetData( hkPackedNiTriStripsData * n );

	/*!
	* Retrieves the subshape data object used by this geometry node, if any.
	* \return The subshape data object.
	*/
	NIFLIB_API vector<OblivionSubShape> GetSubShapes() const;

	/*!
	* Sets the subshape data object used by this geometry node. 
	* \param[in] value The subshape data.
	*/
	NIFLIB_API void SetSubShapes( vector<OblivionSubShape>& value );	

	/*!
	 * Gets the scale. Usually (1.0, 1.0, 1.0).
	 * \return The scale.
	 */
	NIFLIB_API Vector4 GetScale() const;

	/*!
	 * Sets the scale. Usually (1.0, 1.0, 1.0).
	 * \param[in] n The new scale.
	 */
	NIFLIB_API void SetScale( const Vector4 & n );

	NIFLIB_API float GetRadius() const;

	NIFLIB_API void SetRadius(float value);

	/*! Helper routine for calculating mass properties.
	 *  \param[in]  density Uniform density of object
	 *  \param[in]  solid Determines whether the object is assumed to be solid or not
	 *  \param[out] mass Calculated mass of the object
	 *  \param[out] center Center of mass
	 *  \param[out] inertia Mass Inertia Tensor
	 *  \return Return mass, center, and inertia tensor.
	 */
	NIFLIB_API virtual void CalcMassProperties(float density, bool solid, float &mass, float &volume, Vector3 &center, InertiaMatrix& inertia);

	//--END CUSTOM CODE--//
protected:
	mutable unsigned short numSubShapes;
	vector<OblivionSubShape > subShapes;
	unsigned int userData;
	/*! Looks like a memory pointer and may be garbage. */
	unsigned int unused1;
	float radius;
	/*! Looks like a memory pointer and may be garbage. */
	unsigned int unused2;
	Vector4 scale;
	/*! Same as radius */
	float radiusCopy;
	/*! Same as scale. */
	Vector4 scaleCopy;
	Ref<hkPackedNiTriStripsData > data;
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
