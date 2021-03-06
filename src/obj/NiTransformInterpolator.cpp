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
#include "../../include/obj/NiTransformInterpolator.h"
#include "../../include/gen/NiQuatTransform.h"
#include "../../include/obj/NiTransformData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformInterpolator::TYPE("NiTransformInterpolator", &NiKeyBasedInterpolator::TYPE );

NiTransformInterpolator::NiTransformInterpolator() : data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiTransformInterpolator::~NiTransformInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiTransformInterpolator::GetType() const {
	return TYPE;
}

NiObject * NiTransformInterpolator::Create() {
	return new NiTransformInterpolator;
}

void NiTransformInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiKeyBasedInterpolator::Read( in, link_stack, info );
	NifStream( transform.translation, in, info );
	NifStream( transform.rotation, in, info );
	NifStream( transform.scale, in, info );
	if ( info.version <= 0x0A01006D ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			{
				bool tmp;
				NifStream( tmp, in, info );
				transform.trsValid[i2] = tmp;
			};
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTransformInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyBasedInterpolator::Write( out, link_map, missing_link_stack, info );
	NifStream( transform.translation, out, info );
	NifStream( transform.rotation, out, info );
	NifStream( transform.scale, out, info );
	if ( info.version <= 0x0A01006D ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			{
				bool tmp = transform.trsValid[i2];
				NifStream( tmp, out, info );
			};
		};
	};
	WriteRef( StaticCast<NiObject>(data), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiTransformInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiKeyBasedInterpolator::asString();
	out << "  Translation:  " << transform.translation << endl;
	out << "  Rotation:  " << transform.rotation << endl;
	out << "  Scale:  " << transform.scale << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    TRS Valid[" << i1 << "]:  " << transform.trsValid[i1] << endl;
		array_output_count++;
	};
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTransformInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyBasedInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );
	data = FixLink<NiTransformData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiTransformInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyBasedInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

std::list<NiObject *> NiTransformInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiKeyBasedInterpolator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

NiQuatTransform NiTransformInterpolator::GetQuatTransformation() const {
	return transform;
}

void NiTransformInterpolator::SetQuatTransformation( NiQuatTransform value ) {
	transform = value;
}

Ref<NiTransformData> NiTransformInterpolator::GetData() const {
	return data;
}

void NiTransformInterpolator::SetData( NiTransformData * value ) {
	data = value;
}

void NiTransformInterpolator::NormalizeKeys( float phase, float frequency ) {
	if ( data != NULL ) {
		data->NormalizeKeys( phase, frequency );
	}
}

//--END CUSTOM CODE--//
