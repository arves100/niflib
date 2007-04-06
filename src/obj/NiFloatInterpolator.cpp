/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiFloatInterpolator.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiFloatInterpolator::TYPE("NiFloatInterpolator", &NI_FLOAT_INTERPOLATOR_PARENT::TypeConst() );

NiFloatInterpolator::NiFloatInterpolator() NI_FLOAT_INTERPOLATOR_CONSTRUCT {}

NiFloatInterpolator::~NiFloatInterpolator() {}

void NiFloatInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiFloatInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiFloatInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiFloatInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiFloatInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiFloatInterpolator::GetType() const {
	return TYPE;
};

float NiFloatInterpolator::GetFloatValue() const {
	return floatValue;
}

void NiFloatInterpolator::SetFloatValue( float value ) {
	floatValue = value;
}

Ref<NiFloatData > NiFloatInterpolator::GetData() const {
	return data;
}

void NiFloatInterpolator::SetData( Ref<NiFloatData > value ) {
	data = value;
}

const Type & NiFloatInterpolator::TypeConst() {
	return TYPE;
}
