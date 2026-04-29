#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(HIB"水蓝碎花长裙"NOR, ({"blue skirt", "skirt"}) );
    set_weight(1000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
 	set("long", "水蓝色的长裙，穿起来一定很漂亮。\n");
        set("material", "cloth");
        set("armor_prop/armor", 10);
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
