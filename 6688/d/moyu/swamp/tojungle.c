// swamp1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/dyna_room.c";
void create()
{
	set("short", "森林边");
	set("long", @LONG
你苦苦走了二里有余，突然前方现出一颗大星，在天边闪闪发光。凝神望去，
想要辨别方向，看出原来并非天星，而是一盏灯火。既有灯火，必有人家。
你好不欣喜，加快脚步，笔直向着灯火赶去，急行里许，但见黑森森的四下
里都是树木，原来灯火出自林中。
LONG );
	set("exits",   ([
		"east":__DIR__"jungle/jungle1"
		]));

	set("objects", ([
		__DIR__"npc/black_wushi": 2+random(2),
		"/d/moyu/npc/bloodboss": 1,
		]));
	set("blocks",  ([
		"east":"blood boss",
		]));
	setup();
}