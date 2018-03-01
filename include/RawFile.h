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

#ifndef	_RAWFILE_H
#define _RAWFILE_H

#include <cstdint>
#include <string>

class RawFile
{
public:
	RawFile(const std::string &, const size_t, const char *);
	~RawFile();

public:
	const std::string &getFilename() const;
	const size_t &getSize() const;
	const char *getBytes() const;

private:
	const std::string _filename;
	const size_t _size;
	const char *_bytes;
};

#endif /* _RAWFILE_H */