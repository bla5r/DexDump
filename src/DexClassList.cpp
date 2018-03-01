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

#include "DexClassList.h"
#include "Logger.h"

DexClassList::DexClassList()
{

}

DexClassList::~DexClassList()
{
	std::vector<const DexClass *>::const_iterator ite;

	for (ite = this->_classes.begin(); ite != this->_classes.end(); ite++)
		delete *ite;
}

bool DexClassList::init(const EndianType &type, const uint32_t &size, const char *bytes, const uint32_t &offset)
{
	uint32_t i = 0;
	DexClass *elem = NULL;
	const char *ptr = (const char *)bytes + offset;
	const char **actual = &ptr;

	Logger::info("Number of classes: " + std::to_string(size));
	while (i < size)
	{
		elem = new DexClass();
		elem->init(type, bytes, actual);
		this->_classes.push_back(elem);
		i++;
	}
	return (true);
}