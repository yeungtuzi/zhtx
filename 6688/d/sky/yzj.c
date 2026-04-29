#include <ansi.h>

inherit ROOM;
void create()
{        
        set("short", HIW"云中界"NOR);
        set("long", @LONG
        你周围是淡淡的白云，置身于如此美妙的环境中，钩起了你无尽的遐想。
江湖中的权力、地位、武功、虚名仿佛都不重要，仿佛置身于梦境一般。白云中站
着一位白衫青年，用仙风道骨来形容他一点也不为过，他正在冲着你微笑呢。
LONG);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("pingan",1);
        set("no_beg",1);
        
        set("objects", ([
                        __DIR__"npc/jiliang": 1,
        ]));
        
        setup();
}


