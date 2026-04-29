// Room: /u/p/pock/bj/shngong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"宁寿宫"NOR);
	set("long", @LONG
宁寿宫位于皇宫西北，靠近西铁门，英华殿和保华殿。这里一般是公主
的寝居。各个公主阿哥虽然说是生于皇室，但如果不是长子长女，或皇后妃
子的儿女的话，很难得到皇上宠爱。他们连见母亲或者皇上都要听宣，而不
能随便进出。从这点来说，生在帝王之家，未必是好事，连天伦之乐都享受
不到，真是悲哀。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"westdoor",
		"east" : __DIR__"garden",
		"west" : __DIR__"yihuadian",
		"south" : __DIR__"shanmen",
		]));

	setup();
	replace_program(ROOM);
}
