#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIY "新闻中心" NOR);
        set("long", @LONG
    这里是纵横天下的新闻中心，有什么新闻都可以在这里发布(post)，
系统自动随机通知所有在线玩家。
LONG );
        set("exits", ([
           "south" : "/d/wizard/wizard_room",
        ]));

        set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}

