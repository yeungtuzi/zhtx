#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", HIC"隐士居"NOR);
        set ("long", 
@LONG
祥云缭绕，紫气氛氲，一看便非等闲居所。
LONG);
        set("exits", 
        ([
                "j" : "/d/jingcheng/tamgch",
                "west" : "/d/wizard/wizard_room",
                        ]));

        set("valid_startroom", 1);
        set("no_fight", 1);
        replace_program(ROOM);
        setup();
}

