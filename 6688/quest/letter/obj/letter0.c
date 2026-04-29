// letter0.c
// Create by dongsw@zhtx2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("挑战书", ({"tiaozhan shu", "letter"}));
        set("unit", "封");
        set("weight", 5);
        set("no_put", 1);
        set("no_drop", 1);
        set("no_get", 1);
        call_out("set_long", 1, this_object());
        setup();
}

void set_long(object ob)
{
        set("long",
               "这是一封" + ob->query("name") + "。\n\n信封上面写着：\n"
               "收信人：" + ob->query("rname") + "\n"NOR
               "地  区：" + ob->query("letter_r_npc_part") + "\n"
               "地  点：" + ob->query("letter_r_npc_room") + "\n\n"NOR);
}

void init()
{
        add_action("give_letter", "giveto");
}

int give_letter(string arg)
{
        //定义变量
        object ob = this_object(), me = this_player();
        string target, str, fname, rname;
        int exp, pot, per, faith, ctfaith;
        
        per = me->query("per");
        
        if (!arg || !ob = present(arg, environment(me)) )
                return notify_fail("您要送什么给谁？\n");

        target = ob->query("name");
        fname = present("letter", me)->query("fname");
        rname = me->query("rname");

        //验证npc名字
        if ( target != rname )
                return notify_fail( rname + "的挑战书，我可不要！\n");

        //任务npc名字可能相同
        if (userp(ob)) return notify_fail("你送错人了吧？\n");

        //规定时限
        if ( (int) me->query("l_task_time") < time() )
                return notify_fail(target+"说道：你怎么这么晚才来，这个东西过时了！我可不要。”\n");
        
        tell_object(me,"你给了" + target + "一封挑战书。\n" NOR );

        //定义奖励
        exp = 350 + random(250);
        faith = 1 + random(4);
        ctfaith = random(2);
        pot = 60 + random(50);

        str  = target + "将一封薄薄的挑战书拆开，只见上面龙飞凤舞写着几行字：\n";
        str += "        #####################################\n";
        str += "        "+ target +"阁下：\n\n";
        str += "                  今晚子时，月圆之夜。\n";
        str += "                  紫禁之巅，恭候大驾！\n\n";
        str += "                          一剑西来："+ fname +"\n";
        str += "        #####################################\n\n";
        me->start_more(str);

        tell_object(me,CYN + target + CYN"不屑的说到：" + fname + CYN"这等小儿，如此不知天高地厚，我一定要去教训他一番！\n\n" + 
                HIW"您的任务完成了，得到了"
        + chinese_number(exp)     + "点经验值。"
        + chinese_number(pot)     + "点潜能。"
        + chinese_number(faith)   + "点师门忠诚度。"
        + chinese_number(ctfaith) + "点朝廷忠诚度。\n\n"NOR);
          
        if ((int)ob->query("shen_type") < 0)
        {
                if (random( per - 10 ) > 5)
                {
                        tell_object(me,CYN + target + CYN"阴险的说到：你这" + RANK_D->query_rude(me) + 
                                                "一定是" + fname + CYN"派来的奸细，受死吧！\n"NOR);
                        ob->kill_ob(me);
                }
                else tell_object(me, CYN + target + CYN"阴险的说到：你这"+ RANK_D->query_rude(me) +"你是不是"
                                 + fname + CYN"派来偷窥我的奸细？快给我滚！\n"NOR);
        }
        
        me->add("combat_exp", exp);
        me->delete("rname");
        me->add("potential", pot);
        me->set("letter_quest", 0);
        me->add("faith", faith);
        me->add("ct_faith", ctfaith);
        me->delete("letter");
        me->delete("l_task_time");
        destruct(present("letter", me));
        return 1;
}

//玩家死后处理，信件销毁
void owner_is_killed() { destruct(this_object()); }


