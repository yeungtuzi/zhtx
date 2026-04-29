#include <weapon.h>
inherit SPEAR;
void create()
{
        set_name("订作的", ({ "order"}) );
        set_weight(2900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一条铁枪，沉甸甸的。\n");
                set("no_drop",1);
                set("no_get",1);
                set("owner","zh");
                set("rigidity",300);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，耍了一下，然後扛在肩上。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_spear(30);
        setup();
}
void init()
{                  
 	seteuid(geteuid());                  
}                          

int query_autoload()
{
	if( this_player()->query("id") == "zh" )
		return 1;
	return 0;
}
