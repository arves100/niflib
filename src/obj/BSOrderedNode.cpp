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
#include "../../include/obj/BSOrderedNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSOrderedNode::TYPE("BSOrderedNode", &NiNode::TYPE );

BSOrderedNode::BSOrderedNode() : staticBound(false) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSOrderedNode::~BSOrderedNode() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSOrderedNode::GetType() const {
	return TYPE;
}

NiObject * BSOrderedNode::Create() {
	return new BSOrderedNode;
}

void BSOrderedNode::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::Read( in, link_stack, info );
	NifStream( alphaSortBound, in, info );
	NifStream( staticBound, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSOrderedNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::Write( out, link_map, missing_link_stack, info );
	NifStream( alphaSortBound, out, info );
	NifStream( staticBound, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSOrderedNode::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiNode::asString();
	out << "  Alpha Sort Bound:  " << alphaSortBound << endl;
	out << "  Static Bound:  " << staticBound << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSOrderedNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSOrderedNode::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

std::list<NiObject *> BSOrderedNode::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiNode::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
