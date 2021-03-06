/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NITEXTUREEFFECT_H_
#define _NITEXTUREEFFECT_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiDynamicEffect.h"

// Include structures
#include "../Ref.h"
#include "../gen/NiPlane.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiImage;
class NiSourceTexture;
class NiTextureEffect;
typedef Ref<NiTextureEffect> NiTextureEffectRef;

/*!
 * Represents an effect that uses projected textures such as projected lights
 * (gobos), environment maps, and fog maps.
 */
class NiTextureEffect : public NiDynamicEffect {
public:
	/*! Constructor */
	NIFLIB_API NiTextureEffect();
	
	/*! Destructor */
	NIFLIB_API virtual ~NiTextureEffect();
	
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
	 * Retrives the model projection matrix of this effect.  This always seems to be set to the identity.
	 * \return The model projection matrix.
	 */
	NIFLIB_API Matrix33 GetModelProjectionMatrix() const;

	/*!
	 * Sets the model projection matrix of this effect.  This always seems to be set to the identity.
	 * \param[in] value The new model projection matrix.
	 */
	NIFLIB_API void SetModelProjectionMatrix( Matrix33 value );

	/*!
	 * Retrieves the model projection transform of this effect.  This always seems to be set to (0,0,0).
	 * \return The model projection transform.
	 */
	NIFLIB_API Vector3 GetModelProjectionTransform() const;

	/*!
	 * Sets the model projection transform of this effect.  This always seems to be set to (0,0,0).
	 * \param[in] value The new model projection transform.
	 */
	NIFLIB_API void SetModelProjectionTransform( Vector3 value );

	/*!
	 * Retrieves the texture filtering mode used by this effect.
	 * \return The texture filtering mode.
	 */
	NIFLIB_API TexFilterMode GetTextureFiltering() const;

	/*!
	 * Sets the texture filtering mode used by this effect.
	 * \param[in] value The new texture filtering mode.
	 */
	NIFLIB_API void SetTextureFiltering( TexFilterMode value );

	/*!
	 * Retrieves the texture clamping mode used by this effect.
	 * \return The texture clamping mode.
	 */
	NIFLIB_API TexClampMode GetTextureClamping() const;

	/*!
	 * Sets the texture clamping mode used by this effect.
	 * \param[in] value The new texture clamping mode.
	 */
	NIFLIB_API void SetTextureClamping( TexClampMode value );

	/*!
	 * Retrieves the texture type used by this effect.  Valid values are:
	 * 0: PROJECTED_LIGHT
	 * 1: PROJECTED_SHADOW
	 * 2: ENVIRONMENT_MAP (Usual value)
	 * 3: FOG_MAP
	 * \return The texture type.
	 */
	NIFLIB_API TextureType GetTextureType() const;

	/*!
	 * Sets the texture type used by this effect.  Valid values are:
	 * 0: PROJECTED_LIGHT
	 * 1: PROJECTED_SHADOW
	 * 2: ENVIRONMENT_MAP (Usual value)
	 * 3: FOG_MAP
	 * \param[in] value The new texture type.
	 */
	NIFLIB_API void SetTextureType( TextureType value );

	/*!
	 * Retrieves the texture coordinate generation mode.  Valid values are:
	 * 0: WORLD_PARALLEL
	 * 1: WORLD_PERSPECTIVE
	 * 2: SPHERE_MAP (Usual value)
	 * 3: SPECULAR_CUBE_MAP
	 * 4: DIFFUSE_CUBE_MAP
	 * \return The texture coordinate generation mode.
	 */
	NIFLIB_API CoordGenType GetCoordinateGenerationType() const;

	/*!
	 * Sets the texture coordinate generation mode.  Valid values are:
	 * 0: WORLD_PARALLEL
	 * 1: WORLD_PERSPECTIVE
	 * 2: SPHERE_MAP (Usual value)
	 * 3: SPECULAR_CUBE_MAP
	 * 4: DIFFUSE_CUBE_MAP
	 * \return The new texture coordinate generation mode.
	 */
	NIFLIB_API void SetCoordinateGenerationType( CoordGenType value );

	/*!
	 * Retrieves the source texture index.
	 * \return The source texture index.
	 */
	NIFLIB_API Ref<NiSourceTexture > GetSourceTexture() const;

	/*!
	 * Sets the source texture index.
	 * \param[in] value The new source texture index.
	 */
	NIFLIB_API void SetSourceTexture( Ref<NiSourceTexture > value );

	/*!
	 * Retrieves the clipping plane behavior.  Valid values are:
	 * 0: Disabled (Usual value)
	 * 1: Enabled
	 * \return The clipping plane behavior.
	 */
	NIFLIB_API byte GetClippingPlane() const;

	/*!
	 * Sets the clipping plane behavior.  Valid values are:
	 * 0: Disabled (Usual value)
	 * 1: Enabled
	 * \param[in] value The new clipping plane behavior.
	 */
	NIFLIB_API void SetClippingPlane( byte value );

	/*!
	 * Retrieves a Playstation 2 - specific value.  Can just be left at the default of 0.
	 * \return The PS2 L value.
	 */
	NIFLIB_API unsigned short GetPs2L() const;

	/*!
	 * Sets a Playstation 2 - specific value.  Can just be left at the default of 0.
	 * \param[in] value The new PS2 L value.
	 */
	NIFLIB_API void SetPs2L( unsigned short value );

	/*!
	 * Retrieves a Playstation 2 - specific value.  Can just be left at the default of 0xFFB5.
	 * \return The PS2 K value.
	 */
	NIFLIB_API unsigned short GetPs2K() const;

	/*!
	 * Sets a Playstation 2 - specific value.  Can just be left at the default of 0xFFB5.
	 * \param[in] value The new PS2 K value.
	 */
	NIFLIB_API void SetPs2K( unsigned short value );

	NIFLIB_API unsigned short GetMaxAnisotropy() const;
	NIFLIB_API void SetMaxAnisotropy( unsigned short value );

	NIFLIB_API TexClampMode GetTextureClampMode() const;
	NIFLIB_API void SetTextureClampMode( TexClampMode value );

	NIFLIB_API Ref<NiImage> GetImageIndex() const;
	NIFLIB_API void SetImageIndex( Ref<NiImage> value );

	NIFLIB_API byte GetHasPlane() const;

	NIFLIB_API NiPlane GetPlane() const;
	NIFLIB_API void SetPlane( NiPlane value );

	//--END CUSTOM CODE--//
protected:
	/*! Model projection matrix.  Always identity? */
	Matrix33 modelProjectionMatrix;
	/*! Model projection transform.  Always (0,0,0)? */
	Vector3 modelProjectionTransform;
	/*! Texture Filtering mode. */
	TexFilterMode textureFiltering;
	unsigned short maxAnisotropy;
	/*! Texture Clamp mode. */
	TexClampMode textureClamping;
	/*! The type of effect that the texture is used for. */
	TextureType textureType;
	/*! The method that will be used to generate UV coordinates for the texture effect. */
	CoordGenType coordinateGenerationType;
	/*! Image index. */
	Ref<NiImage > image;
	/*! Source texture index. */
	Ref<NiSourceTexture > sourceTexture;
	/*! Determines whether a clipping plane is used. */
	byte enablePlane;
	NiPlane plane;
	short ps2L;
	short ps2K;
	/*! Unknown: 0. */
	unsigned short unknownShort;
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
