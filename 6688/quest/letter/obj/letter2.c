// letter2.c
// Create by dongsw@zhtx2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("家书", ({"home letter", "letter"}));
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
        int exp, pot, gold, faith, ctfaith;

        if ( !arg || !ob = present(arg, environment(me)) )
                return notify_fail("您要送什么给谁？\n");

        target = REPLACE_D->ansi_remove(ob->query("name"));
        fname = present("letter", me)->query("fname");
        rname = REPLACE_D->ansi_remove(me->query("rname"));

        //验证npc名字
        if ( target != rname )
                return notify_fail( rname + "的家书，我可不要！\n");
        
        //任务npc名字可能相同
        if (userp(ob)) return notify_fail("你送错人了吧？\n");
        
        //规定时限
        if ( (int) me->query("l_task_time") < time() )
                return notify_fail(target+"说道：你怎么这么晚才来，这个东西过时了！我可不要。”\n");
 
        tell_object(me,"你给了" + target + "一封家书。\n" NOR );

        //定义奖励
        gold = 1 + random(2);
        exp = 200 + random(200);
        faith = 1 + random(4);
        ctfaith = random(2);
        pot = 50 + random(20);

        str  = target+ "激动的将这封家书打开，几行熟悉的小字浮现在" + target + "眼前：\n";
        str += "        #####################################\n";
        str += "        亲爱的"+ target +"：\n\n";
        str += "                  最近身体可好？我们都很想念你。\n";
        str += "                  不要太想家，我们都在这祝福你。\n\n";
        str += "                          家人："+ fname +"\n";
        str += "        #####################################\n\n";
        me->start_more(str);
        
        tell_object(me, CYN + target + CYN"激动的说到：多谢这位" + RANK_D->query_respect(me) + "为在下带来家书，在下感激不尽。\n");
        tell_object(me, CYN + target + CYN"说到：这里有黄金" + chinese_number(gold) + "两，请您收下。\n\n"+ HIW"您被奖励了"
        + chinese_number(exp)     + "点经验值。"
        + chinese_number(pot)     + "点潜能。"
        + chinese_number(faith)   + "点师门忠诚度。"
        + chinese_number(ctfaith) + "点朝廷忠诚度。\n\n"NOR);

        MONEY_D->pay_player(this_player(), gold * 10000);

        me->add("combat_exp", exp);
        me->add("potential", pot);
        me->set("letter_quest", 0);
        me->delete("letter");
        me->delete("rname");
        me->add("faith", faith);
        me->add("ct_faith", ctfaith);
        me->delete("l_task_time");
        destruct(present("letter", me));
        return 1;
}

//玩家死后处理，信件销毁
void owner_is_killed() { destruct(this_object()); }



