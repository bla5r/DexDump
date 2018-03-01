/*
 * This file is part of DexDump.
 *
 * Copyright(c) 2018 bla5r
 * https://github.com/bla5r
 *
 * This file may be licensed under the terms of of the
 * GNU General Public License Version 3 (the ``GPL'').
 *
 * Software distributed under the License is distributed
 * on an ``AS IS'' basis, WITHOUT WARRANTY OF ANY KIND, either
 * express or implied. See the GPL for the specific language
 * governing rights and limitations.
 *
 * You should have received a copy of the GPL along with this
 * program. If not, go to http://www.gnu.org/licenses/gpl.html
 * or write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef	_DEXCLASS_H
#define _DEXCLASS_H

#include <string>
#include <cstdint>
#include "DexClassDef.h"
#include "SysEndian.h"

#define DEX_CLASS_SIZE sizeof(tDexClass)

/*
 * Extracted struct from:
 *   https://android.googlesource.com/platform/dalvik.git/+/master/libdex/DexFile.h#360
 */

struct sDexClass
{
	char classIdx[sizeof(uint32_t)];
	char accessFlags[sizeof(uint32_t)];
	char superclassIdx[sizeof(uint32_t)];
	char interfacesOff[sizeof(uint32_t)];
	char sourceFileIdx[sizeof(uint32_t)];
	char annotationsOff[sizeof(uint32_t)];
	char classDataOff[sizeof(uint32_t)];
	char staticValuesOff[sizeof(uint32_t)];
};

typedef struct sDexClass tDexClass;

class DexClass
{
public:
	DexClass();
	~DexClass();

public:
	bool init(const EndianType &, const char *, const char **);
	const uint32_t getClassIdx() const;
	const uint32_t getClassDataOff() const;

private:
	const uint32_t _bytesToUint32(const char *) const;

private:
	EndianType _type;
	tDexClass _class;
	DexClassDef _def;
};

#endif /* _DEXCLASS_H */
