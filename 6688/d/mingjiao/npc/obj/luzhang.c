#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIC "鹿杖" NOR, ({ "deer staff","staff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
	"一根短杖，杖头分叉，作鹿角之形，通体黝黑， 不知是何物铸成，。\n");
                set("value", 8000);
                set("material", "steel");
                set("wield_msg", "$N拿出一根似金非金，似石非石的$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
		//set("weapon_prop/astral_vision", 1);
        }
        init_staff(80);
	setup();
}
