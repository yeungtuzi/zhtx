//goldencloth.c
//by masterall

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY"金缕"+HIG"玉"+HIC"衣"NOR, ({ "golden cloth", "cloth" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIY"这件金缕玉衣是由金线混合千年老藤编织而成，然后配以玉器\n"
                        "做为装饰，实在是武林中的一件至宝，它辗转多年，终为司空晓风所得。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "gold");
                set("armor_prop/armor", this_player()->query_skill("force",1)/4);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/8);
                set("armor_prop/attack", this_player()->query_skill("sword",1)/60);
                set("armor_prop/personality", 15);
        }
        setup();
}

