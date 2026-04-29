// /d/xizang/class/snow_mnt/npc/obj/r-jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"大红尼袍"NOR,({"lama cloth", "cloth", "robe"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "这是喇嘛教女尼穿着的大红尼袍.");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",100);
        }
        setup();
}
