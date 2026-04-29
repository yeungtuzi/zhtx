// donglang.c 东厢走廊
// by Masterall
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "东厢走廊");
        set("long", @LONG
    你走在一条走廊上，东边有几间雅室，人来人往很热闹。西边是正门。东边是乾坤
教休息室。
LONG
        );
 
set("exits", ([
                "east" : __DIR__"bedroom",
                "west" : __DIR__"gate",
        ]));
        
setup();
replace_program(ROOM); 
}
 


