/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERDECLINATIONVARCTLR_H_
#define _NIPSYSEMITTERDECLINATIONVARCTLR_H_

#include "APSysCtlr.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiPSysEmitterDeclinationVarCtlr;
typedef Ref<NiPSysEmitterDeclinationVarCtlr> NiPSysEmitterDeclinationVarCtlrRef;

/*!
 * NiPSysEmitterDeclinationVarCtlr - Unknown.
 */

class NiPSysEmitterDeclinationVarCtlr : public NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT {
public:
	NIFLIB_API NiPSysEmitterDeclinationVarCtlr();
	NIFLIB_API ~NiPSysEmitterDeclinationVarCtlr();
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

protected:
	NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
