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

#include "DexFile.h"
#include "Logger.h"

DexFile::DexFile()
{

}

DexFile::~DexFile()
{

}

bool DexFile::_error(const std::string &str) const
{
	Logger::error(str);
	return (false);
}

bool DexFile::init(const size_t &size, const char *bytes)
{
	if (!this->_header.init(size, bytes))
		return (false);
	Logger::info("Type: " + this->_header.getType() + " - Version: " + this->_header.getVersion());
	this->_classes.init(this->_header.getEndian(), this->_header.getClassDefsSize(), bytes, this->_header.getClassDefsOff());
	return (true);
}
