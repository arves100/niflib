/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiSkinData.h"
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinInstance::TYPE("NiSkinInstance", &NI_SKIN_INSTANCE_PARENT::TypeConst() );

NiSkinInstance::NiSkinInstance() NI_SKIN_INSTANCE_CONSTRUCT {}

NiSkinInstance::NiSkinInstance( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes ) NI_SKIN_INSTANCE_CONSTRUCT {
	//Ensure that all bones are below the skeleton root node on the scene graph
	for ( uint i = 0; i < bone_nodes.size(); ++i ) {
		bool is_decended = false;
		NiNodeRef node = bone_nodes[i];
		while ( node != NULL ) {
			if ( node == skeleton_root ) {
				is_decended = true;
				break;
			}
			node = node->GetParent();
		}
		if ( is_decended == false ) {
			throw runtime_error( "All bones must be lower than the skeleton root in the scene graph." );
		}
	}

	//Add the bones to the internal list
	bones.resize( bone_nodes.size() );
	for ( uint i = 0; i < bone_nodes.size(); ++i ) {
		bones[i] = bone_nodes[i];
	}

	//Flag any bones that are part of this skin instance
	for ( uint i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}

	//Store skeleton root and inform it of this attachment
	skeletonRoot = skeleton_root;
	skeletonRoot->AddSkin( this );
}

NiSkinInstance::~NiSkinInstance() {
	//Probably not necessary, and not very safe
	////Unflag any bones that were part of this skin instance
	//for ( uint i = 0; i < bones.size(); ++i ) {
	//	cout << "Bone " << i << ":";
	//	cout << bones[i]->GetIDString() << endl;
	//	bones[i]->SetSkinFlag(false);
	//}

	//Inform Skeleton Root of detatchment and clear it.
	if ( skeletonRoot != NULL ) {
		skeletonRoot->RemoveSkin( this );
	}
}

void NiSkinInstance::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiSkinInstance::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiSkinInstance::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSkinInstance::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );

	//Inform newly fixed skeleton root of attachment
	if ( skeletonRoot != NULL ) {
		skeletonRoot->AddSkin( this );
	}

	//Ensure that bones have the flag set properly
	for ( uint i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}
}

list<NiObjectRef> NiSkinInstance::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSkinInstance::GetType() const {
	return TYPE;
};

vector< Ref<NiNode> > NiSkinInstance::GetBones() const {
	vector<NiNodeRef> ref_bones( bones.size() );
	for (uint i = 0; i < bones.size(); ++i ) {
		ref_bones[i] = bones[i];
	}
	return ref_bones;
}

Ref<NiSkinData> NiSkinInstance::GetSkinData() const {
	return data;
}

void NiSkinInstance::SetSkinData( const Ref<NiSkinData> & n ) {
	data = n;
}

Ref<NiSkinPartition> NiSkinInstance::GetSkinPartition() const {
	return skinPartition;
}

void NiSkinInstance::SetSkinPartition( const Ref<NiSkinPartition> & n ) {
	skinPartition = n;
}

void NiSkinInstance::SkeletonLost() {
	skeletonRoot = NULL;

	//Clear bone list
	bones.clear();

	//Destroy skin data
	data = NULL;
	skinPartition = NULL;
}

uint NiSkinInstance::GetBoneCount() const {
	return uint(bones.size());
}

Ref<NiNode> NiSkinInstance::GetSkeletonRoot() const {
	return skeletonRoot;
}
