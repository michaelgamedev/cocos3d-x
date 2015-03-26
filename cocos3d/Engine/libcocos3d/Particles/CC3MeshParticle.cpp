/*
 * Cocos3D-X 1.0.0
 * Author: Bill Hollings
 * Copyright (c) 2010-2014 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Copyright (c) 2014-2015 Jason Wong
 * http://www.cocos3dx.org/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * http://en.wikipedia.org/wiki/MIT_License
 */
#include "cocos3d.h"

NS_COCOS3D_BEGIN

CC3MeshParticle::CC3MeshParticle()
{
	_rotator = NULL;
	_templateMesh = NULL;
}

CC3MeshParticle::~CC3MeshParticle()
{
	CC_SAFE_RELEASE( _rotator );
	CC_SAFE_RELEASE( _templateMesh );
}

void CC3MeshParticle::setEmitter( CC3ParticleEmitter* anEmitter )
{
	super::setEmitter( anEmitter );
}

CC3Mesh* CC3MeshParticle::getMesh()
{
	return getEmitter()->getMesh(); 
}

bool CC3MeshParticle::isAlive()
{
	return _isAlive; 
}

void CC3MeshParticle::setIsAlive( bool alive )
{
	_isAlive = alive; 
}

GLuint CC3MeshParticle::getFirstVertexOffset()
{
	return _firstVertexOffset; 
}

void CC3MeshParticle::setFirstVertexOffset( GLuint vtxOffset )
{
	_firstVertexOffset = vtxOffset; 
}

GLuint CC3MeshParticle::getVertexCount()
{
	return _templateMesh ? _templateMesh->getVertexCount() : 0; 
}

CCRange CC3MeshParticle::getVertexRange()
{
	return CCRangeMake(getFirstVertexOffset(), getVertexCount()); 
}

GLuint CC3MeshParticle::getFirstVertexIndexOffset()
{
	return _firstVertexIndexOffset; 
}

void CC3MeshParticle::setFirstVertexIndexOffset( GLuint vtxIdxOffset )
{
	_firstVertexIndexOffset = vtxIdxOffset; 
}

GLuint CC3MeshParticle::getVertexIndexCount()
{
	return hasVertexIndices() ? _templateMesh->getVertexIndexCount() : getVertexCount();
}

CCRange CC3MeshParticle::getVertexIndexRange()
{
	return CCRangeMake(getFirstVertexIndexOffset(), getVertexIndexCount()); 
}

bool CC3MeshParticle::hasVertexIndices()
{
	return (_templateMesh && _templateMesh->hasVertexIndices()); 
}

void CC3MeshParticle::markTransformDirty()
{
	_isTransformDirty = true;
	((CC3MeshParticleEmitter*)_emitter)->markParticleTransformDirty();
}

CC3Rotator* CC3MeshParticle::getRotator()
{
	return _rotator;
}

void CC3MeshParticle::setRotator( CC3Rotator* rotator )
{
	CC_SAFE_RELEASE( _rotator );
	_rotator = rotator;
	CC_SAFE_RETAIN( rotator );
}

bool CC3MeshParticle::isColorDirty()
{
	return _isColorDirty;
}

bool CC3MeshParticle::isTransformDirty()
{
	return _isTransformDirty;
}

CC3Vector CC3MeshParticle::getLocation()
{
	return _location; 
}

void CC3MeshParticle::setLocation( const CC3Vector& aLocation )
{
	_location = aLocation;
	markTransformDirty();
}

void CC3MeshParticle::translateBy( const CC3Vector& aVector )
{
	setLocation( getLocation().add( aVector ) );  
}

CC3Vector CC3MeshParticle::getRotation()
{
	return _rotator->getRotation(); 
}

void CC3MeshParticle::setRotation( const CC3Vector& aRotation )
{
	// This test for change avoids unnecessarily creating and transforming a mutable rotator
	if ( !shouldTrackTarget() && !aRotation.equals( _rotator->getRotation() ) ) 
	{
		getMutableRotator()->setRotation( aRotation );
		markTransformDirty();
	}
}

void CC3MeshParticle::rotateBy( const CC3Vector& aRotation )
{
	if ( !shouldTrackTarget() ) 
	{
		getMutableRotator()->rotateBy( aRotation );
		markTransformDirty();
	}
}

CC3Quaternion CC3MeshParticle::getQuaternion()
{
	return _rotator->getQuaternion(); 
}

void CC3MeshParticle::setQuaternion( const CC3Quaternion& aQuaternion )
{
	// This test for change avoids unnecessarily creating and transforming a mutable rotator
	if ( !shouldTrackTarget() && !CC3QuaternionsAreEqual(aQuaternion, _rotator->getQuaternion()) ) 
	{
		getMutableRotator()->setQuaternion( aQuaternion );
		markTransformDirty();
	}
}

void CC3MeshParticle::rotateByQuaternion( const CC3Quaternion& aQuaternion )
{
	if ( !shouldTrackTarget() )
	{
		getMutableRotator()->rotateByQuaternion( aQuaternion );
		markTransformDirty();
	}
}

CC3Vector CC3MeshParticle::getRotationAxis()
{
	return _rotator->getRotationAxis(); 
}

void CC3MeshParticle::setRotationAxis( const CC3Vector& aDirection )
{
	// This test for change avoids unnecessarily creating and transforming a mutable rotator
	if ( !shouldTrackTarget() && !aDirection.equals( _rotator->getRotationAxis() ) ) 
	{
		getMutableRotator()->setRotationAxis( aDirection );
		markTransformDirty();
	}
}

GLfloat CC3MeshParticle::getRotationAngle()
{
	return _rotator->getRotationAngle(); 
}

void CC3MeshParticle::setRotationAngle( GLfloat anAngle )
{
	if ( !shouldTrackTarget() && (anAngle != _rotator->getRotationAngle()) ) 
	{
		getMutableRotator()->setRotationAngle( anAngle );
		markTransformDirty();
	}
}

void CC3MeshParticle::rotateByAngle( GLfloat anAngle, const CC3Vector& anAxis )
{
	if (!shouldTrackTarget()) 
	{
		getMutableRotator()->rotateByAngle( anAngle, anAxis );
		markTransformDirty();
	}
}

CC3Vector CC3MeshParticle::getForwardDirection()
{
	return getDirectionalRotator()->getForwardDirection(); 
}

void CC3MeshParticle::setForwardDirection( const CC3Vector& aDirection )
{
	if ( !shouldTrackTarget() ) 
	{
		getDirectionalRotator()->setForwardDirection( aDirection );
		markTransformDirty();
	}
}

CC3Vector CC3MeshParticle::getUpDirection()
{
	return getDirectionalRotator()->getUpDirection(); 
}

CC3Vector CC3MeshParticle::getReferenceUpDirection()
{
	return getDirectionalRotator()->getReferenceUpDirection(); 
}

void CC3MeshParticle::setReferenceUpDirection( const CC3Vector& aDirection )
{
	getDirectionalRotator()->setReferenceUpDirection( aDirection );
	markTransformDirty();
}

CC3Vector CC3MeshParticle::getRightDirection()
{
	return getDirectionalRotator()->getRightDirection(); 
}

bool CC3MeshParticle::shouldTrackTarget()
{
	return _rotator->shouldTrackTarget(); 
}

/**
 * Returns the rotator property, cast as a CC3MutableRotator.
 *
 * If the rotator is not already a CC3MutableRotator, a new CC3MutableRotator
 * is created and its state is copied from the current rotator.
 *
 * This design allows particles that do not require rotation to use the empty and smaller
 * CC3Rotator instance, but allows an automatic upgrade to a mutable rotator
 * when the node needs to make changes to the rotational properties.
 *
 * This property should only be accessed if the intention is to swap the existing
 * rotator with a directional rotator.
 */
CC3MutableRotator* CC3MeshParticle::getMutableRotator()
{
	if ( !_rotator->isMutable() )
	{
		CC3MutableRotator* mRotator = (CC3MutableRotator*)CC3MutableRotator::rotator();
//		mRotator->populateFrom( _rotator );
		CC3_TRACE("[ptc]CC3MeshParticle swapping for mutable rotator");
		setRotator( mRotator );
	}
	return (CC3MutableRotator*)_rotator;
}

/**
 * Returns the rotator property, cast as a CC3DirectionalRotator.
 *
 * If the rotator is not already a CC3DirectionalRotator, a new CC3DirectionalRotator
 * is created and its state is copied from the current rotator.
 *
 * This design allows most particles to use a simpler and smaller CC3Rotator instance,
 * but allow an automatic upgrade to a larger and more complex directional rotator
 * when the node needs to make use of pointing or tracking functionality.
 *
 * This implementation returns a reversing directional rotator class that orients
 * the positive-Z axis of the node along the forwardDirection.
 *
 * This property should only be accessed if the intention is to swap the existing
 * rotator with a directional rotator.
 */
CC3DirectionalRotator* CC3MeshParticle::getDirectionalRotator()
{
	if ( !_rotator->isDirectional() ) 
	{
		CC3DirectionalRotator* dRotator = (CC3DirectionalRotator*)CC3DirectionalRotator::rotator();
//		dRotator->populateFrom( _rotator );
		dRotator->setShouldReverseForwardDirection( _emitter->shouldReverseForwardDirection() );
		CC3_TRACE("[ptc]CC3MeshParticle swapping for directional rotator");
		setRotator( dRotator );
	}
	return (CC3DirectionalRotator*)_rotator;
}

/**
 * Returns the rotator property, cast as a CC3TargettingRotator.
 *
 * If the rotator is not already a CC3TargettingRotator, a new CC3TargettingRotator
 * is created and its state is copied from the current rotator.
 *
 * This design allows most particles to use a simpler and smaller CC3Rotator instance,
 * but allow an automatic upgrade to a larger and more complex directional rotator
 * when the node needs to make use of pointing or tracking functionality.
 *
 * This implementation returns a reversing directional rotator class that orients
 * the positive-Z axis of the node along the forwardDirection.
 *
 * This property should only be accessed if the intention is to swap the existing
 * rotator with a directional rotator.
 */
CC3TargettingRotator* CC3MeshParticle::getTargettingRotator()
{
	if ( !_rotator->isTargettable() ) 
	{
		CC3TargettingRotator* tRotator = (CC3TargettingRotator*)CC3TargettingRotator::rotator();
//		tRotator->populateFrom( _rotator );
		tRotator->setShouldReverseForwardDirection( _emitter->shouldReverseForwardDirection() );
		CC3_TRACE("[ptc]CC3MeshParticle swapping for targetting rotator", tRotator, _rotator);
		setRotator( tRotator );
	}

	return (CC3TargettingRotator*)_rotator;
}

ccColor4F CC3MeshParticle::getColor4F()
{
	return (hasColor() && getVertexCount() > 0) ? getVertexColor4FAt( 0 ) : super::getColor4F();
}

void CC3MeshParticle::setColor4F( const ccColor4F& aColor )
{
	if ( hasColor() && getVertexCount() > 0 ) 
	{
		setVertexColor4F( aColor, 0 );
		markColorDirty();
	}
}

ccColor4B CC3MeshParticle::getColor4B()
{
	return (hasColor() && getVertexCount() > 0) ? getVertexColor4BAt( 0 ) : super::getColor4B();
}

void CC3MeshParticle::setColor4B( const ccColor4B& aColor )
{
	if ( hasColor() && getVertexCount() > 0 )
	{
		setVertexColor4B( aColor, 0 );
		markColorDirty();
	}
}

void CC3MeshParticle::setTextureRectangle( const CCRect& aRect, GLuint texUnit )
{
	// The texture coordinates of the template mesh, and its effective texture rectangle.
	CC3VertexTextureCoordinates* tmplVtxTexCoords = _templateMesh->getTextureCoordinatesForTextureUnit( texUnit );
	CCRect tmplTexRect = tmplVtxTexCoords->getEffectiveTextureRectangle();

	// Determine the origin of the texture rectangle of this particle, in UV coordinates.
	// This origin is relative to the template texture rectangle, so offset it and scale it
	// by the origin and size of the template texture rectangle.
	CCPoint trOrg;
	trOrg.x = tmplTexRect.origin.x + (aRect.origin.x * tmplTexRect.size.width);
	trOrg.y = tmplTexRect.origin.y + (aRect.origin.y * tmplTexRect.size.height);
	
	// For each vertex, take the offset of the tex coord UV point, relative to the template
	// texture rectangle, scale it by the particle texture rectangle, and offset it by the
	// origin of the particle texture rectangle.
	GLuint vtxCount = getVertexCount();
	for (GLuint vtxIdx = 0; vtxIdx < vtxCount; vtxIdx++) 
	{
		ccTex2F tmplVTC = tmplVtxTexCoords->getTexCoord2FAt( vtxIdx );
		ccTex2F adjVTC;
		adjVTC.u = trOrg.x + ((tmplVTC.u - tmplTexRect.origin.x) * aRect.size.width);
		adjVTC.v = trOrg.y + ((tmplVTC.v - tmplTexRect.origin.y) * aRect.size.height);
		setVertexTexCoord2F( adjVTC, texUnit, vtxIdx );
	}
}

CCRect CC3MeshParticle::getTextureRectangle()
{
	return CCRectZero; 
}

void CC3MeshParticle::setTextureRectangle( const CCRect& aRect )
{
	GLuint tcCount = getMesh()->getTextureCoordinatesArrayCount();
	for (GLuint tcIdx = 0; tcIdx < tcCount; tcIdx++) 
	{
		setTextureRectangle( aRect, tcIdx );
	}
}

/** Returns whether the mesh vertices can be transformed using only translation. */
bool CC3MeshParticle::doesUseTranslationOnly()
{
	return !_rotator->isMutable(); 
}

// If no rotation or scale has been applied, perform an optimized translation operation
// on the vertices, instead of a full tranformation.
void CC3MeshParticle::transformVertices()
{
	if (_isTransformDirty)
	{
		if (doesUseTranslationOnly()) 
			translateVertices();
		else
			fullyTransformVertices();
		
		_isTransformDirty = false;
	}

	transformVertexColors();
}

void CC3MeshParticle::translateVertices()
{
	CC3_TRACE("CC3MeshParticle translating vertices");
	GLuint vtxCount = getVertexCount();
	for (GLuint vtxIdx = 0; vtxIdx < vtxCount; vtxIdx++) 
	{
		CC3Vector vtxLoc = _templateMesh->getVertexLocationAt( vtxIdx );
		setVertexLocation( vtxLoc.add( _location ), vtxIdx );
	}
}

/**
 * Transform the vertices using translation, rotation and scaling, by allocating a transform matrix
 * and transforming it in place using the location, rotator, and scale properties of this particle.
 */
void CC3MeshParticle::fullyTransformVertices()
{
	bool hasNorms = hasVertexNormals();
	GLuint vtxCount = getVertexCount();
	
	// Populate a transform matrix from the transform properties of this particle.
	CC3Matrix4x3 tfmMtx;
	applyLocalTransformsTo( &tfmMtx );
	
	for (GLuint vtxIdx = 0; vtxIdx < vtxCount; vtxIdx++) 
	{
		// Transform the vertex location using the full transform matrix
		CC3Vector4 vtxLoc = _templateMesh->getVertexHomogeneousLocationAt( vtxIdx );
		vtxLoc = CC3Matrix4x3TransformCC3Vector4(&tfmMtx, vtxLoc);
		setVertexHomogeneousLocation( vtxLoc, vtxIdx );
		
		// Transform the vertex normal using only the rotational transform to avoid scaling the normal.
		if (hasNorms) 
		{
			CC3Vector vtxNorm = _templateMesh->getVertexNormalAt( vtxIdx );
			vtxNorm = getRotator()->transformDirection( vtxNorm );
			setVertexNormal( vtxNorm, vtxIdx );
		}
	}
}

/** Apply the location, rotation and scaling transforms to the specified matrix data. */
void CC3MeshParticle::applyLocalTransformsTo( CC3Matrix4x3* mtx )
{
	prepareForTransform( mtx );
	applyTranslationTo( mtx );
	applyRotationTo( mtx );
}

/**
 * Template method that prepares the specified matrix to be transformed by the transform
 * properties of this particle. This implementation starts the matrix as an identity matrix.
 */
void CC3MeshParticle::prepareForTransform( CC3Matrix4x3* mtx )
{
	CC3Matrix4x3PopulateIdentity( mtx );
}

/** Template method that applies the local location property to the specified matrix. */
void CC3MeshParticle::applyTranslationTo( CC3Matrix4x3* mtx )
{
	CC3Matrix4x3TranslateBy( mtx, getLocation() );
}

/** Template method that applies the rotation in the rotator to the specified transform matrix. */
void CC3MeshParticle::applyRotationTo( CC3Matrix4x3* mtx )
{
	_rotator->getRotationMatrix()->multiplyIntoCC3Matrix4x3( mtx );
}

void CC3MeshParticle::markColorDirty()
{
	_isColorDirty = true; 
}

void CC3MeshParticle::transformVertexColors()
{
	if ( !_isColorDirty ) 
		return;
	
	ccColor4F vtxColF;
	ccColor4B vtxColB;
	GLuint vCnt = getVertexCount();
	switch (_emitter->getVertexColorType()) 
	{
		case GL_FLOAT:
			vtxColF = getColor4F();
			for (GLuint vIdx = 0; vIdx < vCnt; vIdx++) 
				setVertexColor4F( vtxColF, vIdx );
			break;
		case GL_FIXED:
		case GL_UNSIGNED_BYTE:
			vtxColB = getColor4B();
			for (GLuint vIdx = 0; vIdx < vCnt; vIdx++)
				setVertexColor4B( vtxColB, vIdx );
			break;
		default:
			break;
	}
	
	_isColorDirty = false;
}

CC3Vector CC3MeshParticle::getVertexLocationAt( GLuint vtxIndex )
{
	return getEmitter()->getVertexLocationAt( _firstVertexOffset + vtxIndex );
}

void CC3MeshParticle::setVertexLocation( const CC3Vector& aLocation, GLuint vtxIndex )
{
	getEmitter()->setVertexLocation( aLocation, _firstVertexOffset + vtxIndex );
}

CC3Vector4 CC3MeshParticle::getVertexHomogeneousLocationAt( GLuint vtxIndex )
{
	return getEmitter()->getVertexHomogeneousLocationAt( _firstVertexOffset + vtxIndex );
}

void CC3MeshParticle::setVertexHomogeneousLocation( const CC3Vector4& aLocation, GLuint vtxIndex )
{
	getEmitter()->setVertexHomogeneousLocation( aLocation, _firstVertexOffset + vtxIndex );
}

CC3Vector CC3MeshParticle::getVertexNormalAt( GLuint vtxIndex )
{
	return getEmitter()->getVertexNormalAt( _firstVertexOffset + vtxIndex );
}

void CC3MeshParticle::setVertexNormal( const CC3Vector& aNormal, GLuint vtxIndex )
{
	getEmitter()->setVertexNormal( aNormal, _firstVertexOffset + vtxIndex );
}

ccColor4F CC3MeshParticle::getVertexColor4FAt( GLuint vtxIndex )
{
	return getEmitter()->getVertexColor4FAt( _firstVertexOffset + vtxIndex );
}

void CC3MeshParticle::setVertexColor4F( const ccColor4F& aColor, GLuint vtxIndex )
{
	getEmitter()->setVertexColor4F( aColor, _firstVertexOffset + vtxIndex );
}

ccColor4B CC3MeshParticle::getVertexColor4BAt( GLuint vtxIndex )
{
	return getEmitter()->getVertexColor4BAt( _firstVertexOffset + vtxIndex );
}

void CC3MeshParticle::setVertexColor4B( const ccColor4B& aColor, GLuint vtxIndex )
{
	getEmitter()->setVertexColor4B( aColor, _firstVertexOffset + vtxIndex );
}

ccTex2F CC3MeshParticle::getVertexTexCoord2FForTextureUnit( GLuint texUnit, GLuint vtxIndex )
{
	return getEmitter()->getVertexTexCoord2FForTextureUnit( texUnit,_firstVertexOffset + vtxIndex );
}

void CC3MeshParticle::setVertexTexCoord2F( const ccTex2F& aTex2F, GLuint texUnit, GLuint vtxIndex )
{
	getEmitter()->setVertexTexCoord2F( aTex2F, texUnit, _firstVertexOffset + vtxIndex );
}

ccTex2F CC3MeshParticle::getVertexTexCoord2FAt( GLuint vtxIndex )
{
	return getVertexTexCoord2FForTextureUnit( 0, vtxIndex );
}

void CC3MeshParticle::setVertexTexCoord2F( const ccTex2F& aTex2F, GLuint vtxIndex )
{
	setVertexTexCoord2F( aTex2F, 0, vtxIndex );
}

GLuint CC3MeshParticle::getVertexIndexAt( GLuint vtxIndex )
{
	return getEmitter()->getVertexIndexAt( _firstVertexIndexOffset + vtxIndex ) - _firstVertexOffset;
}

void CC3MeshParticle::setVertexIndex( GLuint vertexIndex, GLuint vtxIndex )
{
	getEmitter()->setVertexIndex( vertexIndex + _firstVertexOffset, _firstVertexIndexOffset + vtxIndex );
}

bool CC3MeshParticle::hasVertexLocations()
{
	return getMesh()->hasVertexLocations(); 
}

bool CC3MeshParticle::hasVertexNormals()
{
	return getMesh()->hasVertexNormals(); 
}

bool CC3MeshParticle::hasVertexColors()
{
	return getMesh()->hasVertexColors(); 
}

bool CC3MeshParticle::hasVertexTextureCoordinates()
{
	return getMesh()->hasVertexTextureCoordinates(); 
}

bool CC3MeshParticle::init()
{
	if ( super::init() ) 
	{
		setRotator( CC3Rotator::rotator() );
		_templateMesh = NULL;
		_location = CC3Vector::kCC3VectorZero;
		_firstVertexOffset = 0;
		_firstVertexIndexOffset = 0;
		_isTransformDirty = true;		// Force transform on first update
		_isColorDirty = true;			// Force color update

		return true;
	}
	return false;
}

void CC3MeshParticle::setTemplateMesh( CC3Mesh* templateMesh )
{
	CC_SAFE_RELEASE( _templateMesh );
	_templateMesh = templateMesh;
	CC_SAFE_RETAIN( templateMesh );
}

CC3Mesh* CC3MeshParticle::getTemplateMesh()
{
	return _templateMesh;
}

CC3MeshParticle* CC3MeshParticle::particle()
{
	CC3MeshParticle* pParticle = new CC3MeshParticle;
	pParticle->init();
	pParticle->autorelease();

	return pParticle;
}

void CC3MeshParticle::populateFrom( CC3MeshParticle* another )
{
	super::populateFrom( another );
	
	setRotator( (CC3Rotator*)another->getRotator()->copy()->autorelease() );
	setTemplateMesh( another->getTemplateMesh() );
	_location = another->getLocation();
	_firstVertexOffset = another->getFirstVertexOffset();
	_firstVertexIndexOffset = another->getFirstVertexIndexOffset();
	_isTransformDirty = another->isTransformDirty();
	_isColorDirty = another->isColorDirty();
}

CCObject* CC3MeshParticle::copyWithZone( CCZone* zone )
{
	CC3MeshParticle* pVal = new CC3MeshParticle;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

CC3Vector CC3ScalableMeshParticle::getScale()
{
	return _scale; 
}

void CC3ScalableMeshParticle::setScale( const CC3Vector& aScale )
{
	_scale = aScale;
	markTransformDirty();
}

GLfloat CC3ScalableMeshParticle::getUniformScale()
{
	return (isUniformlyScaledLocally())
					? _scale.x
					: _scale.length() / CC3Vector::kCC3VectorUnitCubeLength;
}

void CC3ScalableMeshParticle::setUniformScale( GLfloat aValue )
{
	setScale( cc3v(aValue, aValue, aValue) );  
}

bool CC3ScalableMeshParticle::isUniformlyScaledLocally()
{
	return (_scale.x == _scale.y) && (_scale.x == _scale.z); 
}

/** Returns whether the mesh vertices can be transformed using only translation. */
bool CC3ScalableMeshParticle::doesUseTranslationOnly()
{
	return super::doesUseTranslationOnly() && isTransformRigid(); 
}

bool CC3ScalableMeshParticle::isTransformRigid() 
{
	return _scale.equals( CC3Vector::kCC3VectorUnitCube ); 
}

/** Invoke super, then apply the scaling transforms to the specified matrix data. */
void CC3ScalableMeshParticle::applyLocalTransformsTo( CC3Matrix4x3* mtx )
{
	super::applyLocalTransformsTo( mtx );
	applyScalingTo( mtx );
}

/** Template method that applies the local scale property to the specified transform matrix. */
void CC3ScalableMeshParticle::applyScalingTo( CC3Matrix4x3* mtx )
{
	CC3Matrix4x3ScaleBy(mtx, CC3EnsureMinScaleVector(getScale()));
	CC3_TRACE("CC3ScalableMeshParticle scaled to %s", getScale().stringfy().c_str());
}

bool CC3ScalableMeshParticle::init()
{
	if ( super::init() ) 
	{
		_scale = CC3Vector::kCC3VectorUnitCube;
		return true;
	}

	return false;
}

void CC3ScalableMeshParticle::populateFrom( CC3ScalableMeshParticle* another )
{
	super::populateFrom( another );
	_scale = another->getScale();
}

CCObject* CC3ScalableMeshParticle::copyWithZone( CCZone* zone )
{
	CC3ScalableMeshParticle* pVal = new CC3ScalableMeshParticle;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

NS_COCOS3D_END
