//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"山涧"NOR);
        set("long", @LONG这是一道水流湍急的山涧，要是不懂水性肯定立即就会被呼啸而下的激流冲得无影无踪。
        
LONG
        );
        setup();
}

void init()
{       object ob;
        add_action("do_swim", "swim");
        if( interactive( ob = this_player()))
        {
        remove_call_out("sinking");
        call_out("sinking", 1, ob);
        }
}

int sinking(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision(HIR"$N被迎面而来的激流冲得两眼昏花，一不留神就呛了口水！\n"NOR, ob);
        message_vision(HIR"从上游冲下来一块巨石，险些砸中$N，惊得$N竟然在水中出了一身的冷汗！！\n"NOR, ob);
        damage = random(50)+50;
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
               if(ob->query("kee")< 100){
               message_vision(HIG"$N渐感气力不支，只好听天由命，随着汹涌的激流向下漂去！！\n"NOR, ob);
               ob->unconcious();
               ob->delete_temp("have_jump");
               ob->move("/d/xkd/kouan.c");
               }
        if( environment(ob) == this_object())
        call_out("sinking",random(5)+5, ob);
        }
        else

        return 1;
}


int do_swim(string arg)
{
        object ob=this_player();

        if(!arg || arg=="" )
        {
                tell_object(ob,"你不知道往哪个方向游才好。\n");
                return 1;
        }
       if ( !ob->query_temp("have_jump") )
                  return notify_fail("你从哪里蹦到这里来的，还要不要命了？\n");
       if ( ob->query("force")< 40 )
                  return notify_fail("你的内力不够，还是调息一下内功比较好。\n");
       if ( ob->query("kee")< 100 )
                  return notify_fail("你就这么点气了还在这里玩命，真的不想活了？\n");

        if(arg=="up")
        {
                if(!ob->query_temp("swimming_up")
        || ob->query_temp("swimming_up")<100 )
                {
                ob->add_temp("swimming_up",1);
                ob->add("force",-20);
                ob->receive_damage("kee",50);
                ob->start_busy(random(2));
                tell_object(ob,HIW"你努力地往山溪的上游游去，冰冷的溪水冻得你直打哆嗦，一不留神又呛了几口水。\n"NOR);
                        if(ob->query_skill("force", 1) > 349 && ob->query_skill("force", 1) < 381 ){
                        ob->improve_skill("force", random(ob->query_con())+ 10 );
                        tell_object(ob,HIW"但你默运玄功，全身的真气回转一周天，感觉身上舒服多了。\n\n"NOR);
                        }
                        return 1;
                }
                message_vision(HIY"$N努力的往上游着，突然间发现岸边有个漆黑的山洞，此刻也别无他法，\n不管洞内是否有危险，先找个落脚的地方再说！\n$N扒住了岸边的岩石，吃力地爬到洞口，累得和小猪似的哼嗤哼嗤直喘粗气。\n"NOR,ob);
                ob->delete_temp("swimming_up");
                ob->delete_temp("have_jump");
                ob->set_temp("can_dig",1);
                ob->move("/d/xkd/dong.c");
                        return 1;       
        }
}
