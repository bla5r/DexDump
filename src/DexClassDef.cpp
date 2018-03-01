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

#include "DexClassDef.h"
#include "Logger.h"

DexClassDef::DexClassDef()
{
	this->_type = EndianType::LITTLE;
}

DexClassDef::~DexClassDef()
{
	std::vector<const tDexEncodedField *>::const_iterator iteField;
	std::vector<const tDexEncodedMethod *>::const_iterator iteMethod;

	for (iteField = this->_staticFields.begin(); iteField != this->_staticFields.end(); iteField++)
		delete *iteField;
	for (iteField = this->_instanceFields.begin(); iteField != this->_instanceFields.end(); iteField++)
		delete *iteField;
	for (iteMethod = this->_directMethods.begin(); iteMethod != this->_directMethods.end(); iteMethod++)
		delete *iteMethod;
	for (iteMethod = this->_virtualMethods.begin(); iteMethod != this->_virtualMethods.end(); iteMethod++)
		delete *iteMethod;
}

const uint32_t DexClassDef::_bytesToUint32(const char *bytes) const
{
	return ((Endian::getUint32Function(this->_type)(bytes)));
}

const uint16_t DexClassDef::_bytesToUint16(const char *bytes) const
{
	return ((Endian::getUint16Function(this->_type)(bytes)));
}

void DexClassDef::_getFields(const uint32_t &size, const char **ptr, std::vector<const tDexEncodedField *> &vector)
{
	uint32_t i = 0;
	tDexEncodedField *field;

	while (i < size)
	{
		field = new tDexEncodedField;
		field->fieldIdx = Leb128::readULeb128(ptr);
		field->accessFlags = Leb128::readULeb128(ptr);
		Logger::info(" -> Field ID: " + std::to_string(field->fieldIdx));
		vector.push_back(field);
		i++;
	}
}

void DexClassDef::_getMethods(const uint32_t &size, const char *bytes, const char **ptr, std::vector<const tDexEncodedMethod *> &vector)
{
	uint32_t i = 0;
	tDexEncodedMethod *method;

	while (i < size)
	{
		method = new tDexEncodedMethod;
		method->methodIdx = Leb128::readULeb128(ptr);
		method->accessFlags = Leb128::readULeb128(ptr);
		method->codeOff = Leb128::readULeb128(ptr);
		Logger::info(" -> Method ID: " + std::to_string(method->methodIdx));
		if (method->codeOff != 0)
			method->code.init(this->_type, (const char *)bytes + method->codeOff);
		vector.push_back(method);
		i++;
	}
}

bool DexClassDef::init(const EndianType &type, const char *bytes, const char *actual)
{
	const char **ptr = &actual;

	this->_type = type;
	this->_def.staticFieldsSize = Leb128::readULeb128(ptr);
	this->_def.instanceFieldsSize = Leb128::readULeb128(ptr);
	this->_def.directMethodsSize = Leb128::readULeb128(ptr);
	this->_def.virtualMethodsSize = Leb128::readULeb128(ptr);
	this->_getFields(this->_def.staticFieldsSize, ptr, this->_staticFields);
	this->_getFields(this->_def.instanceFieldsSize, ptr, this->_instanceFields);
	this->_getMethods(this->_def.directMethodsSize, bytes, ptr, this->_directMethods);
	this->_getMethods(this->_def.virtualMethodsSize, bytes, ptr, this->_virtualMethods);
	return (true);
}
