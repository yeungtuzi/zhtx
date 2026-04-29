//yufengzhen.c
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
inherit F_UNIQUE;

void create()
{
        set_name(GRN"玉蜂针"NOR, ({ "yufeng zhen", "zhen"}));
       
        if (clonep())
                set_default_object(__FILE__);
        else {
           
                set("long", "这是一把非常细的银针，里面夹着少许黄金。\n");
            	set("base_value",1);
                set("base_unit", "把");
                set("unit", "把");
             	set("base_weight",1);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放入口袋中。\n");
                set("no_decrease",1);
        }
        init_throwing(99); 
   	set_amount(1);             
        set("poison/type","bee_poison");
        set("poison/amount",20000);   	
   	set("no_decrease",1);
    	setup();
}