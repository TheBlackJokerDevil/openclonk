/*
 * OpenClonk, http://www.openclonk.org
 *
 * Copyright (c) 2001-2009, RedWolf Design GmbH, http://www.clonk.de/
 * Copyright (c) 2013-2016, The OpenClonk Team and contributors
 *
 * Distributed under the terms of the ISC license; see accompanying file
 * "COPYING" for details.
 *
 * "Clonk" is a registered trademark of Matthes Bender, used with permission.
 * See accompanying file "TRADEMARK" for details.
 *
 * To redistribute this file separately, substitute the full license texts
 * for the above references.
 */
/* Implemention of NewGfx - without gfx */

#ifndef INC_StdNoGfx
#define INC_StdNoGfx

#include "graphics/C4Draw.h"

class CStdNoGfx : public C4Draw
{
public:
	CStdNoGfx();
	virtual bool BeginScene() { return true; }
	virtual void EndScene() { }
	virtual void TaskOut() { }
	virtual void TaskIn() { }
	virtual bool UpdateClipper() { return true; }
	virtual bool OnResolutionChanged(unsigned int, unsigned int) { return true; }
	virtual bool PrepareMaterial(StdMeshMatManager& mat_manager, StdMeshMaterialLoader& loader, StdMeshMaterial& mat);
	virtual bool PrepareRendering(C4Surface *) { return true; }
	virtual bool PrepareSpriteShader(C4Shader& shader, const char* name, int ssc, C4GroupSet* pGroups, const char* const* additionalDefines, const char* const* additionalSlices) { return true; }
	virtual void FillBG(DWORD dwClr=0) { }
	virtual void PerformMesh(StdMeshInstance &, float, float, float, float, DWORD, C4BltTransform* pTransform) { }
	virtual void PerformLine(C4Surface *, float, float, float, float, DWORD, float) { }
	virtual void PerformPix(C4Surface *, float, float, DWORD) { }
	virtual bool RestoreDeviceObjects();
	virtual bool InvalidateDeviceObjects() { return true; }
	virtual bool DeleteDeviceObjects() { return true; }
	virtual bool DeviceReady() { return true; }
	virtual bool SetOutputAdapter(unsigned int) { return true; }

	virtual void PerformMultiPix(C4Surface *, const C4BltVertex *, unsigned int, C4ShaderCall*) {}
	virtual void PerformMultiLines(C4Surface *, const C4BltVertex *, unsigned int, float, C4ShaderCall*) {}
	virtual void PerformMultiTris(C4Surface *, const C4BltVertex *, unsigned int, const C4BltTransform *, C4TexRef *, C4TexRef *, C4TexRef *, DWORD, C4ShaderCall*) {}
};

#endif
