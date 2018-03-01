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

#include "DexHeader.h"
#include "Logger.h"

DexHeader::DexHeader()
{
	memset(&this->_header, 0, DEX_HEADER_SIZE);
}

DexHeader::~DexHeader()
{

}

bool DexHeader::_error(const std::string &str) const
{
	Logger::error(str);
	return (false);
}

bool DexHeader::isDexFile() const
{
	return (strncmp(this->_header.magic, DEX_MAGIC, 4) == 0 ? true : false);
}

const uint32_t DexHeader::_bytesToUint32(const char *bytes) const
{
	return ((Endian::getUint32Function(this->getEndian()))(bytes));
}

const uint16_t DexHeader::_bytesToUint16(const char *bytes) const
{
	return ((Endian::getUint16Function(this->getEndian()))(bytes));
}

const std::string DexHeader::getType() const
{
	return (this->isDexFile() ? "DEX" : "Unknown");
}

const std::string DexHeader::getVersion() const
{
	return (std::string(this->_header.magic + 4));
}

const EndianType DexHeader::getEndian() const
{
	return (strncmp(this->_header.endianTag, ENDIAN_MAGIC, 4) == 0 ? EndianType::LITTLE : EndianType::BIG);
}

const uint32_t DexHeader::getFileSize() const
{
	return (this->_bytesToUint32(this->_header.fileSize));
}

const uint32_t DexHeader::getDataSize() const
{
	return (this->_bytesToUint32(this->_header.dataSize));
}

const uint32_t DexHeader::getHeaderSize() const
{
	return (this->_bytesToUint32(this->_header.headerSize));
}

const uint32_t DexHeader::getClassDefsSize() const
{
	return (this->_bytesToUint32(this->_header.classDefsSize));
}

const uint32_t DexHeader::getClassDefsOff() const
{
	return (this->_bytesToUint32(this->_header.classDefsOff));
}

bool DexHeader::init(const size_t &size, const char *bytes)
{
	if (size < DEX_HEADER_SIZE)
		return (this->_error("This file is too small to be a DEX file."));
	memcpy(&this->_header, bytes, DEX_HEADER_SIZE);
	if (size != this->getFileSize())
		return (this->_error("File sizes mismatch."));
	if (DEX_HEADER_SIZE != this->getHeaderSize())
		return (this->_error("Header sizes mismatch."));
	return (this->isDexFile());
}