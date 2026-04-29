// /d/jingcheng/quanlibang/obj/
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"金刚石"NOR, ({"bao shi","stone"}));
        set("level",1);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long",@LONG
钻石恒久远,一颗永流传(level 1)。
LONG
                        );
                set("value",167961600);
        }
        set("weight", 100);
        setup();
}

