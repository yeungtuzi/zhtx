// 9whip.c 九节鞭
// written by pock 
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(BBLU HIC"九节"+HIM"鞭"NOR, ({ "nine whip","whip" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄由软铁特别打造的九节鞭，鞭上九节环环相扣，甚是精细。\n");
                set("value", 300);
                set("material", "steel");
                set("wield_msg", RED"$N「唰」的一声一抖手中的$n,把九节鞭抖的笔直，握在手中作为武器。\n"NOR);
                set("unwield_msg", YEL"$N将手中的$n盘起来别在腰际。\n"NOR);
        }
        init_whip(85);
        setup();
}

