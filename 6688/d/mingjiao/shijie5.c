#include <room.h>

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
	宽阔整齐的白玉石阶，一条猩红的地毯自阶底笔直地铺向远处，
两旁武士肃然直立。尽头处是一座极其宏伟的大殿。
LONG
        );
        set("exits", ([ 
  		"northup" : __DIR__"yanwuchang",
  		"southdown" : __DIR__"shijie4",
	]));
        
	set("objects",([
			__DIR__"npc/mjjiaozhong":2,
	]));

        setup();
}

