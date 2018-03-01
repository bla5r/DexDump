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

#include <fstream>
#include "FileManager.h"
#include "Logger.h"

FileManager::FileManager()
{

}

FileManager::~FileManager()
{
	std::vector<const DexFile *>::const_iterator ite;

	for (ite = this->_dex.begin(); ite != this->_dex.end(); ite++)
		delete *ite;
}

const RawFile *FileManager::_openFile(const std::string &filename)
{
	char *buffer = NULL;
	RawFile *res = NULL;
	std::streampos size;
	std::ifstream file(filename, std::ios::in|std::ios::binary|std::ios::ate);

	if (file.is_open())
	{
		size = file.tellg();
		buffer = new char[size];
		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();
		res = new RawFile(filename, size, buffer);
		Logger::success("File successfully opened: " + filename);
	}
	else
		Logger::error("Unable to open the file: " + filename);
	return (res);
}

bool FileManager::openFiles(const std::vector<std::string> &filenames)
{
	std::vector<std::string>::const_iterator ite;
	const RawFile *file;
	const DexFile *dex;

	for (ite = filenames.begin(); ite != filenames.end(); ite++)
	{
		if ((file = this->_openFile(*ite)) != NULL)
		{
			if ((dex = this->_convertToDex(file)) != NULL)
				this->_dex.push_back(dex);
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

const std::vector<const DexFile *> &FileManager::getDexs()
{
	return (this->_dex);
}

const DexFile *FileManager::_convertToDex(const RawFile *file)
{
	const char *buffer;
	DexFile *dex;

	if (file == NULL)
		return (NULL);
	dex = new DexFile;
	if (!dex->init(file->getSize(), file->getBytes()))
	{
		delete dex;
		delete file;
		return (NULL);
	}
	delete file;
	return (dex);
}
