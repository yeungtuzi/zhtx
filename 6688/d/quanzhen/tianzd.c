// Room: /u/hacky/quanzhen/tianzd.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"天尊殿"NOR);
	set("long", @LONG
    这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不
少白须白眉的老道长们正端坐在图谱画轴之前，似乎在苦苦思索。
南北山墙是高及屋顶的大书架，走近细看，它们是各种各样的道
家心法，屋正中摆着几张矮几诃和几个团，几位老道长正在入定中。
南边是重虚堂，西边是门楼。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zoulang10.c",
  "south" : __DIR__"chongxt.c",
  "west" : __DIR__"menlou.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiu.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
