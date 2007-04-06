/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABONELODCONTROLLER_H_
#define _ABONELODCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../gen/NodeGroup.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class ABoneLODController;
typedef Ref<ABoneLODController> ABoneLODControllerRef;

/*!
 * ABoneLODController - Level of detail controller for bones?
 */

class ABoneLODController : public A_BONE_L_O_D_CONTROLLER_PARENT {
public:
	NIFLIB_API ABoneLODController();
	NIFLIB_API ~ABoneLODController();
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
	 * Returns the number of node groups (each group a sequence of bones).
	 */
	NIFLIB_API int GetNodeGroupCount() const;

	/*!
	 * Returns a specific node group (each group a sequence of bones).
	 */
	NIFLIB_API vector<Ref<NiNode> > GetNodeGroup( int index ) const;

	/*!
	 * Add a single node to the specified group. The Group list will expand if necessary.
	 */
	NIFLIB_API void AddNodeToGroup( int index, Ref<NiNode> node );

	/*!
	 * Remove a single node from the specified group. 
	 */
	NIFLIB_API void RemoveNodeFromGroup( int index, Ref<NiNode> node );

	/*!
	 * Assign an entire node group. 
	 */
	NIFLIB_API void SetNodeGroup( int index, const vector<Ref<NiNode> >& group );


	/*!
	 * Remove an entire node group. 
	 */
	NIFLIB_API void RemoveNodeGroup( int index );

	/*!
	 * Clear all node groups.
	 */
	NIFLIB_API void ClearNodeGroups();

protected:
	A_BONE_L_O_D_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
