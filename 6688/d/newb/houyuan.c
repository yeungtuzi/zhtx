///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是新手村悦来客栈的后院。经常有一些好奇的年轻人从这里开始
进入游戏，往往都是一脸的茫然。不过新手村里的村民大都热情好客，对
刚开始进行游戏的新手也是关怀备至。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west": __DIR__"kefang",
                ]));
                set("valid_startroom", 1);
                set("outdoors", "newbie");
                set("no_fight",1);
                set("objects", ([
                                __DIR__"npc/cunzhang": 1,
                        ]));
        setup();
}



