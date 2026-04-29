/**************************************************************************/
// $Id: rabit.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("小兔子", ({ "tuzi" , "rabit" }) );

        set("nickname", CYN"活泼可爱"NOR);
        set("age", 0);
        set("long",
                HIW"好可爱的小兔子\n" NOR
            );
        set("title",HIY "王屋山特产" NOR);
        set("attitude", "peaceful");


        set("combat_exp", 0);



        setup();


}


