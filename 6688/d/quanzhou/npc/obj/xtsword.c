// Weapon: /d/new_taohua/obj/skysword.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
     set_name( HIG "玄铁剑" NOR, ({ "sword" }) );
 set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把黑黝黝的钝剑, 重量惊人\n"
);
   set("value", 100000);
   set("replica_ob", "/obj/weapon/sword.c");
   set("material", "steel");
   set("unpawnable",1);
   set("rigidity", 100000);
   set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

   init_sword(110);
   setup();
}
