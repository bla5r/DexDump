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

#include "DexClass.h"
#include "Logger.h"

DexClass::DexClass()
{
	this->_type = EndianType::LITTLE;
}

DexClass::~DexClass()
{

}

const uint32_t DexClass::_bytesToUint32(const char *bytes) const
{
	return ((Endian::getUint32Function(this->_type)(bytes)));
}

const uint32_t DexClass::getClassIdx() const
{
	return (this->_bytesToUint32(this->_class.classIdx));
}

const uint32_t DexClass::getClassDataOff() const
{
	return (this->_bytesToUint32(this->_class.classDataOff));
}

bool DexClass::init(const EndianType &type, const char *bytes, const char **actual)
{
	this->_type = type;
	memcpy(&this->_class, *actual, DEX_CLASS_SIZE);
	Logger::info("+-----");
	Logger::info("| Class ID " + std::to_string(this->getClassIdx()));
	Logger::info("+-----");
	if (this->getClassDataOff() != 0)
		this->_def.init(type, bytes, (const char *)bytes + this->getClassDataOff());
	*actual += DEX_CLASS_SIZE;
	return (true);
}