// kedian4.c 如归客栈上房
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"上房"NOR);
	set("long", @TEXT
如归客栈的一间上房。整个房间整洁明亮，东西摆放得整整齐齐。使人住得
舒舒服服，就像在家里住的一样舒适。房子东边墙上开着一个大窗户，窗台下边
是个小桌子。地板上铺着平整的五十公分见方的方砖。
TEXT
	);
	set("exits",([
		"south":__DIR__"kedian1",
		]));
	setup();
	replace_program(ROOM);
}
