/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIGEOMETRY_H_
#define _NIGEOMETRY_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../gen/SkinWeight.h"
#include "../obj/NiGeometryData.h"
//--END CUSTOM CODE--//

#include "NiAVObject.h"

// Include structures
#include "../gen/NiBound.h"
#include "../Ref.h"
#include "../gen/MaterialData.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiObject;
class NiGeometryData;
class NiSkinInstance;
class BSShaderProperty;
class NiAlphaProperty;
class NiGeometry;
typedef Ref<NiGeometry> NiGeometryRef;

/*!
 * Describes a visible scene element with vertices like a mesh, a particle system,
 * lines, etc.
 */
class NiGeometry : public NiAVObject {
public:
	/*! Constructor */
	NIFLIB_API NiGeometry();
	
	/*! Destructor */
	NIFLIB_API virtual ~NiGeometry();
	
	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;
	
	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();
	
	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	
	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Binds this geometry to a list of bones.  Creates and attatches a
	 * NiSkinInstance and NiSkinData class. The bones must have a common
	 * ancestor in the scenegraph.  This becomes the skeleton root.
	 */
	NIFLIB_API void BindSkin( vector< Ref<NiNode> >& bone_nodes );

   /*!
    * Binds this geometry to a list of bones.  Creates and attatches a
    * NiSkinInstance and NiSkinData class. The bones must have a common
    * ancestor in the scenegraph.  This becomes the skeleton root.
    */
   NIFLIB_API void BindSkinWith( vector< Ref<NiNode> >& bone_nodes,  NiObject * (*SkinInstConstructor)() );

	/*!
	 * Unbinds this geometry from the bones.  This removes the NiSkinInstance and NiSkinData objects and causes this geometry to stop behaving as a skin.
	 */
	NIFLIB_API void UnbindSkin();

	/*!
	 * Sets the skin weights in the attached NiSkinData object.
	 * The version on this class calculates the center and radius of
	 * each set of affected vertices automatically.
	 */
	NIFLIB_API void SetBoneWeights( unsigned int bone_index, const vector<BoneVertData> & n );

	/*!
	 * Retrieves the NiSkinInstance object used by this geometry node, if any.
	 * \return The NiSkinInstance object used by this geometry node, or NULL if none is used.
	 */
	NIFLIB_API Ref<NiSkinInstance> GetSkinInstance() const;
	
	/*!
	 * Sets the NiSkinInstance object used by this geometry node.
	 * \param[in] skin The NiSkinInstance object to be used by this geometry node, or NULL if none is to be used.
	 */
	NIFLIB_API void SetSkinInstance(Ref<NiSkinInstance> skin);

	/*!
	 * Retrieves the geometry data object used by this geometry node, if any.  This contains the vertices, normals, etc. and can be shared among several geometry nodes.
	 * \return The geometry data object, or NULL if there is none.
	 */
	NIFLIB_API Ref<NiGeometryData> GetData() const;

	/*!
	 * Sets the geometry data object used by this geometry node.  This contains the vertices, normals, etc. and can be shared among several geometry nodes.
	 * \param[in] n The new geometry data object, or NULL to clear the current one.
	 */
	NIFLIB_API void SetData( NiGeometryData * n );

	/*!
	 * Retrieves the shader used by this geometry node.  The allowable values are game-dependent.
	 * \return The shader.
	 */
	NIFLIB_API  Ref<BSShaderProperty > GetBSShader() const;

	/*!
	 * Sets the shader used by this geometry node.  The allowable values are game-dependent.
	 * \param[in] n The new shader.
	 */
	NIFLIB_API void SetBSShader( const Ref<BSShaderProperty > & n );

	/*
	 * Returns the position of the verticies and values of the normals after they
	 * have been deformed by the positions of their skin influences.
	 * \param[out] vertices A vector that will be filled with the skin deformed position of the verticies.
	 * \param[out] normals A vector thta will be filled with the skin deformed normal values.
	 */
	NIFLIB_API void GetSkinDeformation( vector<Vector3> & vertices, vector<Vector3> & normals ) const;

	/*
	 * Applies the local transform values to the vertices of the geometry and
	 * zeros them out to the identity.
	 */
	NIFLIB_API void ApplyTransforms();

	/*
	 * Propogates the transforms between this skin and the skeleton root,
	 * and then applies them to the verticies of this skin.  Sets the overall
	 * skin data transform to the identity.
	 */
	NIFLIB_API void ApplySkinOffset();

	/*
	 * This automatically normalizes all the skin weights for this geometry node if it is bound to bones as a skin.  In other words, it will guarantee that the weights for all bones on each vertex will add up to 1.0.  This can be used to correct bad input data.
	 */
	NIFLIB_API void NormalizeSkinWeights();

	/*
	 * Used to determine whether this mesh is influenced by bones as a skin.
	 * \return True if this mesh is a skin, false otherwise.
	 */
	NIFLIB_API bool IsSkin();

   NIFLIB_API void SetAlphaProperty(const Ref<NiAlphaProperty >& value);
   NIFLIB_API Ref<NiAlphaProperty > GetAlphaProperty() const;

   NIFLIB_API MaterialData GetMaterialData() const;
   NIFLIB_API void SetMaterialData(MaterialData value);

   NIFLIB_API Ref<NiObject> GetSkin();

   NIFLIB_API NiBound GetBound();
   NIFLIB_API void SetBound(const NiBound& value);

	//--END CUSTOM CODE--//
protected:
	NiBound bound;
	Ref<NiObject > skin;
	/*! Data index (NiTriShapeData/NiTriStripData). */
	Ref<NiGeometryData > data;
	Ref<NiSkinInstance > skinInstance;
	MaterialData materialData;
	Ref<BSShaderProperty > shaderProperty;
	Ref<NiAlphaProperty > alphaProperty;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

}
#endif
