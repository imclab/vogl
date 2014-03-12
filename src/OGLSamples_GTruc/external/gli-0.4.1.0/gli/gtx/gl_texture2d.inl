///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/gtx/gl_texture2d.inl
/// @date 2010-09-27 / 2013-01-13
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

namespace gli{
namespace detail
{
	//GL_COMPRESSED_RED, GL_COMPRESSED_RG, GL_COMPRESSED_RGB, GL_COMPRESSED_RGBA, GL_COMPRESSED_SRGB, GL_COMPRESSED_SRGB_ALPHA, 
	//GL_SRGB, GL_SRGB8, GL_SRGB_ALPHA, or GL_SRGB8_ALPHA8
	struct texture_desc
	{
		GLint InternalFormat;
		GLint InternalFormatCompressed;
		GLint InternalFormatSRGB;
		GLint InternalFormatCompressedSRGB;
		GLenum ExternalFormat;
		GLenum ExternalFormatRev;
		GLenum Type;
	};

	//GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, and GL_BGRA.
	//GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, 
	//GL_INT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, 
	//GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, 
	//GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV, 
	//GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, 
	//GL_UNSIGNED_INT_2_10_10_10_REV

#	ifndef GL_COMPRESSED_RGBA_BPTC_UNORM_ARB
#	define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#	endif

#	ifndef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB
#	define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#	endif

#	ifndef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB
#	define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#	endif

#	ifndef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB
#	define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#	endif

	inline texture_desc gli2ogl_cast(format const & Format)
	{
		texture_desc Cast[] = 
		{
			{GL_NONE, GL_NONE, GL_NONE,	GL_NONE, GL_NONE, GL_NONE, GL_NONE},

			//// Normalized
			//{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_UNSIGNED_BYTE},
			//{GL_RG,		GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_UNSIGNED_BYTE},
			//{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_UNSIGNED_BYTE},
			//{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_UNSIGNED_BYTE},

			//{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_UNSIGNED_SHORT},
			//{GL_RG,		GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_UNSIGNED_SHORT},
			//{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_UNSIGNED_SHORT},
			//{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_UNSIGNED_SHORT},

			//{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_UNSIGNED_INT},
			//{GL_RG,		GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_UNSIGNED_INT},
			//{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_UNSIGNED_INT},
			//{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_UNSIGNED_INT},

			// Unsigned
			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_UNSIGNED_BYTE},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_UNSIGNED_BYTE},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_UNSIGNED_BYTE},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_UNSIGNED_BYTE},

			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_UNSIGNED_SHORT},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_UNSIGNED_SHORT},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_UNSIGNED_SHORT},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_UNSIGNED_SHORT},

			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_UNSIGNED_INT},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_UNSIGNED_INT},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_UNSIGNED_INT},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_UNSIGNED_INT},

			// Signed
			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_BYTE},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_BYTE},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_BYTE},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_BYTE},

			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_SHORT},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_SHORT},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_SHORT},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_SHORT},

			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_INT},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_INT},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_INT},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_INT},

			// Float
			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_HALF_FLOAT},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_HALF_FLOAT},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_HALF_FLOAT},

			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_FLOAT},
			{GL_RG,			GL_COMPRESSED_RG,		GL_RG,				GL_COMPRESSED_RG,				GL_RG,			GL_RG,		GL_FLOAT},
			{GL_RGB,		GL_COMPRESSED_RGB,		GL_SRGB8,			GL_COMPRESSED_SRGB,				GL_RGB,			GL_BGR,		GL_FLOAT},
			{GL_RGBA,		GL_COMPRESSED_RGBA,		GL_SRGB8_ALPHA8,	GL_COMPRESSED_SRGB_ALPHA,		GL_RGBA,		GL_BGRA,	GL_FLOAT},

			// Packed
			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},
			{GL_RGB9_E5,	GL_RGB9_E5,				GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},
			{GL_R11F_G11F_B10F,	GL_R11F_G11F_B10F,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},
			{GL_RED,		GL_COMPRESSED_RED,		GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},
			{GL_RGBA4,		GL_RGBA4,				GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},
			{GL_RGB10_A2,	GL_RGB10_A2,			GL_RED,				GL_COMPRESSED_RED,				GL_RED,			GL_RED,		GL_HALF_FLOAT},

			// Depth
			{GL_DEPTH_COMPONENT16,	GL_DEPTH_COMPONENT16,	GL_DEPTH_COMPONENT16,	GL_DEPTH_COMPONENT16,	GL_DEPTH_COMPONENT,		GL_DEPTH_COMPONENT,		GL_UNSIGNED_SHORT},
			{GL_DEPTH_COMPONENT24,	GL_DEPTH_COMPONENT24,	GL_DEPTH_COMPONENT24,	GL_DEPTH_COMPONENT24,	GL_DEPTH_COMPONENT,		GL_DEPTH_COMPONENT,		GL_UNSIGNED_INT},
			{GL_DEPTH24_STENCIL8,	GL_DEPTH24_STENCIL8,	GL_DEPTH24_STENCIL8,	GL_DEPTH24_STENCIL8,	GL_DEPTH_COMPONENT,		GL_DEPTH_STENCIL,		GL_UNSIGNED_INT},
			{GL_DEPTH_COMPONENT32F,	GL_DEPTH_COMPONENT32F,	GL_DEPTH_COMPONENT32F,	GL_DEPTH_COMPONENT32F,	GL_DEPTH_COMPONENT,		GL_DEPTH_COMPONENT,		GL_FLOAT},
			{GL_DEPTH32F_STENCIL8,	GL_DEPTH32F_STENCIL8,	GL_DEPTH32F_STENCIL8,	GL_DEPTH32F_STENCIL8,	GL_DEPTH_COMPONENT,		GL_DEPTH_STENCIL,		GL_UNSIGNED_INT},

			// Compressed formats
			{GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,			GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,			GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,			GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,			GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RED_RGTC1,					GL_COMPRESSED_RED_RGTC1,					GL_COMPRESSED_RED_RGTC1,					GL_COMPRESSED_RED_RGTC1,					GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_SIGNED_RED_RGTC1,			GL_COMPRESSED_SIGNED_RED_RGTC1,				GL_COMPRESSED_SIGNED_RED_RGTC1,				GL_COMPRESSED_SIGNED_RED_RGTC1,				GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RG_RGTC2,					GL_COMPRESSED_RG_RGTC2,						GL_COMPRESSED_RG_RGTC2,						GL_COMPRESSED_RG_RGTC2,						GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_SIGNED_RG_RGTC2,				GL_COMPRESSED_SIGNED_RG_RGTC2,				GL_COMPRESSED_SIGNED_RG_RGTC2,				GL_COMPRESSED_SIGNED_RG_RGTC2,				GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB,	GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB,	GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB,	GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB,	GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB,	GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB,	GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB,	GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB,	GL_NONE, GL_NONE, GL_NONE},
			{GL_COMPRESSED_RGBA_BPTC_UNORM_ARB,			GL_COMPRESSED_RGBA_BPTC_UNORM_ARB,			GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB,	GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB,	GL_NONE, GL_NONE, GL_NONE},
		};

		return Cast[Format];
	}

}//namespace detail

	inline GLuint createTexture2D(std::string const & Filename)
	{
		gli::texture2D Texture(gli::loadStorageDDS(Filename));
		if(Texture.empty())
			return 0;

		detail::format_desc Desc = detail::getFormatInfo(Texture.format());

		GLint Alignment = 0;
		GLint CurrentTextureName = 0;
		glGetIntegerv(GL_UNPACK_ALIGNMENT, &Alignment);
		glGetIntegerv(GL_TEXTURE_BINDING_2D, &CurrentTextureName);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		GLuint Name = 0;
		glGenTextures(1, &Name);
		glBindTexture(GL_TEXTURE_2D, Name);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Texture.levels() > 1 ? GL_NEAREST_MIPMAP_NEAREST : GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		if(gli::bits_per_pixel(Texture.format()) == gli::block_size(Texture.format()))
		{
			for(gli::texture2D::size_type Level = 0; Level < Texture.levels(); ++Level)
			{
				glTexImage2D(
					GL_TEXTURE_2D, 
					GLint(Level), 
					Desc.Internal,
					GLsizei(Texture[Level].dimensions().x), 
					GLsizei(Texture[Level].dimensions().y), 
					0,
					Desc.External, 
					Desc.Type, 
					Texture[Level].data());
			}
		}
		else
		{
			for(gli::texture2D::size_type Level = 0; Level < Texture.levels(); ++Level)
			{
				glCompressedTexImage2D(
					GL_TEXTURE_2D,
					GLint(Level),
					Desc.Internal,
					GLsizei(Texture[Level].dimensions().x), 
					GLsizei(Texture[Level].dimensions().y), 
					0, 
					GLsizei(Texture[Level].size()), 
					Texture[Level].data());
			}
		}

		// Restaure previous states
		glBindTexture(GL_TEXTURE_2D, GLuint(CurrentTextureName));
		glPixelStorei(GL_UNPACK_ALIGNMENT, Alignment);

		return Name;
	}

}//namespace gli