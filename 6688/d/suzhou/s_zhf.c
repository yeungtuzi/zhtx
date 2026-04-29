// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"后房"NOR);
	set("long", @LONG
	房间中有个衣着还算华丽的中年妇人，还有一个年轻的丫头。两人正
认真地做着女红。
LONG
);
	set("exits",([
	"north" : __DIR__"s_zht",
	"west" : __DIR__"s_zhf2",
	]));

	set("objects",([
	__DIR__"npc/s_zfren" : 1,
	__DIR__"npc/s_npu" : 1,
	]));

	setup();
	replace_program(ROOM);
}
