// yuanshuai.c
// Created by dongsw for zhtx2 2002.8

inherit NPC;
inherit __DIR__"paths.c";

#include <ansi.h>

#define KILLER_DIR "/quest/killer/killer/"
#define KILLER_NPC_DIR "/quest/killer/"

void reward(object me);
void continue_reward(object me);

void create()
{
  set_name("兵马大元帅", ({ "yuan shuai", "shuai" }));
  set("title", HIY"朝廷大臣"NOR);
  set("long", "掌管天下兵马的元帅。\n");
  set("gender", "男性");
  set("age", 40);
  setup();
}

void init ()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_task", "task");
        add_action("do_finish", "finish");
        add_action("do_drop", "drop");
        add_action("do_cancel", "cancel");
}

void greeting(object ob)
{
        object me = this_object();
        object obj;
        
        if (present("ren zhi",environment(ob)))
        obj = present("ren zhi",environment(ob));
        else return;
        
        if (ob->query("cttask/var") == "救人"
                && obj->query("owner_player") == ob)
        {
                message_vision(CYN"$N说道：多谢这位壮士送我回朝，咱们后会有期，再见！\n"NOR,obj);
                ob->set("cttask/end_time", time());
                ob->delete("cttask/get");
                ob->set("cttask/done", 1);
                destruct(obj);
        }
        else return;
}

int accept_object(object who, object ob)
{
        //放弃job要点钱
        if (ob->query("money_id"))
        {
             if(!who->query("cttask/fail") || ( ob->value() < 50000))
             {
             tell_object(who,CYN"兵马大元帅说道：多谢支援国家建设！\n"NOR);
                   return 1;
             }
             else
             {
                   message_vision(CYN"兵马大元帅说到：罚金你已经交纳可以继续为朝廷效力了。\n"NOR, who);
                   who->delete("cttask/fail");
        who->delete("cttask/get");
        who->delete("cttask/job_start");
        who->delete("cttask/finishtime");
                   return 1;
             }
         }
        return 0;
}

int do_task()
{
        int lv, tt;
        string var, position, position2, lev, *killers, arg;
        object killer, killer2, me = this_player(), obj;
        mapping misc;
        
        if( (tt =(int)me->query("cttask/job_start")) && !me->query("cttask/get")
            && tt <= time() && time() < tt + 360)
                return notify_fail("兵马大元帅说道：时下天下太平，国泰民安，没有什么事情可做。\n");

        message_vision(CYN"$N说到：请问元帅大人，最近乾坤教活动如何？是否有杀手为害民间？\n"NOR,me);

        if( me->query("cttask/get") )
                return notify_fail(CYN"\n兵马大元帅说道：我不是已经告诉你任务了么？快去解决。\n"NOR);

        if( me->query("cttask/fail") )
                return notify_fail(CYN"\n兵马大元帅生气的说道：你浪费了机会，我现在还不信任你，你等等在来吧！\n"NOR);

        if( me->query("combat_exp") < 8000000 )
                return notify_fail(CYN"\n兵马大元帅说道：你武学经验太少，无法满足朝廷的需要。\n"NOR);

        killers = get_dir(KILLER_DIR + "*.c");
        killer = new( KILLER_DIR + killers[ random( sizeof(killers) ) ] );
        
        misc = miscs[random(sizeof(miscs))];
        lv = misc["lv"];
        lev = misc["lev"];
        killer->set("title",misc["title"]);

        position = killer->invocation(me, lv);

          switch (random(7))
        {
          case 0 : var = "灭口";
                   arg = CYN"\n兵马大元帅说道：现打听到" + position + "中藏匿，此人残杀无辜，嗜血成性，\n你快去除掉他，以为民除害。\n"NOR;
                   break;
          case 1 : var = "活捉";
                   arg = CYN"\n兵马大元帅说道：现打听到" + position + "中藏匿，此人皇上要亲自审问，\n你快去把他擒来，记住只要活的不要死的。\n"NOR;
                   break;
          case 2 : var = "废武";
                   arg = CYN"\n兵马大元帅说道：现打听到" + position + "中藏匿，此人是个小角色，\n你把他的武功废了，他就不能作恶了。\n"NOR;
                   break;
          case 3 : var = "规劝";
                   arg = CYN"\n兵马大元帅说道：现打听到" + position + "中藏匿，此人本性善良，\n但就是好面子，你去劝劝他，让他弃恶从善吧。\n"NOR;
                   break;
          case 4 : var="战胜";
                   arg = CYN"\n兵马大元帅说道：现打听到" + position + "中藏匿，此人初入魔道，不过内心还未变坏，\n你去教训他一顿让他知道朝廷的厉害，他也就不敢从恶了。\n"NOR;
                   break;
          case 5 : var = "救人";          
                   arg = CYN"\n兵马大元帅说道：我朝一名重要官员被绑架了，希望你能把他救回，\n现打听到" + position + "中藏匿，切记保护官员的生命安全。\n"NOR;
                   obj = new( KILLER_NPC_DIR + "renzhi");
                   obj->move(environment(killer));
                   obj->set_leader(killer);
                   obj->set("owner", killer);
                   obj->set("owner_player", me);
                   obj->set_hp();
                   killer->set_leader(obj);
                   killer->set("renzhi", obj);
                   break;
          case 6 : var = "劝架";
                   arg = CYN"\n兵马大元帅说道：现打听到" + position + "中追杀一名乾坤教叛徒，\n你去帮助一下他，记住不要有人员伤亡。\n"NOR;
                   killer2 = new( KILLER_NPC_DIR + "shashou" );
                   killer2->set("var", var);
                   killer2->set("owner", me);
                   killer2->set("lv",lv);
                   killer2->set("fighter",killer);
                   killer2->set_hp();
                   killer2->move(environment(killer));
                   killer2->set_leader(killer);
                   killer->set_leader(killer2);
                   killer->set("fighter",killer2);
                   break;
          case 7 : var = "歼群";
                   arg = HIR"\n兵马大元帅说道：现有一项危险的任务要你去完成，现打听到" + position + "中出没，消灭他们一行人。\n这里有一包消魂香，希望你见机行事。\n"NOR;
                   break;
        }
        tell_object(me, arg);

        killer->set("var", var);
        killer->set("owner", me);
        killer->set("lv", lv);
        me->set("cttask/get", 1);
        me->set("cttask/lv", lv);
        me->set("cttask/var", var);
        me->set("cttask/lev", lev);
        me->delete("cttask/job_start");
        me->set("cttask/killer", killer);
        me->set("cttask/position", position);
        me->set("cttask/start_time", time());
        me->set("cttask/job_start", time());
        CHANNEL_D->do_channel(this_object(), "sys", "[玩家] " + me->name() + "  [难度] " + lev + "  [种类] " + var);
        return 1;
}

int do_cancel()
{
        int tt;
        object me = this_player();

        if (!me->query("cttask/get"))
        {
                tell_object(me,"你没有接到过任务。\n");
                return 1;
        }
        
        if ( ( tt = (int)me->query("cttask/job_start")))
        {
                if( tt <= time() && time() < tt + 360)
                {
                        message_vision("$N说道：身为朝廷命官怎可轻言放弃？快去做来！\n",this_object(), me);
                        return 1;
                }
        }
        
        message_vision(CYN"$N说到：这个任务属下不能完成，请大人降罪。\n"NOR, me);
        message_vision(CYN"\n兵马大元帅说道：好吧，那我在去找别的人去做吧，你自己好好反省一下。\n"NOR, me);
        
        me->set("cttask/fail", 1);
        me->delete("cttask/get");
        me->delete("cttask/job_start");
        me->delete("cttask/finishtime");

        return 1;
}

int do_finish()
{
        object me = this_player();
        int tt;

        if( !me->query("cttask") )
        {
                message_vision(CYN"\n兵马大元帅说道：你没领过任务要什么奖励？\n"NOR, me);
                return 1;
        }

        if (!me->query("cttask/done"))
        {
                tell_object(me, "你还没有完成我交给你的任务，快去完成！\n");
                return 1;
        }

        message_vision(CYN"\n兵马大元帅说道：$N做的不错，听赏。\n"NOR, me);

        reward(me);
        return 1;
}

void reward(object me)
{
        int exp, lv, var_b, lv_b, faith, ct_faith;
        int extra_b, pot_b, exp_b, tac_exp_b;
        string str, var, lev;
        int wlsw = 0;
        exp = me->query("combat_exp");
        lv = me->query("cttask/lv");
        var  = me->query("cttask/var");
        lev = me->query("cttask/lev");

        if ( lv == 1 ) lv_b = 300;
        else if ( lv == 2 ) lv_b = 600;
        else lv_b = 1000;

        if      ( var == "灭口" ) var_b = 300;
        else if ( var == "废武" ) var_b = 500;
        else if ( var == "活捉" ) var_b = 600;
        else if ( var == "规劝" ) var_b = 700;
        else if ( var == "战胜" ) var_b = 800;
        else if ( var == "救人" ) var_b = 1000;
        else if ( var == "劝架" ) var_b = 1000;
        else var_b = 1200;

        extra_b = ( me->query("combat_exp") / 2500) + var_b;

        if( extra_b > 5000) extra_b = 5000;

        pot_b = (random(extra_b)/5 + 1000 + lv_b + var_b-500);
        exp_b = (extra_b*6 + (random(lv_b) + random(var_b))*3)/4 + random(2000)-3000;

        if ( exp_b > 10000 ) exp_b =10000;
        if ( pot_b < 1000  ) pot_b = 1000;

        tac_exp_b = exp_b / 10;
        faith = exp_b / 200 + random(10);
        ct_faith = exp_b / 200 + random(10);

        me->add("combat_exp", exp_b);
        str  = "\n你被奖励了：" + exp_b + " 点武学经验、";
        me->add("tactic_exp", tac_exp_b);
        str += tac_exp_b + " 点政治经验、";
        me->add("potential", pot_b);
        str += pot_b + " 点潜能、";
        me->add("faith", faith);
        str += faith + " 点师门忠诚度、";
        me->add("ct_faith", ct_faith);
        str += ct_faith + " 点朝廷忠诚度。\n";

        //message("channel:chat", HIY + "\n【官府通告】" + me->query("name") + 
        //        "完成了一个" + lev + "级别的任务，为本朝做出了贡献，特此表彰！\n"+NOR,users());
        tell_object(me, WHT + str + NOR);
        
        me->delete("cttask/done", 1);
        me->delete("cttask/get", 1);
        me->delete("cttask/job_start");
        
        log_file("cttask", sprintf("时间：[%s] ID：%s、奖励：%d点经验、%d点潜能\n", ctime(time()), me->query("id"), exp_b,pot_b));
        
        continue_reward(me);
}

void continue_reward(object me)
{
        int gold, t, r;
        string str;
        object obj;
        int wlsw=0;
        gold = 5 + random(5);
        t = me->query("cttask/finishtime");
        if (!t) t = 0;
        t = t + 1;


        if ( t == 1 )
        {
                message_vision(WHT"这是您完成的第一个任务，请继续努力！\n"NOR, me);
                me->set("cttask/finishtime", t);
                return;
        }
        else message_vision(WHT"这是您连续完成的第" + chinese_number(t) + "个任务，请继续努力！\n"NOR, me);

        if ( t > 1 )
        {
                str = HIY"由于您连续完成任务，朝廷特别嘉奖您" + chinese_number(gold) + "两黄金";
                MONEY_D->pay_player(me, gold * 10000);
        }

        if ( t > 9 && random(me->query("kar")) > 9 )
        {
                obj = new("/d/moyu/obj/nineflower");
                str += "，" + obj->name() + "一颗";
                obj->move(me);
                me->set_temp("cttask/gift2", 1);
        }
     if(t>19 && random(me->query("kar"))>15 && me->query("wlshw") < 500)
     {      wlsw = 1+random(2);
         me->add("wlshw",wlsw);
      str += ", " + wlsw + "点武林声望";
       me->set_temp("cttask/gift2",1);
     }
        else if (!me->query_temp("cttask/gift2")) str += "";
        else str += "。\n";

        if ( t%20 == 0 )
        {
                r = random(2);
                if ( r == 0 )
                obj = new("/class/fighter/dragon_armor");
                else if ( r == 1 )
                obj = new ("/class/scholar/windspring");
                str += "，" + obj->name() + HIY"一件";
                obj->move(me);
                me->set_temp("cttask/gift3",1);
        }
        else if ( me->query_temp("cttask/gift2") == 1 ) str += "";
        else str += "。\n";

        if ( t%50 == 0 )
        {
                r = random(6);
                if ( r == 0 )
                obj = new("/d/latemoon/obj/bracelet");
                else if ( r == 1 )
                obj = new ("/d/xanadu/treasure/casket");
                else if ( r == 2 )
                obj = new ("/d/xueshan/npc/obj/xsword");
                else if ( r == 3 )
                obj = new ("/d/xueshan/npc/obj/xblade");
                else if ( r == 4 )
                obj = new ("/d/shaolin/obj/puti-zi");
                else if ( r == 5 )
                obj = new ("/d/xueshan/npc/obj/xglove");
                str += "，" + obj->query("name") + HIY"一件。\n";
                obj->move(me);
        }
        else if ( t > 9 && (me->query_temp("cttask/gift2") || me->query_temp("cttask/gift3")))
        str += "。\n";

        if (str)
        tell_object(me,HIY + str + NOR);
        me->set("cttask/finishtime", t);
        me->delete_temp("cttask/gift2");
        me->delete_temp("cttask/gift3");
}

int do_drop(string arg)
{
        object me = this_player();
        object obj;

        if( !arg ) return 0;

        if( !objectp(obj = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");

        if ( me->query("cttask/var") != "活捉" || obj->is_corpse())
        {               
                write(CYN"兵马大元帅对你说道：这是什么东西？\n"NOR);
                return 1;
        }
        
        if( obj != me->query("cttask/killer") )
        {
                write(CYN"兵马大元帅对你说道：你将此人擒来作甚？\n"NOR);
                return 1;
        }
        call_out ("accomplish", 1, me, obj);
        return 0;
}

void accomplish(object me, object obj)
{
        object ob = this_object();
        if( !living(obj) )
        {
                message_vision(CYN"$N说到：这位壮士辛苦了，你干的不错。\n"HIR"来人啊！\n"NOR, ob);
                call_out ("accomplish_b", 1, me, obj, ob);
        }
        else return;
}

void accomplish_b(object me, object obj, object ob)
{
        message_vision(HIR"\n士兵：到！\n"NOR, me);
        message_vision(HIR"士兵：到！\n\n"NOR, me);
        call_out ("accomplish_c", 1, me, obj, ob);
}

void accomplish_c(object me, object obj, object ob)
{
        message_vision(CYN"$N说道：给我把此人压下去，好好看管！\n\n"NOR, ob);
        message_vision(HIG"$N被两名士兵押进了地牢。\n\n"NOR, obj);
        destruct (obj);
        me->set("cttask/end_time", time());
        me->delete("cttask/get");
        me->set("cttask/done", 1);
}



