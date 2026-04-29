// daocloak.c

#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(HIC"清风"+HIB"道袍"NOR, ({ "taoist surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIC"这是青城派祖传的一件道袍，虽然已经历多年，但仍显得光亮如新，\n"
                        "真不知道是用什么材料做成的。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", this_player()->query_skill("force",1)/20);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/20);
                set("armor_prop/spirituality", this_player()->query_skill("spells",1)/10); 
                set("armor_prop/personality", 5);
        }
        setup();
}

