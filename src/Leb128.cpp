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

#include "Leb128.h"

/*
 * Extracted function from:
 *   https://android.googlesource.com/platform/dalvik.git/+/master/dx/src/com/android/dex/Leb128.java#82
 */

uint32_t Leb128::readULeb128(const char **bytes)
{
	uint32_t result = 0;
	uint32_t cur = 0;
	uint32_t count = 0;
	const char *ptr = *bytes;

	do
	{
		cur = (ptr[count] & 0xFF);
		result |= (cur & 0x7f) << (count * 7);
		count++;
	} while (((cur & 0x80) == 0x80) && count < 5);
	*bytes = ptr + count;
	return (result);
}

/*
 * Extracted function from:
 *   https://android.googlesource.com/platform/dalvik.git/+/master/dx/src/com/android/dex/Leb128.java#54
 */

int32_t Leb128::readSLeb128(const char **bytes)
{
	int32_t result = 0;
	int32_t cur;
	int32_t count = 0;
	int32_t signBits = -1;
	const char *ptr = *bytes;

	do
	{
		cur = ptr[count] & 0xff;
		result |= (cur & 0x7f) << (count * 7);
		signBits <<= 7;
		count++;
	} while (((cur & 0x80) == 0x80) && count < 5);
	if (((signBits >> 1) & result) != 0)
		result |= signBits;
	*bytes = ptr + count;
	return (result);
}
