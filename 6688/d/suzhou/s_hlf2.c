// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"葫芦庙客房");
	set("long", @LONG
	这间房间还算干净，房间中除了一张床外，居然还有个书架，上面放满了书，一位儒生
模样的年轻人正捧着书，来回走动着，一边还诵着书。
LONG
);

	set("exits",([
	"east" : __DIR__"s_hlt",
	]));
	
	set("objects",([
	__DIR__"npc/s_jyc" : 1,
	]));

	setup();
	replace_program(ROOM);
}
