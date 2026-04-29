#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(CYN"轻罗绸衫"NOR, ({ "bluepink cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这件浅蓝色的绸衫上面绣著几朵勿忘我，闻起来还有一股淡香。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}
 