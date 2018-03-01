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

#ifndef	_DEXCODE_H
#define _DEXCODE_H

#include <cstring>
#include <cstdint>
#include "SysEndian.h"

#define DEX_CODE_SIZE sizeof(tDexCode)

struct sDexCode
{
	char registerSize[sizeof(std::uint16_t)];
	char insSize[sizeof(std::uint16_t)];
	char outsSize[sizeof(std::uint16_t)];
	char triesSize[sizeof(std::uint16_t)];
	char debugInfoOff[sizeof(std::uint32_t)];
	char insnsSize[sizeof(std::uint32_t)];
};

typedef struct sDexCode tDexCode;

class DexCode
{
public:
	DexCode();
	~DexCode();

public:
	bool init(const EndianType &, const char *);

private:
	const std::uint32_t _bytesToUint32(const char *) const;
	void _printBytecode(const std::uint32_t &, const char *);

private:
	EndianType _type;
	tDexCode _code;
	char *_bytecode;
};

#endif /* _DEXCODE_H */