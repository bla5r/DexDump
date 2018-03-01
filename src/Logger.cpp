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

#include "Logger.h"

void Logger::success(const std::string &str)
{
	std::cout << "[+] " << str << std::endl;
}

void Logger::info(const std::string &str)
{
	std::cout << "[i] " << str << std::endl;
}

void Logger::warning(const std::string &str)
{
	std::cout << "[!] " << str << std::endl;
}

void Logger::error(const std::string &str)
{
	std::cout << "[-] " << str << std::endl;
}