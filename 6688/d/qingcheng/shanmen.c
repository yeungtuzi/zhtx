// Room: /open/hihi/shanmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"青城山门"NOR);
	set("long", @LONG
原来崎岖的山路到了此处忽然一平，眼前豁然开朗。青城派选了此处作为
门派的山门，的确是选了一个好地方。放眼北面，一路山路蜿蜒延伸而来，而
那小桥流水，田野的阡陌交通，还有远方小镇的房屋林立，皆尽收眼底.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"jianchi",
          "northdown":__DIR__"shanlu2",
	]));
        set("objects",([
           __DIR__"npc/renxiong":1,
           ]));
	setup();
	replace_program(ROOM);
}
