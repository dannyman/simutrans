#ifndef _PAKSET_INFO_H
#define _PAKSET_INFO_H

#include "../tpl/stringhashtable_tpl.h"
#include "../utils/checksum.h"
#include <string>


class pakset_info_t
{
	/**
	 * checksums of all besch's
	 * since their names are unique we can index them by name
	 */
	static stringhashtable_tpl<checksum_t*> info;

	/**
	 * pakset checksum
	 */
	static checksum_t general;

public:

	static void calculate_checksum();
	static checksum_t* get_checksum() { return &general; }

	static void append(const char* name, checksum_t *chk);

	static void debug();
};

#endif