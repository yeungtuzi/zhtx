// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
        set("short",CYN"虚  空"NOR);
        set("long", @TEXT
       这是最接近天堂的地方——虚空，传说中的武林前辈龙象和不知火舞就已
经抵达了这里，他们当年以几乎近于神的表现战胜了传说中的魔师庞斑和覆雨剑浪
翻云，创造了新一代的武林神话。这里没有力量的体现，没有时空的度量，一切都
在精神和意志中运作，这超乎尘世的气氛使你心旷神怡，只感觉四肢五官六魄脱离
了躯干，融入到这天地一体的虚空中。
TEXT
        );

        set("exits", ([ /* sizeof() == 2 */
          "down": __DIR__"lou9",
          "up": __DIR__"heaven",
        ]));

        set("objects", ([ 
                        "/u/m/masterall/winda" : 1,
                        "/u/m/masterall/banruok" : 1,
                ])
        );
        set("blocks/up","long xiang");

        

        setup();
}  
int valid_leave(object me,string dir)
{
        if(userp(me) && dir=="up")
        {
         if(me->query("combat_exp") < 20000000)
           {

             return notify_fail("仰天弥高，以你目前的能力能够达到这个境界已经不错了。\n");
           }
         if(random(5) < 3)
           {

             return notify_fail("你向上空仰望了许久，仍然留恋着人世间的种种缠绵。\n");
           }
        }
         return 1;
}
