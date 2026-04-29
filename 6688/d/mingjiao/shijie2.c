#include <room.h>

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
	宽阔整齐的白玉石阶，一条猩红的地毯自阶底笔直地铺向远处，
两旁武士肃然直立。尽头处又是十数级石阶。
LONG
        );
        set("exits", ([ 
  		"northup" : __DIR__"shijie3",
  		"southdown" : __DIR__"shijie1",
	]));
        
	set("objects",([
			__DIR__"npc/mjjiaozhong":2,
	]));

        setup();
}

