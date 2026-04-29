#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
       set_name( CYN"流影裙"NOR , ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
               set("value", 700);
                set("material", "cloth");
                set("armor_prop/armor",10);
		set("armor_prop/dodge",10);
        set("wear_msg", "$N将$n拿出穿在身上。\n");
        }
        setup();
}
int wear()
{
     if ((string)this_player()->query("gender") !="女性")
           return notify_fail("只有女生才可穿哦!你变态呀! \n");
     else {
           ::wear();
          }
     return 1;

}
