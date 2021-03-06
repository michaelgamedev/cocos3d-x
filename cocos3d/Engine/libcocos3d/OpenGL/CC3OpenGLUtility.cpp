/*
 * Cocos3D-X 1.0.0
 * Author: Bill Hollings
 * Copyright (c) 2010-2014 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Copyright (c) 2014-2015 Jason Wang
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

std::string CC3GLEnumName(GLenum gle)
{
	switch (gle) 
	{
		case GL_ZERO: return "GL_ZERO";
		case GL_ONE: return "GL_ONE";
//		case GL_FALSE: return "GL_FALSE";			// Same as GL_ZERO
//		case GL_TRUE: return "GL_TRUE";				// Same as GL_ONE
			
		// Drawing Mode
//		case GL_POINTS: return "GL_POINTS";			// Same as GL_ZERO
//		case GL_LINES: return "GL_LINES";			// Same as GL_ONE
		case GL_LINE_LOOP: return "GL_LINE_LOOP";
		case GL_LINE_STRIP: return "GL_LINE_STRIP";
		case GL_TRIANGLES: return "GL_TRIANGLES";
		case GL_TRIANGLE_STRIP: return "GL_TRIANGLE_STRIP";
		case GL_TRIANGLE_FAN: return "GL_TRIANGLE_FAN";

		// Alpha and Depth Function
		case GL_DEPTH_FUNC: return "GL_DEPTH_FUNC";
		case GL_NEVER: return "GL_NEVER";
		case GL_LESS: return "GL_LESS";
		case GL_EQUAL: return "GL_EQUAL";
		case GL_LEQUAL: return "GL_LEQUAL";
		case GL_GREATER: return "GL_GREATER";
		case GL_NOTEQUAL: return "GL_NOTEQUAL";
		case GL_GEQUAL: return "GL_GEQUAL";
		case GL_ALWAYS: return "GL_ALWAYS";

		case GL_POLYGON_OFFSET_FACTOR: return "GL_POLYGON_OFFSET_FACTOR";
		case GL_POLYGON_OFFSET_UNITS: return "GL_POLYGON_OFFSET_UNITS";
			
		// Blending
		case GL_SRC_COLOR: return "GL_SRC_COLOR";
		case GL_ONE_MINUS_SRC_COLOR: return "GL_ONE_MINUS_SRC_COLOR";
		case GL_SRC_ALPHA: return "GL_SRC_ALPHA";
		case GL_ONE_MINUS_SRC_ALPHA: return "GL_ONE_MINUS_SRC_ALPHA";
		case GL_DST_ALPHA: return "GL_DST_ALPHA";
		case GL_ONE_MINUS_DST_ALPHA: return "GL_ONE_MINUS_DST_ALPHA";
		case GL_DST_COLOR: return "GL_DST_COLOR";
		case GL_ONE_MINUS_DST_COLOR: return "GL_ONE_MINUS_DST_COLOR";
		case GL_SRC_ALPHA_SATURATE: return "GL_SRC_ALPHA_SATURATE";

		// Cull face mode
		case GL_CULL_FACE_MODE: return "GL_CULL_FACE_MODE";
		case GL_FRONT: return "GL_FRONT";
		case GL_BACK: return "GL_BACK";
		case GL_FRONT_AND_BACK: return "GL_FRONT_AND_BACK";
			
		// Capabilities
		case GL_TEXTURE_2D: return "GL_TEXTURE_2D";
		case GL_CULL_FACE: return "GL_CULL_FACE";
		case GL_BLEND: return "GL_BLEND";
		case GL_DITHER: return "GL_DITHER";
		case GL_STENCIL_TEST: return "GL_STENCIL_TEST";
		case GL_DEPTH_TEST: return "GL_DEPTH_TEST";
		case GL_DEPTH_WRITEMASK: return "GL_DEPTH_WRITEMASK";
		case GL_SCISSOR_TEST: return "GL_SCISSOR_TEST";
		case GL_POLYGON_OFFSET_FILL: return "GL_POLYGON_OFFSET_FILL";
		case GL_SAMPLE_ALPHA_TO_COVERAGE: return "GL_SAMPLE_ALPHA_TO_COVERAGE";
		case GL_SAMPLE_COVERAGE: return "GL_SAMPLE_COVERAGE";
			
		// Front face winding
		case GL_FRONT_FACE: return "GL_FRONT_FACE";
		case GL_CW: return "GL_CW";
		case GL_CCW: return "GL_CCW";

			/* Misc GL state */
		case GL_LINE_WIDTH: return "GL_LINE_WIDTH";
		case GL_SCISSOR_BOX: return "GL_SCISSOR_BOX";

		// Fog
		case GL_EXP: return "GL_EXP";
		case GL_EXP2: return "GL_EXP2";
			
		// Hint Mode and Target
		case GL_DONT_CARE: return "GL_DONT_CARE";
		case GL_FASTEST: return "GL_FASTEST";
		case GL_NICEST: return "GL_NICEST";
		case GL_GENERATE_MIPMAP_HINT: return "GL_GENERATE_MIPMAP_HINT";
			
		// Light parameter
		case GL_LIGHT_MODEL_AMBIENT: return "GL_LIGHT_MODEL_AMBIENT";
		case GL_AMBIENT: return "GL_AMBIENT";
		case GL_DIFFUSE: return "GL_DIFFUSE";
		case GL_SPECULAR: return "GL_SPECULAR";
		case GL_POSITION: return "GL_POSITION";
		case GL_SPOT_DIRECTION: return "GL_SPOT_DIRECTION";
		case GL_SPOT_EXPONENT: return "GL_SPOT_EXPONENT";
		case GL_SPOT_CUTOFF: return "GL_SPOT_CUTOFF";
		case GL_CONSTANT_ATTENUATION: return "GL_CONSTANT_ATTENUATION";
		case GL_LINEAR_ATTENUATION: return "GL_LINEAR_ATTENUATION";
		case GL_QUADRATIC_ATTENUATION: return "GL_QUADRATIC_ATTENUATION";

		// Data type
		case GL_BYTE: return "GL_BYTE";
		case GL_UNSIGNED_BYTE: return "GL_UNSIGNED_BYTE";
		case GL_SHORT: return "GL_SHORT";
		case GL_UNSIGNED_SHORT: return "GL_UNSIGNED_SHORT";
		case GL_FIXED: return "GL_FIXED";
		case GL_UNSIGNED_INT: return "GL_UNSIGNED_INT";

		case GL_INT_VEC2: return "GL_INT_VEC2";
		case GL_INT_VEC3: return "GL_INT_VEC3";
		case GL_INT_VEC4: return "GL_INT_VEC4";
			
		case GL_BOOL: return "GL_BOOL";
		case GL_BOOL_VEC2: return "GL_BOOL_VEC2";
		case GL_BOOL_VEC3: return "GL_BOOL_VEC3";
		case GL_BOOL_VEC4: return "GL_BOOL_VEC4";
			
		case GL_FLOAT: return "GL_FLOAT";
		case GL_FLOAT_VEC2: return "GL_FLOAT_VEC2";
		case GL_FLOAT_VEC3: return "GL_FLOAT_VEC3";
		case GL_FLOAT_VEC4: return "GL_FLOAT_VEC4";
			
		case GL_FLOAT_MAT2: return "GL_FLOAT_MAT2";
		case GL_FLOAT_MAT3: return "GL_FLOAT_MAT3";
		case GL_FLOAT_MAT4: return "GL_FLOAT_MAT4";
			
		case GL_SAMPLER_2D: return "GL_SAMPLER_2D";
		case GL_SAMPLER_CUBE: return "GL_SAMPLER_CUBE";
			
			// Shaders
		case GL_VERTEX_SHADER: return "GL_VERTEX_SHADER";
		case GL_FRAGMENT_SHADER: return "GL_FRAGMENT_SHADER";
		case GL_MAX_VERTEX_ATTRIBS: return "GL_MAX_VERTEX_ATTRIBS";
		case GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS: return "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS";
		case GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS: return "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS";
		case GL_MAX_TEXTURE_IMAGE_UNITS: return "GL_MAX_TEXTURE_IMAGE_UNITS";
		case GL_SHADER_TYPE: return "GL_SHADER_TYPE";
		case GL_DELETE_STATUS: return "GL_DELETE_STATUS";
		case GL_LINK_STATUS: return "GL_LINK_STATUS";
		case GL_VALIDATE_STATUS: return "GL_VALIDATE_STATUS";
		case GL_ATTACHED_SHADERS: return "GL_ATTACHED_SHADERS";
		case GL_ACTIVE_UNIFORMS: return "GL_ACTIVE_UNIFORMS";
		case GL_ACTIVE_UNIFORM_MAX_LENGTH: return "GL_ACTIVE_UNIFORM_MAX_LENGTH";
		case GL_ACTIVE_ATTRIBUTES: return "GL_ACTIVE_ATTRIBUTES";
		case GL_ACTIVE_ATTRIBUTE_MAX_LENGTH: return "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH";
		case GL_SHADING_LANGUAGE_VERSION: return "GL_SHADING_LANGUAGE_VERSION";
		case GL_CURRENT_PROGRAM: return "GL_CURRENT_PROGRAM";
			
		// MaterialParameter
		case GL_EMISSION: return "GL_EMISSION";
		case GL_SHININESS: return "GL_SHININESS";
		case GL_BLEND_SRC_RGB: return "GL_BLEND_SRC_RGB";
		case GL_BLEND_SRC_ALPHA: return "GL_BLEND_SRC_ALPHA";
		case GL_BLEND_DST_RGB: return "GL_BLEND_DST_RGB";
		case GL_BLEND_DST_ALPHA: return "GL_BLEND_DST_ALPHA";
			
		// MatrixMode
		case GL_MODELVIEW: return "GL_MODELVIEW";
		case GL_PROJECTION: return "GL_PROJECTION";
		case GL_TEXTURE: return "GL_TEXTURE";
			
		// PixelFormat
		case GL_ALPHA: return "GL_ALPHA";
		case GL_RGB: return "GL_RGB";
		case GL_RGBA: return "GL_RGBA";
		case GL_LUMINANCE: return "GL_LUMINANCE";
		case GL_LUMINANCE_ALPHA: return "GL_LUMINANCE_ALPHA";
		case GL_UNSIGNED_SHORT_5_6_5: return "GL_UNSIGNED_SHORT_5_6_5";
		case GL_UNSIGNED_SHORT_4_4_4_4: return "GL_UNSIGNED_SHORT_4_4_4_4";
		case GL_UNSIGNED_SHORT_5_5_5_1: return "GL_UNSIGNED_SHORT_5_5_5_1";
		case GL_DEPTH_COMPONENT: return "GL_DEPTH_COMPONENT";
			
		// Shading Model
		case GL_SHADE_MODEL: return "GL_SHADE_MODEL";
		case GL_FLAT: return "GL_FLAT";
		case GL_SMOOTH: return "GL_SMOOTH";
			
		// TextureUnits
		case GL_TEXTURE_BINDING_2D: return "GL_TEXTURE_BINDING_2D";
		case GL_TEXTURE_BINDING_CUBE_MAP: return "GL_TEXTURE_BINDING_CUBE_MAP";
		case GL_ACTIVE_TEXTURE: return "GL_ACTIVE_TEXTURE";
		case GL_TEXTURE0: return "GL_TEXTURE0";
		case GL_TEXTURE1: return "GL_TEXTURE1";
		case GL_TEXTURE2: return "GL_TEXTURE2";
		case GL_TEXTURE3: return "GL_TEXTURE3";
		case GL_TEXTURE4: return "GL_TEXTURE4";
		case GL_TEXTURE5: return "GL_TEXTURE5";
		case GL_TEXTURE6: return "GL_TEXTURE6";
		case GL_TEXTURE7: return "GL_TEXTURE7";
		case GL_TEXTURE8: return "GL_TEXTURE8";
		case GL_TEXTURE9: return "GL_TEXTURE9";
		case GL_TEXTURE10: return "GL_TEXTURE10";
		case GL_TEXTURE11: return "GL_TEXTURE11";
		case GL_TEXTURE12: return "GL_TEXTURE12";
		case GL_TEXTURE13: return "GL_TEXTURE13";
		case GL_TEXTURE14: return "GL_TEXTURE14";
		case GL_TEXTURE15: return "GL_TEXTURE15";
		case GL_TEXTURE16: return "GL_TEXTURE16";
		case GL_TEXTURE17: return "GL_TEXTURE17";
		case GL_TEXTURE18: return "GL_TEXTURE18";
		case GL_TEXTURE19: return "GL_TEXTURE19";
		case GL_TEXTURE20: return "GL_TEXTURE20";
		case GL_TEXTURE21: return "GL_TEXTURE21";
		case GL_TEXTURE22: return "GL_TEXTURE22";
		case GL_TEXTURE23: return "GL_TEXTURE23";
		case GL_TEXTURE24: return "GL_TEXTURE24";
		case GL_TEXTURE25: return "GL_TEXTURE25";
		case GL_TEXTURE26: return "GL_TEXTURE26";
		case GL_TEXTURE27: return "GL_TEXTURE27";
		case GL_TEXTURE28: return "GL_TEXTURE28";
		case GL_TEXTURE29: return "GL_TEXTURE29";
		case GL_TEXTURE30: return "GL_TEXTURE30";
		case GL_TEXTURE31: return "GL_TEXTURE31";

		// Texture Environment parameters
		case GL_TEXTURE_MIN_FILTER: return "GL_TEXTURE_MIN_FILTER";
		case GL_TEXTURE_MAG_FILTER: return "GL_TEXTURE_MAG_FILTER";
		case GL_NEAREST: return "GL_NEAREST";
		case GL_LINEAR: return "GL_LINEAR";
		case GL_NEAREST_MIPMAP_NEAREST: return "GL_NEAREST_MIPMAP_NEAREST";
		case GL_LINEAR_MIPMAP_NEAREST: return "GL_LINEAR_MIPMAP_NEAREST";
		case GL_NEAREST_MIPMAP_LINEAR: return "GL_NEAREST_MIPMAP_LINEAR";
		case GL_LINEAR_MIPMAP_LINEAR: return "GL_LINEAR_MIPMAP_LINEAR";
		case GL_TEXTURE_WRAP_S: return "GL_TEXTURE_WRAP_S";
		case GL_TEXTURE_WRAP_T: return "GL_TEXTURE_WRAP_T";
		case GL_CLAMP_TO_EDGE: return "GL_CLAMP_TO_EDGE";
		case GL_REPEAT: return "GL_REPEAT";

		// Texture Environment parameters
		case GL_MAX_TEXTURE_SIZE: return "GL_MAX_TEXTURE_SIZE";
		case GL_TEXTURE_ENV: return "GL_TEXTURE_ENV";
		case GL_TEXTURE_ENV_MODE: return "GL_TEXTURE_ENV_MODE";
		case GL_TEXTURE_ENV_COLOR: return "GL_TEXTURE_ENV_COLOR";
		case GL_MODULATE: return "GL_MODULATE";
		case GL_DECAL: return "GL_DECAL";
		case GL_ADD: return "GL_ADD";
		case GL_REPLACE: return "GL_REPLACE";
		case GL_COMBINE: return "GL_COMBINE";
		
		case GL_SUBTRACT: return "GL_SUBTRACT";
		case GL_COMBINE_RGB: return "GL_COMBINE_RGB";
		case GL_COMBINE_ALPHA: return "GL_COMBINE_ALPHA";
		case GL_ADD_SIGNED: return "GL_ADD_SIGNED";
		case GL_INTERPOLATE: return "GL_INTERPOLATE";
		case GL_CONSTANT: return "GL_CONSTANT";
		case GL_PRIMARY_COLOR: return "GL_PRIMARY_COLOR";
		case GL_PREVIOUS: return "GL_PREVIOUS";
		case GL_DOT3_RGB: return "GL_DOT3_RGB";
		case GL_DOT3_RGBA: return "GL_DOT3_RGBA";

		case GL_SRC0_RGB: return "GL_SRC0_RGB";
		case GL_SRC1_RGB: return "GL_SRC1_RGB";
		case GL_SRC2_RGB: return "GL_SRC2_RGB";
		case GL_OPERAND0_RGB: return "GL_OPERAND0_RGB";
		case GL_OPERAND1_RGB: return "GL_OPERAND1_RGB";
		case GL_OPERAND2_RGB: return "GL_OPERAND2_RGB";
		case GL_RGB_SCALE: return "GL_RGB_SCALE";

		case GL_SRC0_ALPHA: return "GL_SRC0_ALPHA";
		case GL_SRC1_ALPHA: return "GL_SRC1_ALPHA";
		case GL_SRC2_ALPHA: return "GL_SRC2_ALPHA";
		case GL_OPERAND0_ALPHA: return "GL_OPERAND0_ALPHA";
		case GL_OPERAND1_ALPHA: return "GL_OPERAND1_ALPHA";
		case GL_OPERAND2_ALPHA: return "GL_OPERAND2_ALPHA";
		case GL_ALPHA_SCALE: return "GL_ALPHA_SCALE";

		// Cube maps
		case GL_TEXTURE_CUBE_MAP: return "GL_TEXTURE_CUBE_MAP";
		case GL_TEXTURE_CUBE_MAP_POSITIVE_X: return "GL_TEXTURE_CUBE_MAP_POSITIVE_X";
		case GL_TEXTURE_CUBE_MAP_NEGATIVE_X: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X";
		case GL_TEXTURE_CUBE_MAP_POSITIVE_Y: return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y";
		case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y";
		case GL_TEXTURE_CUBE_MAP_POSITIVE_Z: return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z";
		case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z";
		case GL_MAX_CUBE_MAP_TEXTURE_SIZE: return "GL_MAX_CUBE_MAP_TEXTURE_SIZE";
			
		// Buffer Objects
		case GL_ARRAY_BUFFER: return "GL_ARRAY_BUFFER";
		case GL_ELEMENT_ARRAY_BUFFER: return "GL_ELEMENT_ARRAY_BUFFER";
		case GL_ARRAY_BUFFER_BINDING: return "GL_ARRAY_BUFFER_BINDING";
		case GL_ELEMENT_ARRAY_BUFFER_BINDING: return "GL_ELEMENT_ARRAY_BUFFER_BINDING";
		case GL_STATIC_DRAW: return "GL_STATIC_DRAW";
		case GL_DYNAMIC_DRAW: return "GL_DYNAMIC_DRAW";
		case GL_BUFFER_SIZE: return "GL_BUFFER_SIZE";
		case GL_BUFFER_USAGE: return "GL_BUFFER_USAGE";

		// Vertex arrays
		case GL_VERTEX_ATTRIB_ARRAY_ENABLED: return "GL_VERTEX_ATTRIB_ARRAY_ENABLED";
		case GL_VERTEX_ATTRIB_ARRAY_SIZE: return "GL_VERTEX_ATTRIB_ARRAY_SIZE";
		case GL_VERTEX_ATTRIB_ARRAY_STRIDE: return "GL_VERTEX_ATTRIB_ARRAY_STRIDE";
		case GL_VERTEX_ATTRIB_ARRAY_TYPE: return "GL_VERTEX_ATTRIB_ARRAY_TYPE";
		case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED: return "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED";
		case GL_VERTEX_ATTRIB_ARRAY_POINTER: return "GL_VERTEX_ATTRIB_ARRAY_POINTER";
		case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: return "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING";


		// Get pnames
		case GL_VIEWPORT: return "GL_VIEWPORT";

		// Clearing values
		case GL_COLOR_CLEAR_VALUE: return "GL_COLOR_CLEAR_VALUE";
		case GL_DEPTH_CLEAR_VALUE: return "GL_DEPTH_CLEAR_VALUE";
		case GL_STENCIL_CLEAR_VALUE: return "GL_STENCIL_CLEAR_VALUE";

		// Stencils
		case GL_STENCIL_FUNC: return "GL_STENCIL_FUNC";
		case GL_STENCIL_REF: return "GL_STENCIL_REF";
		case GL_STENCIL_VALUE_MASK: return "GL_STENCIL_VALUE_MASK";
		case GL_STENCIL_FAIL: return "GL_STENCIL_FAIL";
		case GL_STENCIL_PASS_DEPTH_FAIL: return "GL_STENCIL_PASS_DEPTH_FAIL";
		case GL_STENCIL_PASS_DEPTH_PASS: return "GL_STENCIL_PASS_DEPTH_PASS";
		case GL_KEEP: return "GL_KEEP";
		case GL_INCR: return "GL_INCR";
		case GL_DECR: return "GL_DECR";
		case GL_INVERT: return "GL_INVERT";
		case GL_INCR_WRAP: return "GL_INCR_WRAP";
		case GL_DECR_WRAP: return "GL_DECR_WRAP";
			
		// Shaders
		case GL_COMPILE_STATUS: return "GL_COMPILE_STATUS";
		case GL_INFO_LOG_LENGTH: return "GL_INFO_LOG_LENGTH";
		case GL_SHADER_SOURCE_LENGTH: return "GL_SHADER_SOURCE_LENGTH";
			
		// Framebuffers
		case GL_FRAMEBUFFER: return "GL_FRAMEBUFFER";
		case GL_COLOR_ATTACHMENT0: return "GL_COLOR_ATTACHMENT0";
		case GL_DEPTH_ATTACHMENT: return "GL_DEPTH_ATTACHMENT";
		case GL_STENCIL_ATTACHMENT: return "GL_STENCIL_ATTACHMENT";
		case GL_FRAMEBUFFER_COMPLETE: return "GL_FRAMEBUFFER_COMPLETE";
		case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: return "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
		case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: return "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
		case GL_FRAMEBUFFER_UNSUPPORTED: return "GL_FRAMEBUFFER_UNSUPPORTED";
		case GL_FRAMEBUFFER_BINDING: return "GL_FRAMEBUFFER_BINDING";

		case GL_RENDERBUFFER: return "GL_RENDERBUFFER";
		case GL_RENDERBUFFER_BINDING: return "GL_RENDERBUFFER_BINDING";
		case GL_MAX_RENDERBUFFER_SIZE: return "GL_MAX_RENDERBUFFER_SIZE";
		case GL_RENDERBUFFER_WIDTH: return "GL_RENDERBUFFER_WIDTH";
		case GL_RENDERBUFFER_HEIGHT: return "GL_RENDERBUFFER_HEIGHT";
		case GL_RENDERBUFFER_INTERNAL_FORMAT: return "GL_RENDERBUFFER_INTERNAL_FORMAT";
		case GL_RENDERBUFFER_RED_SIZE: return "GL_RENDERBUFFER_RED_SIZE";
		case GL_RENDERBUFFER_GREEN_SIZE: return "GL_RENDERBUFFER_GREEN_SIZE";
		case GL_RENDERBUFFER_BLUE_SIZE: return "GL_RENDERBUFFER_BLUE_SIZE";
		case GL_RENDERBUFFER_ALPHA_SIZE: return "GL_RENDERBUFFER_ALPHA_SIZE";
		case GL_RENDERBUFFER_DEPTH_SIZE: return "GL_RENDERBUFFER_DEPTH_SIZE";
		case GL_RENDERBUFFER_STENCIL_SIZE: return "GL_RENDERBUFFER_STENCIL_SIZE";

		case GL_RGB8: return "GL_RGB8";
		case GL_RGBA8: return "GL_RGBA8";
		case GL_RGBA4: return "GL_RGBA4";
		case GL_RGB5_A1: return "GL_RGB5_A1";
		case GL_RGB565: return "GL_RGB565";
		case GL_DEPTH_COMPONENT16: return "GL_DEPTH_COMPONENT16";
		case GL_DEPTH_COMPONENT24: return "GL_DEPTH_COMPONENT24";
		case GL_STENCIL_INDEX8: return "GL_STENCIL_INDEX8";
		case GL_DEPTH24_STENCIL8: return "GL_DEPTH24_STENCIL8";
		case GL_UNSIGNED_INT_24_8: return "GL_UNSIGNED_INT_24_8";
		case GL_DEPTH_STENCIL: return "GL_DEPTH_STENCIL";

		// Miscellaneous & extensions
		case GL_VENDOR: return "GL_VENDOR";
		case GL_RENDERER: return "GL_RENDERER";
		case GL_VERSION: return "GL_VERSION";
		case GL_EXTENSIONS: return "GL_EXTENSIONS";
		case GL_PACK_ALIGNMENT: return "GL_PACK_ALIGNMENT";
		case GL_UNPACK_ALIGNMENT: return "GL_UNPACK_ALIGNMENT";

#if !APPORTABLE && !_WIN32
		case GL_BUFFER_OBJECT_EXT: return "GL_BUFFER_OBJECT_EXT";
		case GL_SHADER_OBJECT_EXT: return "GL_SHADER_OBJECT_EXT";
		case GL_PROGRAM_OBJECT_EXT: return "GL_PROGRAM_OBJECT_EXT";
		case GL_VERTEX_ARRAY_OBJECT_EXT: return "GL_VERTEX_ARRAY_OBJECT_EXT";
		case GL_QUERY_OBJECT_EXT: return "GL_QUERY_OBJECT_EXT";
#endif	// !APPORTABLE
			
#if CC3_IOS
		case GL_INT: return "GL_INT";
		case GL_MAX_VERTEX_UNIFORM_VECTORS: return "GL_MAX_VERTEX_UNIFORM_VECTORS";
		case GL_MAX_VARYING_VECTORS: return "GL_MAX_VARYING_VECTORS";
		case GL_MAX_FRAGMENT_UNIFORM_VECTORS: return "GL_MAX_FRAGMENT_UNIFORM_VECTORS";
		case GL_LOW_FLOAT: return "GL_LOW_FLOAT";
		case GL_MEDIUM_FLOAT: return "GL_MEDIUM_FLOAT";
		case GL_HIGH_FLOAT: return "GL_HIGH_FLOAT";
		case GL_LOW_INT: return "GL_LOW_INT";
		case GL_MEDIUM_INT: return "GL_MEDIUM_INT";
		case GL_HIGH_INT: return "GL_HIGH_INT";
		case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS: return "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS";
		case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_APPLE: return "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_APPLE";
		case GL_SHADER_COMPILER: return "GL_SHADER_COMPILER";
		case GL_READ_FRAMEBUFFER_APPLE: return "GL_READ_FRAMEBUFFER_APPLE";
		case GL_DRAW_FRAMEBUFFER_APPLE: return "GL_DRAW_FRAMEBUFFER_APPLE";
		case GL_READ_FRAMEBUFFER_BINDING_APPLE: return "GL_READ_FRAMEBUFFER_BINDING_APPLE";
		case GL_MAX_SAMPLES_APPLE: return "GL_MAX_SAMPLES_APPLE";
#if !APPORTABLE
		case GL_PROGRAM_PIPELINE_OBJECT_EXT: return "GL_PROGRAM_PIPELINE_OBJECT_EXT";
#endif	// !APPORTABLE
#endif	// CC3_IOS

#if CC3_OGL
		case GL_POINT_SPRITE: return "GL_POINT_SPRITE";
#endif	// CC3_OGL
		
		default:
			printf("***ERROR: UNKNOWN_GLENUM (0x%04X)\n", gle);
			return "UNKNOWN_GLENUM";
	}
}

size_t CC3GLElementTypeSize(GLenum dataType) 
{
	switch (dataType) {
		case GL_BYTE: return sizeof(GLbyte);
		case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
		case GL_SHORT: return sizeof(GLshort);
		case GL_UNSIGNED_SHORT: return sizeof(GLushort);
		//case GL_FIXED: return sizeof(GLfixed);
		case GL_UNSIGNED_INT: return sizeof(GLuint);
			
		case GL_INT_VEC2: return sizeof(GLint) * 2;
		case GL_INT_VEC3: return sizeof(GLint) * 3;
		case GL_INT_VEC4: return sizeof(GLint) * 4;
			
		case GL_SAMPLER_2D: return sizeof(GLint);		// Uses glUniform1i
		case GL_SAMPLER_CUBE: return sizeof(GLint);		// Uses glUniform1i
			
		case GL_BOOL: return sizeof(GLint);				// Uses glUniform1i or glUniform1f
		case GL_BOOL_VEC2: return sizeof(GLint) * 2;	// Uses glUniform2i or glUniform2f
		case GL_BOOL_VEC3: return sizeof(GLint) * 3;	// Uses glUniform3i or glUniform3f
		case GL_BOOL_VEC4: return sizeof(GLint) * 4;	// Uses glUniform4i or glUniform4f
			
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_FLOAT_VEC2: return sizeof(GLfloat) * 2;
		case GL_FLOAT_VEC3: return sizeof(GLfloat) * 3;
		case GL_FLOAT_VEC4: return sizeof(GLfloat) * 4;
			
		case GL_FLOAT_MAT2: return sizeof(GLfloat) * 2 * 2;
		case GL_FLOAT_MAT3: return sizeof(GLfloat) * 3 * 3;
		case GL_FLOAT_MAT4: return sizeof(GLfloat) * 4 * 4;

		case GL_INT: return sizeof(GLint);
			
		default: return 0;
	}	
}

GLenum CC3GLColorFormatFromBitPlanes(GLint colorCount, GLint alphaCount) 
{
	//LogTrace(@"Color buffer size: %i, alpha size: %i", colorCount, alphaCount);
	switch (alphaCount) {
		case 0:
			switch (colorCount) {
				case 12: return GL_RGB4;
				case 15: return GL_RGB5;
				case 24: return GL_RGB8;
				case 48: return GL_RGB16;
			}
		case 1:
			if (colorCount == 16) return GL_RGB5_A1;
		case 2:
			if (colorCount == 8) return GL_RGBA2;
			if (colorCount == 32) return GL_RGB10_A2;
		case 4:
			if (colorCount == 16) return GL_RGBA4;
		case 8:
			if (colorCount == 32) return GL_RGBA8;
		case 12:
			if (colorCount == 48) return GL_RGBA12;
		case 16:
			if (colorCount == 64) return GL_RGBA16;
	}
	CCAssert(false, "Unrecognized color buffer bit plane combination: color %d, alpha: %d"/*, colorCount, alphaCount*/);
	return GL_ZERO;
}

GLenum CC3GLDepthFormatFromBitPlanes(GLint depthCount, GLint stencilCount)
{
	//LogTrace(@"Depth buffer size: %i, stencil size: %i", depthCount, stencilCount);
	
	if (depthCount && stencilCount) return GL_DEPTH24_STENCIL8;
	
	switch (depthCount)
	{
		case 0: return GL_ZERO;
		case 16: return GL_DEPTH_COMPONENT16;
		case 24: return GL_DEPTH_COMPONENT24;
		case 32: return GL_DEPTH_COMPONENT32;
	}
	CCAssert(false, "Unrecognized depth buffer bit plane combination: depth %d, stencil: %d"/*, depthCount, stencilCount*/);
	return GL_ZERO;
}

NS_COCOS3D_END
