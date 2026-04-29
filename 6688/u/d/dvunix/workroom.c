#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "巫师工作站");
        set("long", @LONG
这里就是巫师天山有雪(Dvunix)的工作站。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west": "/d/wizard/wizard_room",
                ]));
        setup();
}

