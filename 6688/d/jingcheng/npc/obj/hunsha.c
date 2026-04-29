#include <armor.h>
inherit CLOTH;

void create()
{
       	set_name( "婚纱" , ({ "skirt" }) );
	set("long","新娘子穿的丝织的白色长裙。\n");
       	set_weight(1000);
       	if( clonep() )
               	set_default_object(__FILE__);
       	else {
               	set("unit", "件");
               	set("material", "cloth");
               	set("armor_prop/armor", 1);
        	set("wear_msg", "$N拿出$n披在身上。\n");
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
