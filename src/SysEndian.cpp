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

#include "SysEndian.h"

uint32_t Endian::readUint32LittleEndian(const char *bytes)
{
	uint32_t res = 0;
	uint8_t i = 3;

	while (i > 0)
	{
		res |= (bytes[i--] & 0xFF);
		res <<= 8;
	}
	res |= (bytes[i] & 0xFF);
	return (res);
}

uint32_t Endian::readUint32BigEndian(const char *bytes)
{
	uint32_t res = 0;
	uint8_t i = 0;

	while (i < 3)
	{
		res |= (bytes[i++] & 0xFF);
		res <<=  8;
	}
	res |= (bytes[i] & 0xFF);
	return (res);
}

uint16_t Endian::readUint16LittleEndian(const char *bytes)
{
	uint16_t res = 0;

	res |= (bytes[1] & 0xFF);
	res <<= 8;
	res |= (bytes[0] & 0xFF);
	return (res);
}

uint16_t Endian::readUint16BigEndian(const char *bytes)
{
	uint16_t res = 0;

	res |= (bytes[0] & 0xFF);
	res <<= 8;
	res |= (bytes[1] & 0xFF);
	return (res);
}

const uint32Func Endian::getUint32Function(const EndianType &type)
{
	return (type == EndianType::LITTLE ? &(Endian::readUint32LittleEndian) : &(Endian::readUint32BigEndian));
}

const uint16Func Endian::getUint16Function(const EndianType &type)
{
	return (type == EndianType::LITTLE ? &(Endian::readUint16LittleEndian) : &(Endian::readUint16BigEndian));	
}