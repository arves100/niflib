/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiSpotLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSpotLight::TYPE("NiSpotLight", &NiPointLight::TYPE );

NiSpotLight::NiSpotLight() : outerSpotAngle(0.0f), innerSpotAngle(0.0f), exponent(1.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiSpotLight::~NiSpotLight() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiSpotLight::GetType() const {
	return TYPE;
}

NiObject * NiSpotLight::Create() {
	return new NiSpotLight;
}

void NiSpotLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPointLight::Read( in, link_stack, info );
	NifStream( outerSpotAngle, in, info );
	if ( info.version >= 0x14020005 ) {
		NifStream( innerSpotAngle, in, info );
	};
	NifStream( exponent, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSpotLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPointLight::Write( out, link_map, missing_link_stack, info );
	NifStream( outerSpotAngle, out, info );
	if ( info.version >= 0x14020005 ) {
		NifStream( innerSpotAngle, out, info );
	};
	NifStream( exponent, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiSpotLight::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPointLight::asString();
	out << "  Outer Spot Angle:  " << outerSpotAngle << endl;
	out << "  Inner Spot Angle:  " << innerSpotAngle << endl;
	out << "  Exponent:  " << exponent << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSpotLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPointLight::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSpotLight::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPointLight::GetRefs();
	return refs;
}

std::list<NiObject *> NiSpotLight::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPointLight::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

float NiSpotLight::GetOuterSpotAngle() const {
	return outerSpotAngle;
}

void NiSpotLight::SetOuterSpotAngle( float value ) {
	outerSpotAngle = value;
}

float NiSpotLight::GetInnerSpotAngle() const {
	return innerSpotAngle;
}

void NiSpotLight::SetInnerSpotAngle( float value ) {
	innerSpotAngle = value;
}

float NiSpotLight::GetExponent() const {
	return exponent;
}

void NiSpotLight::SetExponent( float value ) {
	exponent = value;
}

//--END CUSTOM CODE--//
