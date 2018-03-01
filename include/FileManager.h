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

#ifndef	_FILEMANAGER_H
#define _FILEMANAGER_H

#include <vector>
#include <string>
#include "RawFile.h"
#include "DexFile.h"

class FileManager
{
public:
	FileManager();
	~FileManager();

public:
	bool openFiles(const std::vector<std::string> &);
	const std::vector<const DexFile *> &getDexs();

private:
	const RawFile *_openFile(const std::string &);
	const DexFile *_convertToDex(const RawFile *);

private:
	std::vector<const DexFile *> _dex;
};

#endif /* _FILEMANAGER_H */