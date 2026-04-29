// Room: /u/kiss/quanzhen/tianzjt.c
// Made by: kiss
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"天尊"NOR+RED"讲经堂"NOR);
	set("long", @LONG
这是天尊讲经堂，这里的地上整整齐齐的排放着数十个黄布蒲团，
北首有一个红木讲坛，讲坛上放着几本旧惊书。东西边各放着一对美轮美
奂的大花瓶，上插檀香数枝，香烟缭绕，氤氲芬芳，室内一片祥
和之气。看来这里是一个讲经说法的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shuofy.c",
  "north" : __DIR__"jiuxianl.c",
]));
	set("no_clean_up", 0);
create_door("south","木门","north",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
