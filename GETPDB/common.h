#pragma once

#define USER_SHARED_DATA ((PKUSER_SHARED_DATA)0x7ffe0000)

enum {
	e_List = WM_USER + 0x100, e_ip, e_init, e_name, e_connect, e_send, e_pdbcreate, e_length, e_recv, e_disconnect, e_unpack, e_stop, e_packet, e_text
};

struct CNT_MODULE_INFORMATION {
	USHORT LoadCount;
	CHAR FullPathName[];
};
