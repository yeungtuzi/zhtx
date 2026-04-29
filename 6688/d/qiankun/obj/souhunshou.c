#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIB"九阴"+HIR"搜魂"+HIW"手"NOR, ({ "souhun shou", "glove" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIB"这是一件碧蓝色的铁手，由精钢铸造而成，每个关节都可以自由活动。\n此物不知饮了多少人的鲜血，通体弥漫着逼人的杀气！"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "steel");
                set("armor_prop/armor", this_player()->query_skill("force",1)/20);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/40);
                set("armor_prop/attack", this_player()->query_skill("sword",1)/80); 
                set("armor_prop/damage", this_player()->query_skill("sword",1)/10);
        }
        setup();
}

