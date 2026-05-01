// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

//inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        if( me->is_fighting() ) return notify_fail("你正在战斗中！\n");
        
        if( (int)me->query("mana") < 90 ) return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 10 ) return notify_fail("你的精神不够集中！\n");
        if( sheet->name() != "桃符纸" )
                return notify_fail("阴界传送符要画在桃符纸上！\n");

        if( sheet->query_amount() < 1 ) 
                return notify_fail("你没有桃符纸了！\n");
        sheet->set_amount((int)sheet->query_amount() - 1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic/magic_seal");
        newsheet->set_name(YEL "阴界传送符" NOR, ({ "earth-warp sheet", "sheet"}) );      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp" :) );
        newsheet->move(me);
        message_vision("$N写了一道阴界传送符。\n" NOR, me);
        me->add("mana", -90);
        me->receive_damage("sen", 10);

        return 1;
}

int do_warp()
{
        object env;

if( this_player()->is_busy() )
                return notify_fail("你正忙着哪。\n");

if( this_player()->is_fighting() )
                  return notify_fail("战斗中还有空用这些古怪玩意？！\n");
//      if( who && who!=this_player() )
//              return notify_fail("阴界传送符只能对自己使用。\n");

        env = environment(this_player());
        message("vision",
                HIB + this_player()->name() + "祭起一张阴界传送符。\n\n"
                "忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n\n"
                "然後一阵火光突然爆起！\n" NOR, env);
        DROP_CMD->main(this_player(), "all");
        this_player()->move(DEATH_ROOM);
        message("vision",
                CYN "可是...." + this_player()->name() + "已经不见了。\n" NOR, env);
        message("vision",
                CYN "你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n\n"
                NOR     "不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n\n"
                        "却不一样了....\n", this_player() );
        
        return 1;
}

