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

#include "DexCode.h"
#include "Logger.h"

DexCode::DexCode()
{
	this->_type = EndianType::LITTLE;
	this->_bytecode = NULL;
}

DexCode::~DexCode()
{
	if (this->_bytecode != NULL)
		delete [] this->_bytecode;
}

const std::uint32_t DexCode::_bytesToUint32(const char *bytes) const
{
	return ((Endian::getUint32Function(this->_type)(bytes)));
}

void DexCode::_printBytecode(const std::uint32_t &size, const char *bytecode)
{
	std::uint32_t i = 0;

	Logger::info("\tDalvik bytecodes:");
	printf("\t");
	while (i < size)
	{
		printf("%02x ", bytecode[i]);
		i++;
	}
	printf("\n");
}

bool DexCode::init(const EndianType &type, const char *bytes)
{
	const char *bytecode = (const char *)bytes + DEX_CODE_SIZE;
	std::uint32_t bytecodeSize = 0;

	this->_type = type;
	memcpy(&this->_code, bytes, DEX_CODE_SIZE);
	bytecodeSize = this->_bytesToUint32(this->_code.insnsSize) * sizeof(std::uint16_t);
	this->_bytecode = new char[bytecodeSize];
	memcpy(this->_bytecode, bytecode, bytecodeSize);
	this->_printBytecode(bytecodeSize, this->_bytecode);
	return (true);
}
