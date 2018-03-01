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

#include "ParamParser.h"

ParamParser::ParamParser(int ac, const char *av[])
{
	int i = 1;

	while (i < ac)
	{
		this->_filenames.push_back(std::string(av[i]));
		i++;
	}
}

ParamParser::~ParamParser()
{

}

const std::vector<std::string> &ParamParser::getFilenames() const
{
	return (this->_filenames);
}