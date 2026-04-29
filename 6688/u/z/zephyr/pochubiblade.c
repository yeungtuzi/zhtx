// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name( YEL "破成两片的出跸刀" NOR, ({ "po chubi dao", "po dao", "dao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",YEL@LONG
这是一柄黄杨木雕的弯刀，无鞘，刀身长三尺半，上面雕有美人出跸图，
图上人物凡143，马匹109，车辆16，云麾、车盖、仪仗等均历历可数，
据说这些东西如果放为原大，那就要前后排上十来里长，如果化成图画，
裱上手卷，也得绵延十数丈。画与雕刻都出自名家，形态逼真，神情生动。

但是这柄价值连城的名刀已经被从中间劈成了两半，已经没有任何攻击力了。
LONG NOR
         );
                set("unpawnable",1);
                set("value", 0);
                set("material", "wood");
                set("weapon_prop", 0);
        }

setup();
}

