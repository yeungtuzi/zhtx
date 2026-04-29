#include <ansi.h>

inherit ZONGSHI_NPC;

void create()
{
        set_name("欧阳峰", ({"ouyang feng", "feng"}));

        set("title",HIB"邪派 " + HIW"武林宗师" NOR);
        set("gender", "男性");
        set("age", 50);
        set("per", 10);
        set("long", 
                "白驼山庄的庄主，西毒欧阳峰就是他了，出了名的阴险毒辣，\n"
                "他正在传授邪恶之徒一些基本武功。");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: command, "grin" :),
                CYN"欧阳峰说道：“嘿嘿，我这个计策不错，如此这般...，九阴真经必定归我所有！哈哈！”。\n"NOR,
        }));
        set("inquiry",([
                        "武功":(:view_skills:),
                       ]));
        set("kee", 5000);
        set("max_kee", 5000);
        set("gin", 3000);
        set("max_gin", 3000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("atman", 3000);
        set("max_atman",3000);
        set("force", 10000);
        set("max_force", 5000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 300);
        set("combat_exp",5000000);
        set("score", 200000);
        set("shen",-1000000);
         
        set_basic_skill(this_object());
        
        setup();
        carry_object("/obj/weapon/gangzhang.c")->wield();
        carry_object("/obj/cloth/fur_coat.c")->wear();
}

int accept_object(object who, object ob)
{
        int t;
          if ((t = ob->query("research")) && !who->query("宗师"))
        {
                if(t == 300 && ob->query("owner") == who)
                {
                        if( who->query("shen") < 0)
                        {
                                message_vision("$n给了$N一把" + ob->name() + NOR"。\n", this_object(),who);
                                command("nod");
                                message_vision(CYN"$N对$n说道：好小子！干的不错。\n"NOR, this_object(),who);
                                who->set("lfy_winner",1);
                                who->set("宗师","欧阳峰");
                                destruct(present("jtl key",who));
                                message("channel:chat", 
                                HIC + "【闲聊】" + name() + HIC"(" + capitalize(query("id")) +
                                ")：所谓的侠义之士们小心了，等" + who->name() + "练好了武功，取你们的狗命！\n"+NOR,users());
                                command("grin " + who->query("id"));
                                return 1;
                        }
                        else
                        {
                                write(CYN"欧阳峰说道：“你是哪里跑来卧低的？！”。\n"NOR);
                                write(CYN"欧阳峰说道：“钥匙留下，人快滚，要不然小心你人头落地！”。\n"NOR);
                                return 1;
                        }
                        
                                
                }
        }
        return 0;
}

