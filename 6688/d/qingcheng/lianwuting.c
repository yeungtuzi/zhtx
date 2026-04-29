// Room: /open/hihi/banshichu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"练武厅"NOR);
	set("long", @LONG
这里是镖局的练武厅，厅的东面有一排兵器架，架上放着各种各样的兵器，以供
镖师平时练武之用。这里地方宽敞，的确是一个切磋武艺的好地方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"banshichu",
		]));
	set("objects", ([ /* sizeof() == 1 */
     __DIR__"npc/biaoshi1" : 1,
		  __DIR__"npc/biaoshi2" : 2,
     __DIR__"npc/biaoshi3" : 3,
		  __DIR__"npc/dizi" : 4,
		  __DIR__"obj/shisuo":1,
		]));
	setup();
	replace_program(ROOM);
}
