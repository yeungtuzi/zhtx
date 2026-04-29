/**************************************************************************/
// $Id: monkey.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("小猴子", ({ "houzi" , "monkey" }) );

        set("nickname", CYN"活泼可爱"NOR);
//      set("race", "野兽");
        set("age", 0);
        set("long",
                HIR"一只可爱的小猴子\n" NOR
            );
        set("title",HIY "王屋山特产" NOR);
        set("attitude", "peaceful");

        set("combat_exp", 1000000);

        set_skill("dodge",10000);

        setup();


}


