//yuedong.c
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short","月洞门");
     set("long",
"月洞门门额上写着"BLU"“琴心”"NOR"两字，以蓝色琉璃砌成，笔致苍劲，\n"
"当是出于秃笔翁的手笔了。\n"
);
     set("exits", ([ /* sizeof() == 2 */
            "north"   : __DIR__"zoulang1",
            "south"   : __DIR__"hall", 
         ]));
     setup();
     replace_program(ROOM);

}