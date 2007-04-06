/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPOINTLIGHT_H_
#define _NIPOINTLIGHT_H_

#include "NiLight.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiPointLight;
typedef Ref<NiPointLight> NiPointLightRef;

/*!
 * NiPointLight - A point light.
 */

class NiPointLight : public NI_POINT_LIGHT_PARENT {
public:
	NIFLIB_API NiPointLight();
	NIFLIB_API ~NiPointLight();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Constant Attenuation
	 */
	NIFLIB_API float GetConstantAttenuation() const;
	NIFLIB_API void SetConstantAttenuation( float value );

	/*!
	 * Linear Attenuation
	 */
	NIFLIB_API float GetLinearAttenuation() const;
	NIFLIB_API void SetLinearAttenuation( float value );

	/*!
	 * Quadratic Attenuation (see glLight)
	 */
	NIFLIB_API float GetQuadraticAttenuation() const;
	NIFLIB_API void SetQuadraticAttenuation( float value );

protected:
	NI_POINT_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
