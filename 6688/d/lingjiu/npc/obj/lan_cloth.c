#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( HIW"月白云衫"NOR, ({ "lan cloth","cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件宝衣，女孩子都喜欢的衣服，是「针神」符敏仪特意为梅兰竹菊四姐妹做的。\n");
                set("unit", "件");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/personality", 5);
		set("armor_prop/dodge", 5);
                set("female_only", 1);
        }
        setup();
}
