#include <ansi.h>

inherit ROOM;
void create()
{        
        set("short", HIW"云中"NOR);
        set("long", @LONG
        你周围是淡淡的白云，置身于如此美妙的环境中，钩起了你无尽的遐想。
江湖中的权力、地位、武功、虚名仿佛都不重要，仿佛置身于梦境一般。
LONG);
         set("no_kill",1);
         set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1);

        setup();
}


