///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit NPC;

nosave string * charlist=({"一","二","三","四","五","六","七","八","九","十","百","千","万",
                                                                "亿","我","们","热","爱","纵","横","天","下","泥","巴",
                                                                "赵","钱","孙","李","周","吴","郑","王","冯","陈","诸","卫","蒋","沈","韩",
                                                                "杨","朱","秦","尤","许","何","吕","施","张","孔","曹","严","华","金","魏",
                                                                "陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚",
                                                                "范","彭","郎","鲁","韦","昌","马","苗","凤","花","方","俞","任","袁","柳",
                                                                "酆","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤","滕","殷","罗",
                                                                "毕","郝","邬","安","常","乐","于","时","傅","皮","卡","齐","康","姚","邵",
                                                                "伍","余","元","卜","顾","孟","平","黄","和","穆","萧","尹","堪","汪",});

// npc will carry too many object if allow keep obj,see give.c
int no_keep(object ob) {
        return(1);
}

void do_xizining(object me,string str);

void create()
{
        object ob;
        set_name("张子鹤", ({ "teacher","zhang"}) );
        set("gender", "男性" );
        set("age", 46);
        set("long","这是一位面色憔悴的中年书生，看上去温和而又不失威严。\n");
        set("combat_exp", 20000);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("literate", 60);
        set_skill("parry", 20);
        set("chat_chance",2);
        set("chat_msg", ({
                "张子鹤说道：人之初，性本善。性相近，习相远。\n",
                "张子鹤说道：苟不教，性乃迁。教之道，贵以专。\n",
                "张子鹤说道：昔孟母，择邻处。子不学，断机杼。\n",
                "张子鹤说道：窦燕山，有义方，教五子，名俱扬。\n",
                "张子鹤说道：养不教，父之过；教不严，师之惰。\n",
        }));

        carry_object("/obj/cloth")->wear();
        setup();

}

void init()
{
        object ob;

        ::init();
        add_action("do_xizi", "xizi");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int do_xizi()
{
        int progress;string str;
        object me = this_player();
        if(me->query("combat_exp")>=12000) return notify_fail(CYN"张子鹤说：我只负责教授尚不会习字的幼童。\n"
                                        "这位" + RANK_D->query_respect(me)+"可以到村西口的小溪边钓鱼，也许会对你有用\n"NOR);
         if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
         if(me->query("sen")<11)
          return notify_fail("你的精神不能集中,习字可不是那么容易的事。\n");
        progress=me->query("mark/xizi");
        if (progress<0) progress=0;
        if (progress>sizeof(charlist)) progress=sizeof(charlist);
        str=charlist[progress];
        message_vision("张子鹤向$N示范了几遍“"HIW+str+NOR"”字的写法。\n"
        "张子鹤轻轻的拍了拍$N的头，说道：你开始练习这个字吧。\n",me);
        message_vision(HIY"$N开始认真的练习写“"HIW+str+HIY"”字........。\n"NOR,me);
        me->add("sen",-5);
        me->start_busy(10);
    call_out("do_xizining",6,me,str);
    return 1;
}

void do_xizining(object me,string str)
{
        int i=random(99)+me->query("xiziinc");
        me->interrupt_me(me,"death");
        if(i>85) {
                tell_object(me,MAG"你眼中灵光一闪，迅速在纸上工工整整的写下了“"HIW+str+NOR+MAG"”字！\n"
                        "张子鹤过来凑近一看，满意的说道：嗯，这个字你算是学会了。\n"NOR);
                me->add("combat_exp",100);
                me->add("potential",40);
                message_vision(HIM"$N学会了“"HIW+str+NOR+HIM"”字！\n"NOR,me);
                tell_object(me,"你的经验、潜能和读书识字水平有所增长。\n");
                me->improve_skill("literate", (int)me->query("int"));
                me->add("mark/xizi",1);
                me->delete("xiziinc");
        }
        else if(i>60){
                tell_object(me,CYN"你歪头想了一会，在纸上歪歪扭扭的写下了一个“"HIW+str+NOR+CYN"”字。\n"
                        "张子鹤过来凑近一看，摇了摇头，说道：这个字你还得继续练习。\n"NOR);
                me->add("xiziinc",10);
        }
        else if(i>30){
                        tell_object(me,"你歪头想了一会，在纸上歪歪扭扭的写下了一个“"HIW+str+NOR"”字。\n"
                                "张子鹤过来凑近一看，面有怒色，说道：笔划错了！\n");
                        me->add("xiziinc",5);
        }
        else{
                tell_object(me,HIB"你只觉得一片茫然，对老师刚才教的字毫无印象！\n"
                        "张子鹤过来凑近一看，摇了摇头，叹了口气：孺子不可教也。\n"NOR);
        }
}

void greeting(object ob)
{
                int exp;
        if( !ob || environment(ob) != environment() ) return;
        exp=ob->query("combat_exp");
        if(exp<12000) {
                        message_vision(CYN"张子鹤轻轻的拍了拍$N的头，说道：这位" + RANK_D->query_respect(ob)+"是来习字的吧?\n"
                                "在这儿习字(xizi)是不需要交钱的。\n"NOR,ob);
                        tell_object(ob,YEL"张子鹤对你说道：在这儿习字还可以增加经验和潜能哦！\n"NOR
                        YEL"张云财说：如果有了提高，用(hp)命令就可以看到你增加的经验和潜能了。\n"NOR);
                }
                else {
        message_vision(CYN"张子鹤淡淡的看了$N一眼，说道：这位" + RANK_D->query_respect(ob)+"有何贵干啊?\n"
                        "张子鹤说：我只负责教授尚不会习字的幼童。\n"NOR,ob);
                tell_object(ob,YEL"张子鹤对你说道：想继续学习读书识字的话要收取少量学资。\n"NOR);
                ob->delete("mark/xizi");
                }
}

int recognize_apprentice(object ob)
{
        if (ob->query("family/family_name")=="朝廷")
                return 1;
        if (!(int)ob->query_temp("mark/张"))  return 0;
        return 1;
}

int accept_learn(object me, string skill)
{
        if (skill=="literate")
        {
                if (me->query("family/family_name")=="朝廷")
                        return 1;
                if (!(int)me->query_temp("mark/张"))
                        return 0;
                me->add_temp("mark/张", -1);
                return 1;
        }

        return 0;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/张"))
                who->set_temp("mark/张", 0);
        if (ob->query("money_id") && ob->value() >= 100) {
                message_vision("张子鹤同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/张", ob->value() / 5);
                return 1;
        }
        return 0;
}
