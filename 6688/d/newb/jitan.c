
#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "祭坛");
        set("long", @LONG
这里是纵横天下新手村的祭坛，周围满是肃穆庄严的佛像，天青色
的石碑清楚的刻着几个大字：纵横天下，快意恩仇。石碑旁正有一
顽童在玩耍，祭坛周围是一偏旷野，没有什么出路。
LONG
        );

        set("no_fight",1);
        set("objects", ([
                        __DIR__"npc/boy": 1,
                ]));
        setup();
}



