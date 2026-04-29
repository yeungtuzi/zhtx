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
        ]));

        set("objects", ([ 
                        "/u/m/masterall/winda" : 1,
                        "/u/m/masterall/banruok" : 1,
                ])
        );

        

        setup();
}  
