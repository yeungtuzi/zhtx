// /d/xizang/class/gold_wh/npc/obj/pao.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( YEL "黄色喇嘛袍" NOR ,({"lama pao","pao","cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",100);
        }
        setup();
}
