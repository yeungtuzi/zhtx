#include <armor.h>
#include <ansi.h>

inherit SHIELD;
inherit F_UNIQUE;

void create()
{
        set_name(BLK"地煞"+HIR"修罗"+HIB"盾"NOR, ({ "demon shield", "shield" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        BLK"这是一面鬼森森的大盾，上面刻着一幅食人魔的图案，让人看了不寒而栗。\n据说此盾过于邪恶，被达摩老祖封于泰山之上，想不到竟落入乾坤教的手中。"NOR);
                set("unit", "面");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
//                set("unpawnable",1);
                set("value", 100000);
                set("material", "steel");
                set("armor_prop/armor", this_player()->query_skill("force",1)/16);
                set("armor_prop/armor_vs_force", this_player()->query_skill("force",1)/20);
                set("armor_prop/attack", this_player()->query_skill("sword",1)/80); 
                set("armor_prop/damage", this_player()->query_skill("sword",1)/20);
                set("armor_prop/personality", -5);
        }
        setup();
}

