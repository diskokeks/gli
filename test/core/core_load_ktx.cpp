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
/// @file gli/test/core_load_ktx.hpp
/// @date 2013-03-12 / 2013-03-12
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <gli/gli.hpp>

int test_texture2d_export()
{
	int Error(0);

	{
		gli::texture2D Texture(gli::loadStorageKTX("../../data/test_rgb8.ktx"));
		assert(!Texture.empty());
		gli::saveStorageKTX(Texture, "../../data/test_rgb8_saved.ktx");
	}
	{
		gli::texture2D Texture(gli::loadStorageKTX("../../data/test_rgb8_saved.ktx"));
		assert(!Texture.empty());
		gli::saveStorageKTX(Texture, "../../data/test_rgb8_reloaded.ktx");
	}
	{
		gli::texture2D Texture(gli::loadStorageKTX("../../data/test_bc1.ktx"));
		assert(!Texture.empty());
		gli::saveStorageKTX(Texture, "../../data/test_bc1_saved.ktx");
	}

	return Error;
}

int main()
{
	int Error(0);

	Error += test_texture2d_export();

	return Error;
}

