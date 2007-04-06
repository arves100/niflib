/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkConvexTransformShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkConvexTransformShape::TYPE("bhkConvexTransformShape", &BHK_CONVEX_TRANSFORM_SHAPE_PARENT::TypeConst() );

bhkConvexTransformShape::bhkConvexTransformShape() BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT {}

bhkConvexTransformShape::~bhkConvexTransformShape() {}

void bhkConvexTransformShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkConvexTransformShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkConvexTransformShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkConvexTransformShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkConvexTransformShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkConvexTransformShape::GetType() const {
	return TYPE;
};

const Type & bhkConvexTransformShape::TypeConst() {
	return TYPE;
}
