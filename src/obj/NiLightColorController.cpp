/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiLightColorController.h"
#include "../../include/obj/NiPosData.h"
#include "../../include/obj/NiPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLightColorController::TYPE("NiLightColorController", &NI_LIGHT_COLOR_CONTROLLER_PARENT::TypeConst() );

NiLightColorController::NiLightColorController() NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT {}

NiLightColorController::~NiLightColorController() {}

void NiLightColorController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiLightColorController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiLightColorController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLightColorController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiLightColorController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLightColorController::GetType() const {
	return TYPE;
};

Ref<NiPosData > NiLightColorController::GetData() const {
	return data;
}

void NiLightColorController::SetData( Ref<NiPosData > value ) {
	data = value;
}

Ref<NiPoint3Interpolator > NiLightColorController::GetInterpolator() const {
	return interpolator;
}

void NiLightColorController::SetInterpolator( Ref<NiPoint3Interpolator > value ) {
	interpolator = value;
}

const Type & NiLightColorController::TypeConst() {
	return TYPE;
}
