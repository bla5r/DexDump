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

#include <string>
#include "ParamParser.h"
#include "FileManager.h"
#include "Logger.h"

static int usage()
{
	Logger::info("Usage: ./dexdiff [DEX FILES...]");
	return (EXIT_SUCCESS);
}

static int error(const std::string &str)
{
	Logger::error(str);
	return (EXIT_FAILURE);
}

int main(int ac, const char *av[])
{
	ParamParser params(ac, av);
	FileManager manager;

	if (!manager.openFiles(params.getFilenames()))
		return (error("File initialisation failed. Exiting..."));
	return (EXIT_SUCCESS);
}