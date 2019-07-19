/* Copyright (c) 2019, NIF File Format Library and Tools
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
#include "../../include/obj/NiMaterialColorController.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMaterialColorController::TYPE("NiMaterialColorController", &NiPoint3InterpController::TYPE );

NiMaterialColorController::NiMaterialColorController() : targetColor((MaterialColor)0), data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiMaterialColorController::~NiMaterialColorController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiMaterialColorController::GetType() const {
	return TYPE;
}

NiObject * NiMaterialColorController::Create() {
	return new NiMaterialColorController;
}

void NiMaterialColorController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPoint3InterpController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( targetColor, in, info );
	};
	if ( info.version <= 0x0A010067 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMaterialColorController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPoint3InterpController::Write( out, link_map, missing_link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( targetColor, out, info );
	};
	if ( info.version <= 0x0A010067 ) {
		WriteRef( StaticCast<NiObject>(data), out, info, link_map, missing_link_stack );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiMaterialColorController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPoint3InterpController::asString();
	out << "  Target Color:  " << targetColor << endl;
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMaterialColorController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPoint3InterpController::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version <= 0x0A010067 ) {
		data = FixLink<NiPosData>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiMaterialColorController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPoint3InterpController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

std::list<NiObject *> NiMaterialColorController::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPoint3InterpController::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
