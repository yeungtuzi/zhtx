inherit NPC;
#include <ansi.h>

int give_flybag();
int give_gift();
int back_gift();


void create()
{
        set_name("姬良", ({"ji liang"}));
        set("long","一位白衫青年，仙风道骨，仪表不凡。\n");
        set("gender", "男性");
        set("title",YEL"新人导师"NOR);
        set("age", 22);
        set("per", 40);
        set("inquiry", ([
                           "飞行包":(:give_flybag:),
                           "礼物":(:give_gift:),
                           "gift":(:give_gift:),
                           "失去的记忆":(:back_gift:),
                        ]));
        setup();
}

int give_flybag()
{
        object me=this_player();
        object ob=this_object();
        object obj;
        
        if (me->query_temp("newbie_flybag")=="got" )
        {
               command("say 你不是刚刚要了飞行包了吗？！");
                        return 1;
        }
        
        
        message_vision("$N说道：拿好。\n",ob);
        message_vision("$N给了$n一个飞行包。\n",ob,me);
        
        obj = new("/d/sky/obj/flybag.c");
        obj->move(me);
        
        me->set_temp("newbie_flybag","got");
        return 1;
}

int back_gift()
{
        object me=this_player();

        if ( !me->query("have_resetgift") )
        {
               command("say 你好像没有重新脱胎换骨分配天赋吧？！");
                        return 1;
        }

        if ( me->query("had_resetgift") )
        {
               command("say 你不是已经脱胎换骨了吗？还来问什么！");
                        return 1;
        }
        
        tell_object(me,HIY"姬良微笑着看了你一眼，“你真的失落了什么东西吗？让就让我用上苍的力量为你找回吧！”\n随即冲你轻轻一点，一道神光立即笼罩了你，不多久你的容颜似乎又重新焕发了光彩。\n"NOR);

        me->set("kar",me->query("kar_bak"));
        me->delete("kar_bak");

        me->set("per",me->query("per_bak"));
        me->delete("per_bak");

        me->set("fav",me->query("fav_bak"));
        me->delete("fav_bak");

        me->set("elo",me->query("elo_bak"));
        me->delete("elo_bak");

        me->set("spi",me->query("spi_bak"));
        me->delete("spi_bak");

        me->set("msc",me->query("msc_bak"));
        me->delete("msc_bak");

        me->set("wil",me->query("wil_bak"));
        me->delete("wil_bak");

        me->set("vis",me->query("vis_bak"));
        me->delete("vis_bak");
        
        me->delete("have_resetgift");
        me->set("had_resetgift",1);
        return 1;
}

int give_gift()
{
        object me=this_player();
        object ob=this_object();
        object obj;
        
        if (me->query("newbie_giftgot"))
        {
               command("say 新手礼物只能领一个,不要贪得无厌哦！！");
                        return 1;
        }
        if (me->query("combat_exp") > 500000)
        {
               command("say 新手礼物不发给老妖精！！");
                        return 1;
        }
        if (me->query("dummy") )
        {
               command("say 你都给人做dummy了，还是省省吧！");
        }
        if (me->query("combat_exp") < 49999)
        {
               command("say 大米我是不发礼物的，乖乖靠边站吧！！");
                        return 1;
        }
        if (me->query_skill("force", 1) < 100)
        {
               command("say 你还没去少林寺磕头吧，赶紧把内功心法磕头磕到100就可以来领礼物了！！");
               command("say 记得磕完头之前千万不要拜师哦，小心命丧少林僧兵之手！");
                        return 1;
          }
        
        message_vision(HIC"$N说道：“拿好，不要让坏人抢去了。”\n"NOR,ob);
        message_vision(YEL"$N给了$n一个包装精美的礼盒。\n"NOR,ob,me);
        
        obj = new("/u/m/masterall/obj/giftbox.c");
        obj->move(me);
        obj->set("owner", me);
        
        me->set("newbie_giftgot",1);
        return 1;
}


void die()
{
        object ob;
        if( objectp(ob = query_temp("last_damage_from")) )
        {
                message("system",  HIM "\n【天杀令】姬良(Ji Liang)：" + ob->query("name") + "你这" + RANK_D->query_rude(ob) + "，我受到了天神的特别保护，你居然敢对我放肆，去死吧！\n"NOR,users() );
                ob->move("/d/wizard/jianyu");
        }
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        return;
}

