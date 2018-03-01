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

#ifndef	_DEXHEADER_H
#define _DEXHEADER_H

#include <cstring>
#include <string>
#include "SysEndian.h"

#define DEX_HEADER_SIZE sizeof(tDexHeader)

#define DEX_MAGIC "dex\n"
#define DEX_MAGIC_SIZE 8
#define CHECKSUM_SIZE 20

#define ENDIAN_MAGIC "\x78\x56\x34\x12"

/*
 * Extracted struct from:
 *   https://android.googlesource.com/platform/dalvik.git/+/master/libdex/DexFile.h#272
 */

struct sDexHeader
{
	char magic[DEX_MAGIC_SIZE];
	char checksum[sizeof(uint32_t)];
	char signature[CHECKSUM_SIZE];
	char fileSize[sizeof(uint32_t)];
	char headerSize[sizeof(uint32_t)];
	char endianTag[sizeof(uint32_t)];
	char linkSize[sizeof(uint32_t)];
	char linkOff[sizeof(uint32_t)];
	char mapOff[sizeof(uint32_t)];
	char stringIdsSize[sizeof(uint32_t)];
	char stringIdsOff[sizeof(uint32_t)];
	char typeIdsSize[sizeof(uint32_t)];
	char typeIdsOff[sizeof(uint32_t)];
	char protoIdsSize[sizeof(uint32_t)];
	char protoIdsOff[sizeof(uint32_t)];
	char fieldIdsSize[sizeof(uint32_t)];
	char fieldIdsOff[sizeof(uint32_t)];
	char methodIdsSize[sizeof(uint32_t)];
	char methodIdsOff[sizeof(uint32_t)];
	char classDefsSize[sizeof(uint32_t)];
	char classDefsOff[sizeof(uint32_t)];
	char dataSize[sizeof(uint32_t)];
	char dataOff[sizeof(uint32_t)];
};

typedef struct sDexHeader tDexHeader;

class DexHeader
{
public:
	DexHeader();
	~DexHeader();

public:
	bool init(const size_t &, const char *);
	bool isDexFile() const;
	const std::string getType() const;
	const std::string getVersion() const;
	const EndianType getEndian() const;
	const uint32_t getFileSize() const;
	const uint32_t getDataSize() const;
	const uint32_t getHeaderSize() const;
	const uint32_t getClassDefsOff() const;
	const uint32_t getClassDefsSize() const;

private:
	bool _error(const std::string &) const;
	const uint32_t _bytesToUint32(const char *) const;
	const uint16_t _bytesToUint16(const char *) const;

private:
	tDexHeader _header;
};

#endif /* _DEXHEADER_H */