// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name( BLU "刈鹿刀" NOR, ({ "yilu dao", "dao", "blade" }) );
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", CYN"一把暗兰色的刀。刀身宽，上雕有花纹，雕工异常精致。\n"NOR);
                set("unpawnable",1);
                set("value", 0);
                set("material", "bloodsteel");
                set("wield_msg", "$N抽出$n握在手中，一阵无边的杀气弥散开来。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/attack", 50);
                set("weapon_prop/defense",50);
        }

        init_blade(200);
        setup();
}

