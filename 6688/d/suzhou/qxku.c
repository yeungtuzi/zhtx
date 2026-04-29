// Room: /d/suzhou/qxku.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"器械库"NOR);
	set("long", @LONG
	这儿是放镖局弟子们使用的器械的地方。有竹剑，竹刀。两位趟子手坐
在这儿闲聊。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"lwchang",
	]));

	set("objects", ([
		__DIR__"npc/obj/zhudao" : 1,
		__DIR__"npc/obj/gangdao" : 1,
		__DIR__"npc/fighter3" : 2,
	]));

	setup();
	replace_program(ROOM);
}

