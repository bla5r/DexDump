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

#ifndef _SYSENDIAN_H_
#define _SYSENDIAN_H_

#include <cstdint>

enum EndianType
{
	LITTLE,
	BIG
};

typedef uint32_t (*uint32Func)(const char *);
typedef uint16_t (*uint16Func)(const char *);

class Endian
{
public:
	static uint32_t readUint32LittleEndian(const char *);
	static uint32_t readUint32BigEndian(const char *);
	static uint16_t readUint16LittleEndian(const char *);
	static uint16_t readUint16BigEndian(const char *);
	static const uint32Func getUint32Function(const EndianType &);
	static const uint16Func getUint16Function(const EndianType &);
};

#endif /* _SYSENDIAN_H */