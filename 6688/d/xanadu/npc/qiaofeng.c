#include <ansi.h>

inherit ZONGSHI_NPC;

void create()
{
        set_name("乔峰", ({"qiao feng", "qiao", "feng"}));

        set("title",HIG"正派 " + HIW"武林宗师" NOR);
        set("gender", "男性");
        set("age", 35);
        set("per", 30);
        set("long", 
                "他就是和“南慕容”相齐名的“北乔峰”，果然是威风凛凛，\n"
                "他正在传授正义之士一些基本武功。");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: command, "haha" :),
                CYN"乔峰说道：“哈哈哈，痛快痛快，等我吃饱喝足进去杀个痛快！”。\n"NOR,
                CYN"乔峰说道：“怎么还没有人来行侠仗义，那些伪君子们都哪里去了！”。\n"NOR,
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
        set("shen",1000000);
         
        set_basic_skill(this_object());
        
        setup();
        carry_object("/obj/cloth/leather.c")->wear();
}

int accept_object(object who, object ob)
{
        int t;
          if ((t = ob->query("research")) && !who->query("宗师"))
        {
                if(t == 300 && ob->query("owner") == who)
                {
                        if( who->query("shen") >= 0)
                        {
                                message_vision("$n给了$N一把" + ob->name() + NOR"。\n", this_object(),who);
                                command("nod");
                                message_vision(CYN"$N对$n说道：你为武林除此大害，功劳真是不小啊！\n"NOR, this_object(),who);
                                who->set("lfy_winner",1);
                                who->set("宗师","乔峰");
                                destruct(present("jtl key",who));
                                message("channel:chat", 
                                HIC + "【闲聊】" + name() + HIC"(" + capitalize(query("id")) +
                                ")：" + who->name() + "杀死魔头，行侠仗义，如今本座指点他一些基本武功作为奖励，希望其再接再厉，为中原武林争光添彩。\n"+NOR,users());
                                command("pat " + who->query("id"));
                                return 1;
                        }
                        else
                        {
                                write(CYN"乔峰说道：“旁门邪派也想来偷学武功？快滚，想都别想！”。\n"NOR);
                                write(CYN"乔峰说道：“钥匙没收了作为惩罚！你如果能弃恶从善，在教你不迟！”。\n"NOR);
                                return 1;
                        }
                        
                                
                }
        }
        return 0;
}

