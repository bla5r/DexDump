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

#ifndef	_DEXCLASSDEF_H
#define _DEXCLASSDEF_H

#include <vector>
#include "DexCode.h"
#include "SysEndian.h"
#include "Leb128.h"

struct sDexEncodedField
{
	uint32_t fieldIdx;
	uint32_t accessFlags;
};

typedef struct sDexEncodedField tDexEncodedField;

struct sDexEncodedMethod
{
	uint32_t methodIdx;
	uint32_t accessFlags;
	uint32_t codeOff;
	DexCode code;
};

typedef struct sDexEncodedMethod tDexEncodedMethod;

struct sDexClassDef
{
	uint32_t staticFieldsSize;
	uint32_t instanceFieldsSize;
	uint32_t directMethodsSize;
	uint32_t virtualMethodsSize;
};

typedef struct sDexClassDef tDexClassDef;

class DexClassDef
{
public:
	DexClassDef();
	~DexClassDef();

public:
	bool init(const EndianType &, const char *, const char *);

private:
	const uint32_t _bytesToUint32(const char *) const;
	const uint16_t _bytesToUint16(const char *) const;
	void _getFields(const uint32_t &, const char **, std::vector<const tDexEncodedField *> &);
	void _getMethods(const uint32_t &, const char *, const char **, std::vector<const tDexEncodedMethod *> &);

private:
	EndianType _type;
	tDexClassDef _def;
	std::vector<const tDexEncodedField *> _staticFields;
	std::vector<const tDexEncodedField *> _instanceFields;
	std::vector<const tDexEncodedMethod *> _directMethods;
	std::vector<const tDexEncodedMethod *> _virtualMethods;
};

#endif /* _DEXCLASSDEF_H */
